#pragma once

#include "ofMain.h"
#include "ofxCurve.h"

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
  vector<glm::vec3> controlPoints;
  vector<glm::vec3> points;
  vector<glm::vec3> newControls;
  vector<glm::vec3> otherPoints;
};
