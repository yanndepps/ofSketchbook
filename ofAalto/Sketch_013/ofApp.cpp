/*
** © Aalto Project
** Sketch_013
** PolySpiral
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

  // ofSetCircleResolution(150 * scale);
  ofSetCircleResolution(200);

  ofBackground(0);

  fbo.allocate(width, height, GL_RGBA);

  ofSeedRandom(15);

  int it = 1;

  controlPoints.resize(3 * it + 1);

  for (int i = 0; i < controlPoints.size(); ++i) {
    controlPoints[i] = glm::vec3(ofRandom(200 * scale, width - 200 * scale),
                                 ofRandom(200 * scale, height - 200 * scale),
                                 0.0);
  }

  points = evalCR(controlPoints, 500);
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

  for (int i = 0; i < points.size(); i++) {
    float r = 127 + 127 * sin(ofDegToRad(i / 2.0 + ofGetFrameNum()));
    float g = 127 + 127 * sin(ofDegToRad(i / 2.0 + 10 * sin(ofDegToRad(ofGetFrameNum()))));
    float b = 192 + 64 * sin(ofDegToRad(i / 3.0 + 45 * sin(ofDegToRad(ofGetFrameNum()))));

    ofPushMatrix();
    ofSetColor(r, 255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    auto l = (60 + (45 * sin(ofDegToRad(i + ofGetFrameNum())))) * scale;
    ofTranslate(points[i]);
    ofRotate(i / float(10));
    ofDrawRectangle(0, 0, l, l);
    ofSetColor(255 - r, 255);
    for (int j = 45; j < 360 + 45; j += 90) {
      auto len = (60 + (45 * sin(ofDegToRad(i + ofGetFrameNum())))) * scale;
      ofDrawRectangle(l * cos(ofDegToRad(j)), l * sin(ofDegToRad(j)), len, len);
    }
    ofPopMatrix();
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

  ofSetupOpenGL(640, 640, OF_WINDOW);
  ofRunApp(new ofApp());
}

//--------------------------------------------------------------
