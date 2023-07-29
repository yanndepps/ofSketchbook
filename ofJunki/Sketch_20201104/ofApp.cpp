/*
** © JunKiyoshi
** Recoded & Edited
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetFrameRate(30);
  ofSetWindowTitle("invisible sphere");
  // ofBackgroundHex(0xFFFFFF); // Black over White
  // ofBackgroundHex(0x000000); // White over Black
  // ofBackgroundHex(0x1C2D1D); // Pigment_01
  // ofBackgroundHex(0xD8F50B); // Pigment_02
  // ofBackgroundHex(0xDE1C57); // Pigment_03
  ofBackgroundHex(0xD83B3B); // Pigment_04

  ofEnableDepthTest();
  ofEnableSmoothing();
  ofEnableAntiAliasing();

  this->frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);

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
  ofSeedRandom(39);

  this->face.clear();
  this->frame.clear();

  int radius = 160 * scale; // 250
  float phi_deg_step = 10;
  float theta_deg_step = 3;

  for (float theta_deg = theta_deg_step; theta_deg < 180; theta_deg += theta_deg_step * 2) {
    int phi_deg_start = ofGetFrameNum() * 5 + theta_deg * 2;
    for (float phi_deg = phi_deg_start; phi_deg < phi_deg_start + 150; phi_deg += phi_deg_step) {
      auto index = this->face.getNumVertices();
      vector<glm::vec3> vertices;

      vertices.push_back(glm::vec3(
          radius * sin((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD) * cos((phi_deg + phi_deg_step * 0.5) * DEG_TO_RAD),
          radius * sin((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD) * sin((phi_deg + phi_deg_step * 0.5) * DEG_TO_RAD),
          radius * cos((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD)));
      vertices.push_back(glm::vec3(
          radius * sin((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD) * cos((phi_deg - phi_deg_step * 0.5) * DEG_TO_RAD),
          radius * sin((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD) * sin((phi_deg - phi_deg_step * 0.5) * DEG_TO_RAD),
          radius * cos((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD)));
      vertices.push_back(glm::vec3(
          radius * sin((theta_deg + theta_deg_step * 0.5) * DEG_TO_RAD) * cos((phi_deg + phi_deg_step * 0.5) * DEG_TO_RAD),
          radius * sin((theta_deg + theta_deg_step * 0.5) * DEG_TO_RAD) * sin((phi_deg + phi_deg_step * 0.5) * DEG_TO_RAD),
          radius * cos((theta_deg + theta_deg_step * 0.5) * DEG_TO_RAD)));
      vertices.push_back(glm::vec3(
          radius * sin((theta_deg + theta_deg_step * 0.5) * DEG_TO_RAD) * cos((phi_deg - phi_deg_step * 0.5) * DEG_TO_RAD),
          radius * sin((theta_deg + theta_deg_step * 0.5) * DEG_TO_RAD) * sin((phi_deg - phi_deg_step * 0.5) * DEG_TO_RAD),
          radius * cos((theta_deg + theta_deg_step * 0.5) * DEG_TO_RAD)));

      this->face.addVertices(vertices);
      this->frame.addVertices(vertices);

      this->face.addIndex(index + 0);
      this->face.addIndex(index + 1);
      this->face.addIndex(index + 3);
      this->face.addIndex(index + 0);
      this->face.addIndex(index + 3);
      this->face.addIndex(index + 2);

      this->frame.addIndex(index + 0);
      this->frame.addIndex(index + 1);
      this->frame.addIndex(index + 3);
      this->frame.addIndex(index + 2);
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  fbo.begin();
  ofClear(0);
  // ---
  this->cam.begin();
  ofRotateX(270);
  ofRotateZ(ofGetFrameNum() * 0.5);

  // ofSetHexColor(0x000000); // Black over White
  // ofSetHexColor(0xFFFFFF); // White over Black
  // ofSetHexColor(0x8EE12A); // Pigment_01
  // ofSetHexColor(0xF24D77); // Pigment_02
  // ofSetHexColor(0xFAD10B); // Pigment_03
  ofSetHexColor(0x292E34); // Pigment_04

  this->face.draw();

  // ofSetHexColor(0xFFFFFF); // Black over White
  // ofSetHexColor(0x000000); // White over Black
  // ofSetHexColor(0x1C2D1D); // Pigment_01
  // ofSetHexColor(0xD8F50B); // Pigment_02
  // ofSetHexColor(0xDE1C57); // Pigment_03
  ofSetHexColor(0xD83B3B); // Pigment_04

  this->frame.draw();

  ofDrawSphere(120 * scale);

  this->cam.end();
  // ---
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
int main()
{
  ofSetupOpenGL(720, 720, OF_WINDOW);
  ofRunApp(new ofApp());
}
