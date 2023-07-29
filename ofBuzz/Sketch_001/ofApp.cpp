// Drawing Generative Lines
// © Dan Buzzo
// Recoded 2023.07.29

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetFrameRate(5);
  ofSetWindowTitle("openFrameworks");
  ofBackground(239);
}

//--------------------------------------------------------------
void ofApp::update()
{
  myLine.addVertex(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
}

//--------------------------------------------------------------
void ofApp::draw()
{
  ofColor myColor;
  myColor.setHsb(255, 255, 255, 80);
  ofSetColor(myColor);
  ofSetLineWidth(3);

  // for (int i = 0; i < 100; i++) {
  //   ofDrawLine(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
  // }

  myLine.draw();
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

  // Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
  ofGLWindowSettings settings;
  settings.setSize(740, 740);
  settings.windowMode = OF_WINDOW; // can also be OF_FULLSCREEN

  auto window = ofCreateWindow(settings);

  ofRunApp(window, make_shared<ofApp>());
  ofRunMainLoop();
}
