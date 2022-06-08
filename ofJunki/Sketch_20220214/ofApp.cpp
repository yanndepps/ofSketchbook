/*
** © JunKiyoshi
** Recoded & Edited
*/

#include "ofApp.h"

//--------------------------------------------------------------
Actor::Actor(vector<glm::vec3>& location_list, vector<vector<int>>& next_index_list, vector<int>& destination_list)
{
  this->select_index = ofRandom(location_list.size());
  while (true) {
    auto itr = find(destination_list.begin(), destination_list.end(), this->select_index);
    if (itr == destination_list.end()) {
      destination_list.push_back(this->select_index);
      break;
    }
    this->select_index = (this->select_index + 1) % location_list.size();
  }
  this->next_index = this->select_index;
  this->noise_seed = ofRandom(1000);
}

//--------------------------------------------------------------
void Actor::update(const int& frame_span, vector<glm::vec3>& location_list, vector<vector<int>>& next_index_list, vector<int>& destination_list)
{
  if (ofGetFrameNum() % frame_span == 0) {
    auto tmp_index = this->select_index;
    this->select_index = this->next_index;
    int retry = next_index_list[this->select_index].size();
    this->next_index = next_index_list[this->select_index][(int)ofRandom(next_index_list[this->select_index].size())];
    while (--retry > 0) {
      auto destination_itr = find(destination_list.begin(), destination_list.end(), this->next_index);
      if (destination_itr == destination_list.end()) {
	if (tmp_index != this->next_index) {
	  destination_list.push_back(this->next_index);
	  break;
	}
      }
      this->next_index = next_index_list[this->select_index][(this->next_index + 1) % next_index_list[this->select_index].size()];
    }
    if (retry <= 0) {
      destination_list.push_back(this->select_index);
      this->next_index = this->select_index;
    }
  }
  auto param = ofGetFrameNum() % frame_span;
  auto distance = location_list[this->next_index] - location_list[this->select_index];
  if (this->next_index != this->select_index) {
    this->prev_location = this->location;
  }
  this->location = location_list[this->select_index] + distance / frame_span * param;
  this->log.push_front(this->location);
  while (this->log.size() > 20) {
    this->log.pop_back();
  }
}

//--------------------------------------------------------------
glm::vec3 Actor::getLocation()
{
  return this->location;
}

//--------------------------------------------------------------
glm::vec3 Actor::getPrevLocation()
{
  return this->prev_location;
}

//--------------------------------------------------------------
deque<glm::vec3> Actor::getLog()
{
  return this->log;
}

//--------------------------------------------------------------
void Actor::setColor(ofColor color)
{
  this->color = color;
}

//--------------------------------------------------------------
ofColor Actor::getColor()
{
  return this->color;
}

//--------------------------------------------------------------
float Actor::getNoiseSeed()
{
  return this->noise_seed;
}

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetFrameRate(60);
  ofSetWindowTitle("happy valentine day");
  ofBackground(255);
  ofSetLineWidth(2);

  auto span = 40;
  for (int x = -280; x <= 280; x += span) {
    for (int y = -280; y <= 280; y += span) {
      this->location_list.push_back(glm::vec3(x, y, 0));
    }
  }
  auto param = span;
  for (auto& location : this->location_list) {
    vector<int> next_index = vector<int>();
    int index = -1;
    for (auto& other : this->location_list) {
      index++;
      if (location == other) {
	continue;
      }
      float distance = glm::distance(location, other);
      if (distance <= param) {
	next_index.push_back(index);
      }
    }
    this->next_index_list.push_back(next_index);
  }
  ofColor color;
  // vector<int> hex_list = {0xef476f, 0xffd166, 0x06d6a0, 0x118ab2, 0x073b4c};
  vector<int> hex_list = {0xd53939, 0xb6754d, 0xa88d5f, 0x524643, 0x3c5a53, 0x7d8c7c, 0xdad6cd};
  vector<ofColor> base_color_list;
  for (auto hex : hex_list) {
    color.setHex(hex);
    base_color_list.push_back(color);
  }
  for (int i = 0; i < 180; i++) {
    this->actor_list.push_back(make_unique<Actor>(this->location_list, this->next_index_list, this->destination_list));
    this->actor_list.back()->setColor(base_color_list[(int)ofRandom(base_color_list.size())]);
  }

  // ---
  toScale = 1.0;
  save = false;
  fileName = "./output/frame";
  width = toScale * ofGetWidth();
  height = toScale * ofGetHeight();
  fbo.allocate(width, height, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update()
{
  int frame_span = 10;
  int prev_index_size = 0;
  if (ofGetFrameNum() % frame_span == 0) {
    prev_index_size = this->destination_list.size();
  }
  for (auto& actor : this->actor_list) {
    actor->update(frame_span, this->location_list, this->next_index_list, this->destination_list);
  }
  if (prev_index_size != 0) {
    this->destination_list.erase(this->destination_list.begin(), this->destination_list.begin() + prev_index_size);
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  fbo.begin();
  ofClear(0);
  // ---
  ofTranslate(ofGetWindowSize() * 0.5);
  for (auto& actor : this->actor_list) {
    ofPushMatrix();

    ofTranslate(actor->getLocation());

    float scale = 1.1;

    ofFill();
    ofSetColor(actor->getColor());
    ofBeginShape();
    for (auto deg = 0; deg < 360; deg += 1) {
      ofVertex(this->make_point(deg * DEG_TO_RAD) * scale);
    }
    ofEndShape(true);

    ofNoFill();
    ofSetColor(39);
    ofBeginShape();
    for (auto deg = 0; deg < 360; deg += 1) {
      ofVertex(this->make_point(deg * DEG_TO_RAD) * scale);
    }

    ofEndShape(true);
    ofPopMatrix();
  }
  fbo.end();
  fbo.draw(0, 0, ofGetWidth(), ofGetHeight());

  // ---
  if (save) {
    ofPixels pix;
    fbo.readToPixels(pix);
    ofSaveImage(pix, fileName + "_" + ofToString(ofGetFrameNum()) + ".png", OF_IMAGE_QUALITY_BEST);
  }

  if (ofGetFrameNum() == 360) {
    ofLog() << "done rendering !";
    ofExit();
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
  if (key == 's') {
    save = !save;
  }
}

//--------------------------------------------------------------
// Reference by https://twitter.com/shiffman/status/1095764239665512453
glm::vec2 ofApp::make_point(float theta)
{
  float x = 16 * (pow(sin(theta), 3));
  float y = 13 * cos(theta) - 5 * cos(2 * theta) - 2 * cos(3 * theta) - cos(4 * theta);
  return glm::vec2(x, -y);
}
//--------------------------------------------------------------
int main()
{
  ofSetupOpenGL(720, 720, OF_WINDOW);
  ofRunApp(new ofApp());
}
