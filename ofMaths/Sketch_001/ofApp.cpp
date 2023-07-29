// Coding Maths
// © BIT-101
// Sketch_001 -> Intro
// Recoded 2023.07.29

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetFrameRate(5);
  ofSetWindowTitle("openFrameworks");

  ofBackground(239);
  // ofSetColor(0);

  minInc = 0;
  maxInc = 10;
}

//--------------------------------------------------------------
void ofApp::update()
{
  // while (minInc < maxInc) {
  //   myLine.addVertex(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
  //   minInc++;
  // }
  // ---
  for (minInc; minInc < maxInc; minInc++) {
    myLine.addVertex(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  ofColor myColor;
  myColor.setHsb(100, 100, 100, 80);
  ofSetColor(myColor);
  ofSetLineWidth(2);
  myLine.draw();
}

//--------------------------------------------------------------
int main()
{

  ofSetupOpenGL(720, 720, OF_WINDOW);
  ofRunApp(new ofApp());
}
