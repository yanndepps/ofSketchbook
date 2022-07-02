/*
** © Aalto Project
** Sketch_001
** Template
** Recoded
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  scale = 1.0;
  save = false;
  fileName = "framework";

  width = scale * ofGetWidth();
  height = scale * ofGetHeight();
  centre = glm::vec2((ofGetWidth() * scale) / 2, (ofGetHeight() * scale) / 2);

  ofEnableSmoothing();
  ofEnableAntiAliasing();
  ofEnableAlphaBlending();

  ofSetCircleResolution(100 * scale);

  fbo.allocate(width, height, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
  fbo.begin();
  // draw code here
  fbo.end();

  fbo.draw(0, 0, ofGetWidth(), ofGetHeight());

  if (save) {
    ofPixels pix;
    fbo.readToPixels(pix);
    ofSaveImage(pix, fileName + ofToString(ofGetFrameNum()) + ".png", OF_IMAGE_QUALITY_BEST);
  }
}

//--------------------------------------------------------------
int main()
{

  ofSetupOpenGL(512, 512, OF_WINDOW);
  ofRunApp(new ofApp());
}

//--------------------------------------------------------------
