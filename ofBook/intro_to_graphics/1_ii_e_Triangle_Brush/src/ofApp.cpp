// --- Triangle Brush --- //
// Vectors & Rotations

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetWindowTitle("Triangle Brush");
  ofSetFrameRate(60);
  ofEnableAlphaBlending();
  ofSetBackgroundAuto(false);
  ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  // left mouse button
  if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
    int numTriangles = 10;
    int minOffset = 5;
    int maxOffset = 70;
    int alpha = 150;

    for (int t = 0; t < numTriangles; ++t) {
      float offsetDistance = ofRandom(minOffset, maxOffset);
      ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

      // define a triangle at the origin ( 0, 0 ) that points to the right
      ofVec2f p1(0, 6.25);
      ofVec2f p2(25, 0);
      ofVec2f p3(0, -6.25);
      // the rotate() function uses degrees
      float rotation = ofRandom(360.0);
      p1.rotate(rotation);
      p2.rotate(rotation);
      p3.rotate(rotation);

      ofVec2f triangleOffset(offsetDistance, 0.0);
      triangleOffset.rotate(rotation);

      p1 += mousePos + triangleOffset;
      p2 += mousePos + triangleOffset;
      p3 += mousePos + triangleOffset;

      ofColor aqua(0, 255, 255, alpha);
      ofColor purple(198, 0, 205, alpha);
      ofColor inbetween = aqua.getLerped(purple, ofRandom(1.0));
      ofSetColor(inbetween);

      ofDrawTriangle(p1, p2, p3);
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
