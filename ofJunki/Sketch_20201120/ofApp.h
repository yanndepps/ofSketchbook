#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{

public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);

  vector<glm::vec2> location_list;
  vector<float> deg_list;
  vector<int> param_list;
  vector<ofColor> color_list, base_color_list;

  ofFbo fbo;
  float scale;
  float width, height;
  float save;
  string fileName;
};
