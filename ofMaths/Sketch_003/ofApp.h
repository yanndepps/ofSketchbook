#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{

public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);

  //---
  float centerY;
  float centerX;
  float offset;
  float speed;
  float angle;

  void render();
};
