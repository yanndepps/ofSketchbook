// Domestika -> Immersive Art
// Sketch_002 -> Loops
// Recoded -> 2023.08.01

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetFrameRate(30);
  ofSetWindowTitle("openFrameworks");
  ofBackground(33);
  ofSetColor(249);

  int factor = 5;
  pos.x = ofRandom(0, ofGetWidth());
  pos.y = ofRandom(0, ofGetHeight());
  vel.x = ofRandom(-1, 1) * factor;
  vel.y = ofRandom(-1, 1) * factor;
}

//--------------------------------------------------------------
void ofApp::update()
{
  pos += vel;
  if ((pos.x > ofGetWidth()) || (pos.x < 0)) {
    vel.x *= -1;
  }
  if ((pos.y > ofGetHeight()) || (pos.y < 0)) {
    vel.y *= -1;
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  ofDrawCircle(pos.x, pos.y, ofGetHeight() * 0.025);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}

//--------------------------------------------------------------
int main()
{
  ofSetupOpenGL(360, 360, OF_WINDOW);
  ofRunApp(new ofApp());
}
