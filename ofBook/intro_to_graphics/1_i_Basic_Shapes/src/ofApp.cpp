#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  ofBackground(0); // clear the screen with a black color
  ofSetColor(255); // set the drawing color to white

  ofFill(); // if we omit this and leave ofNoFill(), all the shapes will be
            // outlines
  ofSetLineWidth(2); // line width is a default value of 1 if we don't modify it

  // draw some shapes
  ofDrawRectangle(50, 50, 100,
                  100); // 100 wide x 100 high, top left corner at ( 50, 50 )
  ofDrawCircle(250, 100, 50); // radius of 50, centered at ( 250, 100 )
  ofDrawEllipse(400, 100, 80,
                100); // 80 wide x 100 high, centered at ( 400, 100 )
  ofDrawTriangle(500, 150, 550, 50, 600,
                 150); // three corners: ( 500,150 ), ( 550,50 ), ( 600,150 )
  ofDrawLine(700, 50, 700, 150);

  for (int i = 0; i < 11; i++) {
    ofDrawLine(650, 50 + (i * 10), 750, 75 + (i * 5));
  }

  ofNoFill();
  ofSetLineWidth(4.5);

  // shapes ( shifted down 150 pixels )
  ofDrawRectangle(50, 200, 100, 100);
  ofDrawCircle(250, 250, 50);
  ofDrawEllipse(400, 250, 80, 100);
  ofDrawTriangle(500, 300, 550, 200, 600, 300);
  ofDrawLine(700, 200, 700, 300);

  for (int i = 0; i < 11; i++) {
    ofDrawLine(650, 200 + (i * 10), 750, 225 + (i * 5));
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

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
  ofSetupOpenGL(800, 350, OF_WINDOW);
  ofRunApp(new ofApp());
}
