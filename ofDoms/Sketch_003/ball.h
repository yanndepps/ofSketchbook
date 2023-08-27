#pragma once
#include "ofMain.h"

class ball
{
public:
  ball();
  void setup(ofVec2f initPos, ofVec2f initVel, float rad);
  void update();
  void draw();

  ofVec2f pos;
  ofVec2f vel;
  float radius;
};
