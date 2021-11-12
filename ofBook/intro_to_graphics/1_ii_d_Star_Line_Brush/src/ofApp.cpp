// --- Star Line Brush --- //
// Working with a Linear Map

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(60);
  ofEnableAlphaBlending();
  ofSetBackgroundAuto(false);
  ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  // lseft mouse button
  if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
    int numLines = 30;
    int minRadius = 25;
    int maxRadius = 125;
    for (int i = 0; i < numLines; i++) {
      float angle = ofRandom(ofDegToRad(360.0));
      float distance = ofRandom(minRadius, maxRadius);
      float xOffset = cos(angle) * distance;
      float yOffset = sin(angle) * distance;
      // make shorter lines more opaque
      float alpha = ofMap(distance, minRadius, maxRadius, 50, 0);
      ofSetColor(255, alpha);

      ofSetLineWidth(ofRandom(1.0, 5.0));
      ofDrawLine(ofGetMouseX(), ofGetMouseY(), ofGetMouseX() + xOffset,
		 ofGetMouseY() + yOffset);
    }
  }
  // right mouse button
  if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {
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
