// Coding Maths
// © BIT-101
// Sketch_002 -> Intro to Trigonometry
// Recoded 2023.07.29

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetFrameRate(30);
  ofSetWindowTitle("openFrameworks");
  ofBackground(239);
  ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
  ofTranslate(0, ofGetHeight() * 0.5);
  ofScale(1, -1);

  for (float angle = 0; angle < PI * 2; angle += 0.01) {
    // cout << sin(angle);
    int x = angle * 200;
    int y = sin(angle) * 200;
    ofDrawRectangle(x, y, 5, 5);
  }
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
