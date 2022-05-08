#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{

public:
  void setup();
  void update();
  void draw();

  glm::vec2 make_point(float theta);

  ofEasyCam cam;
  ofMesh face, frame;

  ofFbo fbo;
  float scale;
  float width, height;
  bool save;
  string fileName;
};
