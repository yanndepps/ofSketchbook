/*
** © Aalto Project
** Sketch_006
** Shape_A_Type_B_appear
** Recoded
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  scale = 2.0;
  save = false;
  fileName = "output/frame_";

  width = 2.0 * ofGetWidth();
  height = 2.0 * ofGetHeight();
  centre = glm::vec2((ofGetWidth() * 2.0) / 2.0, (ofGetHeight() * 2.0) / 2.0);

  ofEnableSmoothing();
  ofEnableAntiAliasing();
  ofEnableAlphaBlending();

  ofSetCircleResolution(100 * 2.0);
  // ofSetCircleResolution(200);

  ofBackground(0);

  fbo.allocate(width, height, GL_RGBA);

  ofSeedRandom(72); // 8872

  controlPoints.resize(3 * 2 + 1);

  for (int i = 0; i < controlPoints.size(); ++i) {
    controlPoints[i] = glm::vec3(ofRandom(100 * 2.0, width - 100 * 2.0),
                                 ofRandom(100 * 2.0, height - 100 * 2.0),
                                 0.0);
  }

  points = evalCR(controlPoints, 200);

  counter = 0;
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

  int selectedFrame = 467;
  for (int i = 0; i < counter; i++) {
    float r = 127 + 127 * sin(ofDegToRad(i + selectedFrame));
    float g = 127 + 127 * sin(ofDegToRad(i + 50 * sin(ofDegToRad(selectedFrame))));
    float b = 127 + 127 * sin(ofDegToRad(i + 25 * sin(ofDegToRad(selectedFrame))));

    ofSetColor(r, g, b);

    // float x = centre.x + (i / 1.0) * cos(ofDegToRad(i)) * ofNoise(0.0 / 50.0) * scale;
    // float y = centre.y + (i / 1.0) * sin(ofDegToRad(i)) * ofNoise(0.0 / 500.0) * scale;

    ofDrawCircle(points[i], 40 * scale + 25 * cos(ofDegToRad((i + selectedFrame + ofGetFrameNum()) / 1.0)) * scale);
  }

  fbo.end();

  fbo.draw(0, 0, ofGetWidth(), ofGetHeight());

  if (save && (counter < points.size())) {
    ofPixels pix;
    fbo.readToPixels(pix);
    ofSaveImage(pix, fileName + ofToString(ofGetFrameNum()) + ".png", OF_IMAGE_QUALITY_BEST);
  }

  if (counter >= points.size())
    ofExit();

  if (counter < points.size())
    counter++;
}

//--------------------------------------------------------------
int main()
{

  ofSetupOpenGL(512, 512, OF_WINDOW);
  ofRunApp(new ofApp());
}

//--------------------------------------------------------------
