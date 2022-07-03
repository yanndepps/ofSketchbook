/*
** © Aalto Project
** Sketch_011
** Shape_Blob
** Recoded
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  scale = 2.0;
  save = false;
  fileName = "output/frame_";

  width = scale * ofGetWidth();
  height = scale * ofGetHeight();
  centre = glm::vec2((ofGetWidth() * scale) / 2.0, (ofGetHeight() * scale) / 2.0);

  ofEnableSmoothing();
  ofEnableAntiAliasing();
  ofEnableAlphaBlending();

  ofSetCircleResolution(100 * scale);
  // ofSetCircleResolution(200);

  ofBackground(0);

  fbo.allocate(width, height, GL_RGBA);

  ofSeedRandom(3);

  controlPoints.resize(3 + 1);

  for (int i = 0; i < controlPoints.size(); ++i) {
    controlPoints[i] = glm::vec3(ofRandom(50 * scale, width - 50 * scale),
                                 ofRandom(50 * scale, height - 50 * scale),
                                 0.0);
  }

  points = evalBezier(controlPoints, 1120);
}

//--------------------------------------------------------------
void ofApp::update()
{
  ofSetWindowTitle(ofToString(ofGetFrameNum()));
}

//--------------------------------------------------------------
void ofApp::draw()
{
  fbo.begin();
  ofClear(0, 0);
  int sFrame = 429;

  for (int i = 0; i < points.size(); i++) {
    float r = 255 * sin(ofDegToRad(i + 100 * sin(ofDegToRad(sFrame))));
    float g = 128 * sin(ofDegToRad(i + sFrame));
    float b = 255 * sin(ofDegToRad(i + 45 * sin(ofDegToRad(sFrame))));

    ofSetColor(r, g, b);

    ofDrawCircle(points[i], 50 * scale + 25 * cos(ofDegToRad((i + sFrame + ofGetFrameNum()) / 1.0)) * scale);
  }

  fbo.end();

  fbo.draw(0, 0, ofGetWidth(), ofGetHeight());

  if (save && ofGetFrameNum() < 3601) {
    ofPixels pix;
    fbo.readToPixels(pix);
    ofSaveImage(pix, fileName + ofToString(ofGetFrameNum()) + ".png", OF_IMAGE_QUALITY_BEST);
  }

  if (ofGetFrameNum() == 3601)
    ofExit();
}

//--------------------------------------------------------------
int main()
{

  ofSetupOpenGL(512, 512, OF_WINDOW);
  ofRunApp(new ofApp());
}

//--------------------------------------------------------------
