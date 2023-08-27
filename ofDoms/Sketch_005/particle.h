#pragma once
#include "ofMain.h"

class particle
{
public:
  particle();

  void setup();
  void update(float speed, float noise);
  void draw(float sizeDot);

  ofVec2f pos;
  ofVec2f vel;
  ofVec2f frc;
  ofVec2f uniqueVal;
  float drag;
  float size;
};
