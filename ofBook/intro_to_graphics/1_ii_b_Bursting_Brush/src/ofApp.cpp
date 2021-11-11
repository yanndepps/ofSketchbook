/*
 * Bursting Rectangles
 */

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(60);
  ofSetBackgroundAuto(false);
  ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
    ofSetRectMode(OF_RECTMODE_CENTER);
    int numRects = 10;
    for (int r = 0; r < numRects; r++) {
      ofSetColor(ofRandom(50, 255));
      float width = ofRandom(1, 5);
      float height = ofRandom(1, 5);
      float distance = ofRandom(35);

      // formula for converting from polar to Cartesian coordinates :
      // x = cos(polar angle) * (polar distance)
      // y = sin(polar angle) * (polar distance)
      // need angle to be in radians in order to use sin() & cos()
      // make use of the OF function ofDegToRad()
      float angle = ofRandom(ofDegToRad(360.0));
      float xOffset = cos(angle) * distance;
      float yOffset = sin(angle) * distance;
      ofDrawRectangle(ofGetMouseX() + xOffset, ofGetMouseY() + yOffset, width,
                      height);
    }
  }

  // if right mouse pressed
  if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {
    // erase the screen with a black background
    ofBackground(0);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == 's') {
    ofSaveScreen("screenshot_" + ofGetTimestampString() + ".png");
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}

//--------------------------------------------------------------
int main() {
  ofSetupOpenGL(600, 600, OF_WINDOW);
  ofRunApp(new ofApp());
}
