#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{

public:
  void setup();
  void update();
  void draw();

  ofFbo fbo;
  float scale;
  float width, height;
  glm::vec2 centre;
  bool save;
  string fileName;
};
