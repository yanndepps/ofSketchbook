// Domestika -> Immersive Art
// Sketch_006 -> Computer Vision & Interactivity Part II
// Video version
// Recoded -> 2023.08.19

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  // init video
  vidPlayer.load("finger.mov");
  vidPlayer.play();
  vidPlayer.setLoopState(OF_LOOP_NORMAL);

  // init openCV
  colorImg.allocate(320, 240);
  grayImg.allocate(320, 240);
  grayBg.allocate(320, 240);
  grayDiff.allocate(320, 240);

  // init GUI
  gui.setup();
  gui.add(overallSpeed.setup("speed", 1, 0, 3));
  gui.add(noiseAmount.setup("noise", 1, 0, 3));
  gui.add(trail.setup("trail", 6, 0, 20));
  gui.add(threshold.setup("threshold", 80, 0, 255));
  gui.add(bLearnBg.setup("capture bg", false));

  ofSetFrameRate(30);
  ofSetWindowTitle("openFrameworks");
  ofBackground(33);
  ofSetColor(249);

  p.assign(600, particle());
  for (int i = 0; i < p.size(); i++) {
    p[i].setup();
  }

  ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update()
{
  // is it a new frame ?
  bool bNewFrame = false;
  // upd player
  vidPlayer.update();
  // true if new frame
  bNewFrame = vidPlayer.isFrameNew();

  // it new frame -> bg substraction operations
  if (bNewFrame == true) {
    // copy video pxls
    colorImg.setFromPixels(vidPlayer.getPixels());
    // convert to grayscale
    grayImg = colorImg;

    // toggle -> capture bg
    if (bLearnBg == true) {
      grayBg = grayImg;
      bLearnBg = false;
    }

    // check diff between captured bg and current frame
    grayDiff.absDiff(grayBg, grayImg);
    // threshold in the grayscale img for better contours
    grayDiff.threshold(threshold);
    // find and create vectorial contours
    contourFinder.findContours(grayDiff, 20, (320 * 20), 10, true);
  }

  // copy points from the contours
  vector<ofVec2f> blobPts;
  for (int i = 0; i < contourFinder.blobs.size(); i++) {
    for (int j = 0; j < contourFinder.blobs[i].pts.size(); j++) {
      blobPts.push_back(contourFinder.blobs[i].pts[j] * ofGetWidth() / 320);
    }
  }

  for (int i = 0; i < p.size(); i++) {
    p[i].repel(blobPts);
    p[i].update(overallSpeed, noiseAmount);
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  ofSetColor(0, 0, 0, trail);
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  ofSetColor(255, 255, 255, 255);

  for (int i = 0; i < p.size(); i++) {
    p[i].draw(1);
  }

  // draw -> incoming, grayscale, bg and threshold difference
  ofSetHexColor(0xffffff);
  colorImg.draw(20, 20);
  grayImg.draw(360, 20);
  grayBg.draw(20, 280);
  grayDiff.draw(360, 280);

  // draw -> contours
  ofFill();
  ofSetHexColor(0x333333);
  ofDrawRectangle(360, 540, 320, 240);
  ofSetHexColor(0xffffff);

  contourFinder.draw(360, 540);

  gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}

//--------------------------------------------------------------
int main()
{
  ofSetupOpenGL(720, 720, OF_WINDOW);
  // ofSetupOpenGL(1366, 768, OF_WINDOW);
  ofRunApp(new ofApp());
}
