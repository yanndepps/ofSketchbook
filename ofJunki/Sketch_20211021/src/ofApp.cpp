/*
** Recoded sketch 20211021 from JunKiyoshi
** wip -> export frame by frame animation
** TODO: implement proper scale factor
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  scale = 1.0;
  save = true;
  fileName = "loveLetter";

  width = scale * ofGetWidth();
  height = scale * ofGetHeight();

  ofEnableSmoothing();
  ofEnableAntiAliasing();
  ofEnableAlphaBlending();

  ofSetFrameRate(30);
  ofSetWindowTitle("openFrameworks");
  ofBackground(239);
  ofSetColor(39);
  ofSetBackgroundAuto(false);

  fbo.allocate(width, height, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update() { ofSeedRandom(21); }

//--------------------------------------------------------------
void ofApp::draw() {
  fbo.begin();
  // ofClear(0, 0);

  for (int i = 0; i < 2; i++) {
    auto location = glm::vec2(
        ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.05), 0, 1, 50, 670),
        ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.05), 0, 1, 50, 670));
    auto scale =
        ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.05), 0, 1, 1, 10);

    ofPushMatrix();
    ofTranslate(location);
    ofRotate(ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.05), 0, 1, -360,
                   360));

    ofSetColor(39);
    ofFill();
    ofBeginShape();
    for (auto deg = 0; deg < 360; deg += 1) {
      ofVertex(this->make_point(deg * DEG_TO_RAD) * scale);
    }
    ofEndShape(true);

    ofSetColor(239);
    ofNoFill();
    ofBeginShape();
    for (auto deg = 0; deg < 360; deg += 1) {
      ofVertex(this->make_point(deg * DEG_TO_RAD) * scale);
    }
    ofEndShape(true);
    ofPopMatrix();
  }

  ofSetColor(239);
  ofFill();
  ofBeginShape();
  ofVertex(0, 0);
  ofVertex(ofGetWidth(), 0);
  ofVertex(ofGetWidth(), ofGetHeight());
  ofVertex(0, ofGetHeight());
  ofNextContour(true);
  ofVertex(50, 50);
  ofVertex(ofGetWidth() - 50, 50);
  ofVertex(ofGetWidth() - 50, ofGetHeight() - 50);
  ofVertex(50, ofGetHeight() - 50);
  ofEndShape(true);

  fbo.end();
  fbo.draw(0, 0, ofGetWidth(), ofGetHeight());

  if (save) {
    ofPixels pix;
    fbo.readToPixels(pix);
    ofSaveImage(pix, fileName + "_" + ofToString(ofGetFrameNum()) + ".png",
                OF_IMAGE_QUALITY_BEST);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
//--------------------------------------------------------------
glm::vec2 ofApp::make_point(float theta) {
  float x = 16 * (pow(sin(theta), 3));
  float y = 13 * cos(theta) - 5 * cos(2 * theta) - 2 * cos(3 * theta) -
            cos(4 * theta);
  return glm::vec2(x, -y);
}
//--------------------------------------------------------------
int main() {
  ofSetupOpenGL(720, 720, OF_WINDOW);
  ofRunApp(new ofApp());
}
