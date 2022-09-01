/*
** © Aalto Project
** Sketch_015
** BezierBlob
** Recoded
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  scale = 1.0;
  save = false;
  fileName = "output/frame_";

  width = scale * ofGetWidth();
  height = scale * ofGetHeight();
  centre = glm::vec2((ofGetWidth() * scale) / 2.0, (ofGetHeight() * scale) / 2.0);

  ofEnableSmoothing();
  ofEnableAntiAliasing();
  ofEnableAlphaBlending();

  ofSetCircleResolution(100 * scale);
  ofBackground(0);

  fbo.allocate(width, height, GL_RGBA);

  ofSeedRandom(1);

  controlPoints.resize(3 + 1);

  for (int i = 0; i < controlPoints.size(); ++i) {
    controlPoints[i] = glm::vec3(ofRandom(200 * scale, width - 200 * scale), ofRandom(200 * scale, height - 200 * scale), 0.0);
  }

  points = evalBezier(controlPoints, 1000);
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
  // ---
  for (int i = 0; i < points.size(); i++) {
    float r = 255 * sin(ofDegToRad(i + ofGetFrameNum()));
    float g = 255 * sin(ofDegToRad(i + 100 * sin(ofDegToRad(ofGetFrameNum()))));
    float b = 255 * sin(ofDegToRad(i + 45 * sin(ofDegToRad(ofGetFrameNum()))));

    ofSetColor(r, g, b);

    float x = centre.x + (i / 1.0) * cos(ofDegToRad(i)) * ofNoise(ofGetFrameNum() / 100.0) * scale;
    float y = centre.y + (i / 1.0) * sin(ofDegToRad(i)) * ofNoise(ofGetFrameNum() / 1000.0) * scale;

    ofDrawCircle(points[i], 100 * scale + 50 * cos(ofDegToRad(i + ofGetFrameNum() / 1.0)) * scale);
    // ofDrawCircle(x, y, 100 * scale + 50 * cos(ofDegToRad(i + ofGetFrameNum() / 1.0)) * scale);
  }
  // ---
  fbo.end();
  fbo.draw(0, 0, ofGetWidth(), ofGetHeight());

  if (save && ofGetFrameNum() < 3601) {
    ofPixels pix;
    fbo.readToPixels(pix);
    ofSaveImage(pix, fileName + ofToString(ofGetFrameNum()) + ".png", OF_IMAGE_QUALITY_BEST);
  }

  if (ofGetFrameNum() == 3601) {
    ofExit();
  }
}

//--------------------------------------------------------------
int main()
{
  ofSetupOpenGL(640, 640, OF_WINDOW);
  ofRunApp(new ofApp());
}
