#pragma once

#include "ofMain.h"

class Actor
{
public:
  Actor(vector<glm::vec3>& location_list, vector<vector<int>>& next_index_list,
        vector<int>& destination_list);

  void update(const int& frame_span, vector<glm::vec3>& location_list,
              vector<vector<int>>& next_index_list, vector<int>& destination_list);

  glm::vec3 getLocation();
  glm::vec3 getPrevLocation();
  deque<glm::vec3> getLog();
  void setColor(ofColor color);
  ofColor getColor();
  float getNoiseSeed();

private:
  int select_index;
  int next_index;
  float noise_seed;

  glm::vec3 location;
  glm::vec3 prev_location;
  deque<glm::vec3> log;
  ofColor color;
};

class ofApp : public ofBaseApp
{

public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);

  glm::vec2 make_point(float theta);

  vector<glm::vec3> location_list;
  vector<vector<int>> next_index_list;
  vector<int> destination_list;

  vector<unique_ptr<Actor>> actor_list;

  ofFbo fbo;
  float toScale;
  float width, height;
  bool save;
  string fileName;
};
