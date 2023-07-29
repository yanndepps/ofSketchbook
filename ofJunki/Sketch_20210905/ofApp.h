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
  ofMesh face, line, sphere_face, sphere_line;
  vector<ofMeshFace> triangle_list;

  glm::vec3 blue_location;
  glm::vec3 red_location;

  ofFbo fbo;
  float scale;
  float width, height;
  bool save;
  string fileName;
};
