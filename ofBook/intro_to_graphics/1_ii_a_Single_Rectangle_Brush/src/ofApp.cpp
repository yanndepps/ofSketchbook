/*
 * ShapeBrush
 */

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  // stop the background from being redrawn each frame
  ofSetBackgroundAuto(false);
  // still draw a background before using the brush
  ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  // if left mouse button is pressed ...
  if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
    // randomness
    float randomColor = ofRandom(50, 255);
    ofSetColor(randomColor);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), 20, 20);
  }
  // if right mouse button is pressed
  if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {
    // erase the screen with a black background
    ofBackground(0);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == 's') {
    ofSaveScreen("savedScreenshot_" +  ofGetTimestampString() + ".png");
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
