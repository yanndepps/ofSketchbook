/*
** © JunKiyoshi
** Recoded & Edited
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetFrameRate(60);
  ofSetWindowTitle("openframeworks");

  // ofBackground(239);
  // ofBackgroundHex(0xf6f6f4); // chromotome -> spatial01
  ofBackgroundHex(0xfff8e7); // chromotome -> rohlfs_1R
  ofSetLineWidth(2);
  ofSetCircleResolution(30);

  ofEnableSmoothing();
  ofEnableAntiAliasing();

  ofColor color;
  // vector<int> hex_list = {0xef476f, 0xffd166, 0x06d6a0, 0x118ab2, 0x073b4c}; // original colors
  // vector<int> hex_list = {0xff5937, 0xf6f6f4, 0x4169ff}; // chromotome -> spatial01
  vector<int> hex_list = {0x004996, 0x567bae, 0xff4c48, 0xffbcb3}; // chromotome -> rohlfs_1R
  for (auto hex : hex_list) {
    color.setHex(hex);
    this->base_color_list.push_back(color);
  }

  float span = 120;
  for (float x = span * 0.5; x < ofGetWidth(); x += span) {
    for (float y = span * 0.5; y < ofGetHeight(); y += span) {
      this->location_list.push_back(glm::vec2(x, y));
      this->deg_list.push_back(ofRandom(360));
      this->param_list.push_back((int)ofRandom(90) * 4);
      this->color_list.push_back(this->base_color_list[(int)ofRandom(this->base_color_list.size())]);
    }
  }

  // ---
  scale = 1.0;
  save = false;
  fileName = "./output/frame";
  width = scale * ofGetWidth();
  height = scale * ofGetHeight();
  fbo.allocate(width, height, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
  fbo.begin();
  ofClear(0);
  // ---
  int radius = 38;
  for (int i = 0; i < this->location_list.size(); i++) {
    this->param_list[i] = (this->param_list[i] + 4) % 360;

    if (this->param_list[i] == 0) {
      this->deg_list[i] = ofRandom(360);
      this->color_list[i] = this->base_color_list[(int)ofRandom(this->base_color_list.size())];
    }

    vector<glm::vec2> vertices;
    if (this->param_list[i] > 0 && this->param_list[i] < 180) {
      for (int deg = 0; deg < this->param_list[i]; deg += 1) {
	vertices.push_back(glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
      }

      for (int deg = 360 - this->param_list[i]; deg < 360; deg += 1) {
	vertices.push_back(glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
      }
    }

    if (this->param_list[i] >= 180 && this->param_list[i] < 360) {
      auto tmp_param = this->param_list[i] - 180;
      for (int deg = tmp_param; deg < 180; deg += 1) {
	vertices.push_back(glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
      }

      for (int deg = 180; deg < 360 - tmp_param; deg += 1) {
	vertices.push_back(glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
      }
    }

    ofPushMatrix();
    ofTranslate(this->location_list[i]);
    ofRotate(this->deg_list[i]);

    ofFill();
    ofSetColor(this->color_list[i]);
    ofBeginShape();
    ofVertices(vertices);
    ofEndShape(true);

    ofNoFill();
    // ofSetColor(39);
    // ofSetColor(239);
    // ofSetHexColor(0xff5937); // chromotome -> spatial01
    ofSetHexColor(0x004996); // chromotome -> rohlfs_1R
    ofDrawCircle(glm::vec2(), 43);

    ofPopMatrix();
  }
  // ---
  fbo.end();
  fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
  // ---
  if (save) {
    ofPixels pix;
    fbo.readToPixels(pix);
    ofSaveImage(pix, fileName + "_" + ofToString(ofGetFrameNum()) + ".png", OF_IMAGE_QUALITY_BEST);
  }
  // ---
  // if (ofGetFrameNum() == 360) {
  //   ofLog() << "done rendering !";
  //   ofExit();
  // }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
  if (key == 's') {
    save = !save;
  }
}

//--------------------------------------------------------------
int main()
{
  ofSetupOpenGL(720, 720, OF_WINDOW);
  ofRunApp(new ofApp());
}
