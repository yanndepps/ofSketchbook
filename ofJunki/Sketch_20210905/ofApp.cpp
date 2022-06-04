/*
** © JunKiyoshi
** Recoded & Edited
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetFrameRate(60);
  ofSetWindowTitle("openframeworks");

  ofBackground(239);
  ofNoFill();
  ofSetColor(39);
  ofEnableDepthTest();
  ofEnableSmoothing();
  ofEnableAntiAliasing();
  ofSetCircleResolution(60);
  ofSetLineWidth(2);

  auto ico_sphere = ofIcoSpherePrimitive(80, 5);
  this->triangle_list.insert(this->triangle_list.end(), ico_sphere.getMesh().getUniqueFaces().begin(), ico_sphere.getMesh().getUniqueFaces().end());

  this->line.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
  this->sphere_line.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);

  // ---
  scale = 1.0;
  save = false;
  fileName = "./output/frame";
  width = scale * ofGetWidth();
  height = scale * ofGetHeight();
  fbo.allocate(width, height, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update()
{
  ofSeedRandom(39);

  this->face.clear();
  this->line.clear();
  this->sphere_face.clear();
  this->sphere_line.clear();

  float x_span = 1;
  auto noise_seed = glm::vec2(ofRandom(1000), ofRandom(1000));

  for (int x_param = -1; x_param <= 1; x_param += 2) {
    int start_index = this->face.getNumVertices();
    for (float x = 100; x < 250; x += x_span) {
      float next_x = x + x_span;
      int index = this->face.getNumVertices();

      float angle_x = ofMap(ofNoise(noise_seed.x, x * 0.0035 + ofGetFrameNum() * 0.0085), 0, 1, PI * -2, PI * 2);
      auto rotation_x = glm::rotate(glm::mat4(), angle_x, glm::vec3(1, 0, 0));

      float angle_y = ofMap(ofNoise(noise_seed.y, x * 0.0035 + ofGetFrameNum() * 0.0085), 0, 1, PI * -2, PI * 2);
      auto rotation_y = glm::rotate(glm::mat4(), angle_y, glm::vec3(0, 1, 0));

      float next_angle_x = ofMap(ofNoise(noise_seed.x, next_x * 0.0035 + ofGetFrameNum() * 0.0085), 0, 1, PI * -2, PI * 2);
      auto next_rotation_x = glm::rotate(glm::mat4(), next_angle_x, glm::vec3(1, 0, 0));

      float next_angle_y = ofMap(ofNoise(noise_seed.y, next_x * 0.0035 + ofGetFrameNum() * 0.0085), 0, 1, PI * -2, PI * 2);
      auto next_rotation_y = glm::rotate(glm::mat4(), next_angle_y, glm::vec3(0, 1, 0));

      vector<glm::vec3> vertices;
      vertices.push_back(glm::vec4(x * x_param, 20, 0, 0) * rotation_y * rotation_x);
      vertices.push_back(glm::vec4(next_x * x_param, 20, 0, 0) * next_rotation_y * next_rotation_x);
      vertices.push_back(glm::vec4(next_x * x_param, -20, 0, 0) * next_rotation_y * next_rotation_x);
      vertices.push_back(glm::vec4(x * x_param, -20, 0, 0) * rotation_y * rotation_x);

      this->face.addVertices(vertices);
      this->line.addVertices(vertices);

      this->face.addIndex(index + 0);
      this->face.addIndex(index + 1);
      this->face.addIndex(index + 2);
      this->face.addIndex(index + 0);
      this->face.addIndex(index + 2);
      this->face.addIndex(index + 3);

      this->line.addIndex(index + 0);
      this->line.addIndex(index + 1);
      this->line.addIndex(index + 2);
      this->line.addIndex(index + 3);

      if (x_param == -1) {
	this->face.addColor(ofColor(255, 0, 153));
	this->face.addColor(ofColor(255, 0, 153));
	this->face.addColor(ofColor(255, 0, 153));
	this->face.addColor(ofColor(255, 0, 153));
      } else {
	this->face.addColor(ofColor(0, 203, 255));
	this->face.addColor(ofColor(0, 203, 255));
	this->face.addColor(ofColor(0, 203, 255));
	this->face.addColor(ofColor(0, 203, 255));
      }

      if (x == 100 && x_param == -1) {
	this->red_location = (vertices[0] + vertices[3]) / 2;
      }

      if (x == 100 && x_param == 1) {
	this->blue_location = (vertices[0] + vertices[3]) / 2;
      }
    }

    this->line.addIndex(start_index + 0);
    this->line.addIndex(start_index + 3);
    this->line.addIndex(this->line.getNumVertices() - 1);
    this->line.addIndex(this->line.getNumVertices() - 2);
  }

  for (int i = 0; i < this->triangle_list.size(); i++) {
    vector<glm::vec3> vertices;

    glm::vec3 avg = (this->triangle_list[i].getVertex(0) + this->triangle_list[i].getVertex(1) + this->triangle_list[i].getVertex(2)) / 3;
    vertices.push_back(this->triangle_list[i].getVertex(0));
    vertices.push_back(this->triangle_list[i].getVertex(1));
    vertices.push_back(this->triangle_list[i].getVertex(2));

    this->sphere_face.addVertices(vertices);
    this->sphere_line.addVertices(vertices);

    if (glm::distance(avg, this->red_location) > glm::distance(avg, this->blue_location)) {
      this->sphere_face.addColor(ofColor(0, 203, 255));
      this->sphere_face.addColor(ofColor(0, 203, 255));
      this->sphere_face.addColor(ofColor(0, 203, 255));
    } else {
      this->sphere_face.addColor(ofColor(255, 0, 153));
      this->sphere_face.addColor(ofColor(255, 0, 153));
      this->sphere_face.addColor(ofColor(255, 0, 153));
    }

    this->sphere_line.addColor(ofColor(239));
    this->sphere_line.addColor(ofColor(239));
    this->sphere_line.addColor(ofColor(239));

    this->sphere_face.addTriangle(this->sphere_face.getNumVertices() - 1, this->sphere_face.getNumVertices() - 2, this->sphere_face.getNumVertices() - 3);

    this->sphere_line.addIndex(this->sphere_line.getNumVertices() - 1);
    this->sphere_line.addIndex(this->sphere_line.getNumVertices() - 2);
    this->sphere_line.addIndex(this->sphere_line.getNumVertices() - 2);
    this->sphere_line.addIndex(this->sphere_line.getNumVertices() - 3);
    this->sphere_line.addIndex(this->sphere_line.getNumVertices() - 1);
    this->sphere_line.addIndex(this->sphere_line.getNumVertices() - 3);
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  fbo.begin();
  ofClear(0);
  // ---
  this->cam.begin();

  // ofDrawCircle(glm::vec3(), 81);

  ofRotateX(ofGetFrameNum() * 0.37);
  ofRotateY(ofGetFrameNum() * 0.72);

  this->face.draw();
  // this->line.drawWireframe();
  this->sphere_face.draw();
  // this->sphere_line.drawWireframe();

  this->cam.end();
  // ---
  fbo.end();
  fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
  // ---
  if (save) {
    ofPixels pix;
    fbo.readToPixels(pix);
    ofSaveImage(pix, fileName + "_" + ofToString(ofGetFrameNum()) + ".png", OF_IMAGE_QUALITY_BEST);
  }

  // if (ofGetFrameNum() == 360) {
  //   ofLog() << "done rendering !";
  //   ofExit();
  // }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
  if (key == 's') {
    save = !save;
  }
}

//--------------------------------------------------------------
int main()
{

  ofSetupOpenGL(720, 720, OF_WINDOW);
  ofRunApp(new ofApp());
}

//--------------------------------------------------------------
