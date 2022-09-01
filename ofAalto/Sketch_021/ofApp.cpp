/*
** © Aalto Project
** Sketch_021
** ikVareOnBW
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

  ofSetCircleResolution(150 * scale);
  ofBackground(0);

  fbo.allocate(width, height, GL_RGBA);

  ofSeedRandom(1232147);

  int it = 1;

  controlPoints.resize(3 * it + 1);
  newControls.resize(3 * it + 1);

  for (int i = 0; i < controlPoints.size(); ++i) {
    controlPoints[i] = glm::vec3(ofRandom(200 * scale, width - 200 * scale), ofRandom(200 * scale, height - 200 * scale), 0.0);
  }

  ofSeedRandom(78);

  for (int i = 0; i < newControls.size(); ++i) {
    newControls[i] = glm::vec3(ofRandom(200 * scale, width - 200 * scale), ofRandom(200 * scale, height - 200 * scale), 0.0);
  }

  otherPoints = evalCR(newControls, 500);
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
  // ---
  for (int i = 0; i < points.size(); i++) {
    float r = 127 + 127 * sin(ofDegToRad(i / 2.0 + ofGetFrameNum()));
    float g = 127 + 127 * sin(ofDegToRad(i / 2.0 + 10 * sin(ofDegToRad(ofGetFrameNum()))));
    float b = 192 + 64 * sin(ofDegToRad(i / 3.0 + 45 * sin(ofDegToRad(ofGetFrameNum()))));
    // TODO
    float bForGrey = 191 + 64 * sin(ofDegToRad(i + ofGetFrameNum()));
    float hue = 245;
    float saturation = 127 * sin(ofDegToRad(i));
    float brightness = 255;

    ofSetColor(ofColor::fromHsb(hue, 0, bForGrey));
    // ofSetRectMode(OF_RECTMODE_CENTER);

    auto l = (30 + (30 * sin(ofDegToRad(i / 2.0 + ofGetFrameNum())))) * scale;
    auto l2 = (45 + (45 * sin(ofDegToRad(i / 2.0 + ofGetFrameNum())))) * scale;

    auto x = width / 2 + i / 10.0 * cos(ofDegToRad(i));
    auto y = height / 2 + i / 10.0 * sin(ofDegToRad(i));

    ofDrawCircle(otherPoints[i], l);
    ofSetColor(ofColor::fromHsb(hue, 0, bForGrey));
    // ofSetColor(ofColor::fromHsb(hue, saturation, brightness));
    ofDrawCircle(points[i].x, points[i].y, l2);
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
