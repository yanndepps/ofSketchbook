/*
 * tbos_002
 * ch02 -> Hello World
 */

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  // load and compile the shader
  shader.load("", "shader.frag");

  // large print export
  int value;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &value);
  float total = 8.3 + 8.3;
  w = (8.3 / total) * (value - 1);
  h = (8.3 / total) * (value - 1);
  largeOffscreenImage.allocate(w, h, GL_RGBA);
  // ---
  ofSetWindowTitle("tbos_002");
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  largeOffscreenImage.begin();

  // replace the pipeline with our shader
  shader.begin();

  // send uniforms
  shader.setUniform1f("u_time", ofGetElapsedTimef());
  shader.setUniform2f("u_mouse", mouseX, mouseY);
  shader.setUniform2f("u_resolution", w, h);

  // make a billboard
  ofDrawRectangle(0, 0, w, h);

  // default shader pipeline
  shader.end();

  largeOffscreenImage.end();
  // large print draw
  ofRectangle bounds(0, 0, ofGetWidth(), ofGetHeight());
  ofRectangle target(0, 0, w, h);
  target.scaleTo(bounds);

  largeOffscreenImage.draw(target);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  // reload everytime you press a key
  if (key == 's' || key == 'S') {
    shader.load("", "shader.frag");
  }

  // large print export
  if (key == ' ') {
    ofPixels p;
    largeOffscreenImage.readToPixels(p);
    ofSaveImage(p, ofGetTimestampString() + ".png");
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
  ofSetupOpenGL(620, 620, OF_WINDOW);
  ofRunApp(new ofApp());
}
