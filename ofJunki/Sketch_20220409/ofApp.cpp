/*
** © JunKiyoshi -> https://www.youtube.com/shorts/VcpcKUQsFSw
** Recoded
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofBackgroundHex(0xfcce09);
  this->cam.setDistance(500);

  scale = 1.0;
  save = false;
  fileName = "./output/waveheart";

  width = scale * ofGetWidth();
  height = scale * ofGetHeight();

  ofEnableSmoothing();
  ofEnableAntiAliasing();
  // ofEnableAlphaBlending();
  // ofSetBackgroundAuto(false);

  // ---
  ofSetFrameRate(30);
  ofSetWindowTitle("wavering heart");
  ofEnableDepthTest();

  this->frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);

  fbo.allocate(width, height, GL_RGBA);
  // fbo.begin();
  // ofClear(0);
  // fbo.end();
}

//--------------------------------------------------------------
void ofApp::update()
{
  ofSeedRandom(78);

  this->face.clear();
  this->frame.clear();

  for (float scale = 3; scale < 15; scale += 1) {
    auto start_index = this->face.getNumVertices();

    for (int deg = 0; deg < 360; deg += 1) {
      vector<glm::vec3> vertices;
      vertices.push_back(glm::vec3(this->make_point(deg * DEG_TO_RAD) * scale, -15));
      vertices.push_back(glm::vec3(this->make_point(deg * DEG_TO_RAD) * (scale + 0.5), -15));
      vertices.push_back(glm::vec3(this->make_point((deg + 1) * DEG_TO_RAD) * (scale + 0.5), -15));
      vertices.push_back(glm::vec3(this->make_point((deg + 1) * DEG_TO_RAD) * scale, -15));

      vertices.push_back(glm::vec3(this->make_point(deg * DEG_TO_RAD) * scale, 15));
      vertices.push_back(glm::vec3(this->make_point(deg * DEG_TO_RAD) * (scale + 0.5), 15));
      vertices.push_back(glm::vec3(this->make_point((deg + 1) * DEG_TO_RAD) * (scale + 0.5), 15));
      vertices.push_back(glm::vec3(this->make_point((deg + 1) * DEG_TO_RAD) * scale, 15));

      for (auto& vertex : vertices) {
	auto angle = ofMap(ofNoise(scale * 0.025, vertex.y * 0.001 + ofGetFrameNum() * 0.01), 0, 1, -PI * 2, PI * 2);
	auto rotation = glm::rotate(glm::mat4(), angle, glm::vec3(0, 1, 0));
	vertex = glm::vec4(vertex, 0) * rotation;
      }
      auto index = this->face.getNumVertices();
      this->face.addVertices(vertices);
      this->frame.addVertices(vertices);

      this->face.addIndex(index + 0);
      this->face.addIndex(index + 1);
      this->face.addIndex(index + 2);
      this->face.addIndex(index + 0);
      this->face.addIndex(index + 2);
      this->face.addIndex(index + 3);
      this->face.addIndex(index + 4);
      this->face.addIndex(index + 5);
      this->face.addIndex(index + 6);
      this->face.addIndex(index + 4);
      this->face.addIndex(index + 6);
      this->face.addIndex(index + 7);
      this->face.addIndex(index + 0);
      this->face.addIndex(index + 4);
      this->face.addIndex(index + 1);
      this->face.addIndex(index + 4);
      this->face.addIndex(index + 5);
      this->face.addIndex(index + 1);
      this->face.addIndex(index + 1);
      this->face.addIndex(index + 5);
      this->face.addIndex(index + 6);
      this->face.addIndex(index + 6);
      this->face.addIndex(index + 2);
      this->face.addIndex(index + 1);
      this->face.addIndex(index + 2);
      this->face.addIndex(index + 6);
      this->face.addIndex(index + 7);
      this->face.addIndex(index + 7);
      this->face.addIndex(index + 3);
      this->face.addIndex(index + 2);
      this->face.addIndex(index + 3);
      this->face.addIndex(index + 7);
      this->face.addIndex(index + 4);
      this->face.addIndex(index + 4);
      this->face.addIndex(index + 0);
      this->face.addIndex(index + 3);

      this->frame.addIndex(index + 0);
      this->frame.addIndex(index + 3);
      this->frame.addIndex(index + 1);
      this->frame.addIndex(index + 2);
      this->frame.addIndex(index + 4);
      this->frame.addIndex(index + 7);
      this->frame.addIndex(index + 5);
      this->frame.addIndex(index + 6);
    }

    if (this->face.getNumVertices() != start_index) {
      this->frame.addIndex(start_index + 0);
      this->frame.addIndex(start_index + 4);
      this->frame.addIndex(start_index + 0);
      this->frame.addIndex(start_index + 1);
      this->frame.addIndex(start_index + 5);
      this->frame.addIndex(start_index + 1);
      this->frame.addIndex(start_index + 5);
      this->frame.addIndex(start_index + 4);

      this->frame.addIndex(this->face.getNumVertices() - 1);
      this->frame.addIndex(this->face.getNumVertices() - 2);
      this->frame.addIndex(this->face.getNumVertices() - 1);
      this->frame.addIndex(this->face.getNumVertices() - 5);
      this->frame.addIndex(this->face.getNumVertices() - 6);
      this->frame.addIndex(this->face.getNumVertices() - 2);
      this->frame.addIndex(this->face.getNumVertices() - 6);
      this->frame.addIndex(this->face.getNumVertices() - 5);
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  fbo.begin();
  ofClear(0);

  this->cam.begin();

  ofRotateXDeg(180);
  ofRotateYDeg(ofGetFrameNum() * 0.5);

  ofSetHexColor(0x408ac9);
  this->face.draw();

  ofSetHexColor(0xfcce09);
  this->frame.drawWireframe();

  this->cam.end();

  fbo.end();
  fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
  if (save) {
    ofPixels pix;
    fbo.readToPixels(pix);
    ofSaveImage(pix, fileName + "_" + ofToString(ofGetFrameNum()) + ".png", OF_IMAGE_QUALITY_BEST);
  }
}
//--------------------------------------------------------------
glm::vec2 ofApp::make_point(float theta)
{
  float x = 16 * (pow(sin(theta), 3));
  float y = 13 * cos(theta) - 5 * cos(2 * theta) - 2 * cos(3 * theta) - cos(4 * theta);
  return glm::vec2(x, -y);
}
//--------------------------------------------------------------
int main()
{
  ofSetupOpenGL(512, 512, OF_WINDOW);
  ofRunApp(new ofApp());
}
