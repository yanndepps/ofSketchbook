#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{

public:
  void setup();
  void update();
  void draw();

  ofPolyline myLine;
  int minInc;
  int maxInc;
};
