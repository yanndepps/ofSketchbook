// Domestika -> Immersive Art
// Sketch_004 -> Particle System Part II
// Recoded -> 2023.08.03

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  gui.setup();
  gui.add(overallSpeed.setup("speed", 1, 0, 3));
  gui.add(noiseAmount.setup("noise", 1, 0, 3));
  gui.add(trail.setup("trail", 6.0, 0, 20));

  ofSetFrameRate(30);
  ofSetWindowTitle("openFrameworks");
  ofBackground(33);
  ofSetColor(249);

  p.assign(100, particle());
  for (int i = 0; i < p.size(); i++) {
    p[i].setup();
  }

  ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update()
{
  for (int i = 0; i < p.size(); i++) {
    p[i].update(overallSpeed, noiseAmount);
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  ofSetColor(0, 0, 0, trail);
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  ofSetColor(255, 255, 255, 255);

  for (int i = 0; i < p.size(); i++) {
    p[i].draw(1);
  }

  gui.draw();
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
