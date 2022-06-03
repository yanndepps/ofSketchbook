#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{

public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);

  ofEasyCam cam;
  ofMesh face, frame;

  ofFbo fbo;
  float scale;
  float width, height;
  bool save;
  string fileName;
};
