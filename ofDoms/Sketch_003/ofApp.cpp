// Domestika -> Immersive Art
// Sketch_003 -> Arrays & Classes
// Recoded -> 2023.08.03

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

  ofSetFrameRate(30);
  ofSetWindowTitle("openFrameworks");
  ofBackground(33);
  ofSetColor(249);

  for (int i = 0; i < 200; i++) {
    fastBall[i].setup(ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight())), ofVec2f(ofRandom(-2, 2) * 5, ofRandom(-2, 2) * 5), ofRandom(5, 25));
  }
}

//--------------------------------------------------------------
void ofApp::update()
{
  for (int i = 0; i < 200; i++) {
    fastBall[i].update();
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  for (int i = 0; i < 200; i++) {
    fastBall[i].draw();
  }
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
  ofSetupOpenGL(720, 720, OF_WINDOW);
  ofRunApp(new ofApp());
}
