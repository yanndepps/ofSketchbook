/*
 * Glowing Circles Brush
 * Using Transparency & Color
 */

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
  // left mouse
  if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
    // increase for a wider brush
    int maxRadius = 50;
    // decrease for more circles (i.e. a more opaque brush)
    int radiusStepSize = 5;
    // increase for a more opaque brush
    int alpha = 3;
    // increase for a larger spread of circles
    int maxOffsetDistance = 100;

    for (int radius = maxRadius; radius > 0; radius -= radiusStepSize) {
      float angle = ofRandom(ofDegToRad(360.0));
      float distance = ofRandom(maxOffsetDistance);
      float xOffset = cos(angle) * distance;
      float yOffset = sin(angle) * distance;

      // randomly select a color between orange and red
      ofColor myOrange(255, 132, 0, alpha);
      ofColor myRed(255, 6, 0, alpha);
      ofColor inBetween = myOrange.getLerped(myRed, ofRandom(1.0));
      ofSetColor(inBetween);

      ofDrawCircle(ofGetMouseX() + xOffset, ofGetMouseY() + yOffset, radius);
    }
  }

  // right mouse
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
