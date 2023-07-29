/*
** © Aalto Project
** Sketch_014
** perlinShapeShifter
** Recoded
*/

#include "ofApp.h"
#include "ofAppRunner.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  scale = 2.0;
  save = true;
  fileName = "output/frame_";

  width = scale * ofGetWidth();
  height = scale * ofGetHeight();
  centre =
      glm::vec2((ofGetWidth() * scale) / 2.0, (ofGetHeight() * scale) / 2.0);

  ofEnableSmoothing();
  ofEnableAntiAliasing();
  ofEnableAlphaBlending();

  // ofSetCircleResolution(200);
  ofSetCircleResolution(700 * scale);
  ofBackground(0);

  fbo.allocate(width, height, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update() { ofSetWindowTitle(ofToString(ofGetFrameNum())); }

//--------------------------------------------------------------
void ofApp::draw()
{
  fbo.begin();
  ofClear(0, 0, 0, 0);
  // ---
  // TODO
  for (int i = 0; i < 500; i++) {
    float r = 255 * sin(ofDegToRad(i + ofGetFrameNum()));
    float g = 255 * sin(ofDegToRad(i + 20 * sin(ofDegToRad(ofGetFrameNum()))));
    float b = 255 * sin(ofDegToRad(i + 10 * cos(ofDegToRad(ofGetFrameNum()))));

    ofSetColor(r, g, b);

    float x = centre.x + (i / 1.0) * cos(ofDegToRad(i)) * ofNoise(ofGetFrameNum() / 100.0) * scale;
    float y = centre.y + (i / 1.0) * sin(ofDegToRad(i)) * ofNoise(ofGetFrameNum() / 1000.0) * scale;

    ofDrawCircle(x, y, 100 * cos(ofDegToRad(i + ofGetFrameNum() / 10.0)) * scale);
  }
  // ---
  fbo.end();
  fbo.draw(0, 0, ofGetWidth(), ofGetHeight());

  if (save && ofGetFrameNum() < 3601) {
    ofPixels pix;
    fbo.readToPixels(pix);
    ofSaveImage(pix, fileName + ofToString(ofGetFrameNum()) + ".png",
                OF_IMAGE_QUALITY_BEST);
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
