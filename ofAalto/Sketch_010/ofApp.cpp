/*
** © Aalto Project
** Sketch_010
** VareOne
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

  // ofSeedRandom(122); // version 1
  ofSeedRandom(1232147); // version 2

  int it = 1;

  controlPoints.resize(3 * it + 1);
  newControls.resize(3 * it + 1);

  for (int i = 0; i < controlPoints.size(); ++i) {
    controlPoints[i] = glm::vec3(ofRandom(100 * scale, width - 100 * scale),
                                 ofRandom(100 * scale, height - 100 * scale),
                                 0.0);
  }

  // ofSeedRandom(78);   // version 1
  ofSeedRandom(5132); // version 2

  for (int i = 0; i < newControls.size(); ++i) {
    newControls[i] = glm::vec3(ofRandom(100 * scale, width - 100 * scale),
                               ofRandom(100 * scale, height - 100 * scale),
                               0.0);
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

  int sFrame = 121;
  for (int i = 0; i < points.size(); i++) {
    float r = 127 + 127 * sin(ofDegToRad(i / 2.0 + sFrame * ofGetFrameNum()));
    float g = 127 + 127 * sin(ofDegToRad(i / 2.0 + 10 * sin(ofDegToRad(ofGetFrameNum() + sFrame))));
    float b = 192 + 64 * sin(ofDegToRad(i / 3.0 + 45 * sin(ofDegToRad(ofGetFrameNum() + sFrame))));

    float bForGrey = 191 + 64 * sin(ofDegToRad(i + ofGetFrameNum() + sFrame));
    float hue = 245;
    float saturation = 127 * sin(ofDegToRad(i));
    float brightness = 255;

    // ofSetColor(ofColor::fromHsb(hue, 0, bForGrey)); // use for b&w
    ofSetColor(ofColor::fromHsb(hue, saturation, brightness)); // use for p&w

    auto l = (60 + (60 * sin(ofDegToRad(i + ofGetFrameNum() + sFrame)))) * scale;
    auto l2 = (90 + (45 * sin(ofDegToRad(i + ofGetFrameNum() + sFrame)))) * scale;

    auto x = width / 2 + i / 4.0 * cos(ofDegToRad(i));
    auto y = height / 2 + i / 4.0 * sin(ofDegToRad(i));

    ofDrawCircle(otherPoints[i], l);

    // ofSetColor(ofColor::fromHsb(hue, 0, bForGrey)); // use for b&w
    ofSetColor(ofColor::fromHsb(hue, saturation, brightness)); // use for p&w

    ofDrawCircle(points[i], l2);
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
