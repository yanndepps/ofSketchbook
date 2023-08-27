// Coding Maths
// © BIT-101
// Sketch_003 -> More Trigonometry
// Recoded 2023.08.27

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetFrameRate(30);
  ofSetWindowTitle("openFrameworks");
  ofBackground(239);
  ofSetColor(0);
  //---
  speed = 0.1; // 0.1
  angle = 0;
  //---
}

//--------------------------------------------------------------
void ofApp::update()
{
  centerY = ofGetHeight() * 0.5;
  centerX = ofGetWidth() * 0.5;
  offset = ofGetHeight() * 0.2; // 0.4
  //---
  // cout << "offset value -> " << offset << endl;
}

//--------------------------------------------------------------
void ofApp::render()
{
  float y = centerY + sin(angle) * offset;
  ofDrawCircle(centerX, y, 50);
  angle += speed;
}

//--------------------------------------------------------------
void ofApp::draw()
{
  render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
  switch (key) {
  case 'f':
  case 'F':
    ofToggleFullscreen();
    break;
  default:
    break;
  }
}

//--------------------------------------------------------------
int main()
{

  ofSetupOpenGL(720, 720, OF_WINDOW);
  ofRunApp(new ofApp());
}
