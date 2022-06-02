/*
** © Junkiyoshi
** Recoded
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetFrameRate(60);
  ofSetWindowTitle("openframeworks");

  // white over black
  // ofBackgroundHex(0x000000);
  // ofSetHexColor(0xffffff);

  // black over white
  // ofBackgroundHex(0xffffff);
  // ofSetHexColor(0x000000);

  // Tendinous
  // https://colors.lol/tendinous
  // tendinous fuchsia -> #ED0DD9 -> bg
  // isotopic light periwinkle -> #C1C6FC -> fg
  // inspired bright purple -> #BE03FD -> tx
  // ofBackgroundHex(0xED0DD9);
  // ofSetHexColor(0xC1C6FC);

  // Undefaced
  // https://colors.lol/undefaced
  // undefaced off white -> #FFFFE4 -> fg
  // self-addressed pinkish brown -> #B17261 -> tx
  // accosted brick red -> #8F1402 -> bg
  // ofBackgroundHex(0x8F1402);
  // ofSetHexColor(0xFFFFE4);

  // Uncited
  // https://colors.lol/uncited
  // uncited tangerine -> #FF9408 -> fg
  // revokable deep turquoise -> #017374 -> tx
  // lubric dark teal -> #014D4E -> bg
  ofBackgroundHex(0x014D4E);
  ofSetHexColor(0xFF9408);

  this->mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);

  // ---
  scale = 1.0;
  save = false;
  fileName = "./output/uncited";
  width = scale * ofGetWidth();
  height = scale * ofGetHeight();

  ofEnableSmoothing();
  ofEnableAntiAliasing();

  fbo.allocate(width, height, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update()
{
  ofSeedRandom(39);
  this->mesh.clear();

  for (int i = 0; i < 4; i++) {
    auto noise_seed = ofRandom(1000);
    for (int x = 0; x <= ofGetWidth(); x += 4) {
      auto y = ofMap(ofNoise(noise_seed, x * 0.003, ofGetFrameNum() * 0.003), 0, 1, 0, ofGetHeight());
      this->mesh.addVertex(glm::vec3(x, y, 0));

      if (x > 0) {
	this->mesh.addIndex(this->mesh.getNumVertices() - 2);
	this->mesh.addIndex(this->mesh.getNumVertices() - 1);
      }
    }
  }

  for (int i = 0; i < this->mesh.getNumVertices(); i++) {
    for (int k = i + 2; k < this->mesh.getNumVertices(); k++) {
      if (glm::distance(this->mesh.getVertex(i), this->mesh.getVertex(k)) < 25) {

	this->mesh.addIndex(i);
	this->mesh.addIndex(k);
      }
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  fbo.begin();
  ofClear(0);
  // ---
  this->mesh.drawWireframe();
  // ---
  fbo.end();
  fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
  // ---
  if (save) {
    ofPixels pix;
    fbo.readToPixels(pix);
    ofSaveImage(pix, fileName + "_" + ofToString(ofGetFrameNum()) + ".png", OF_IMAGE_QUALITY_BEST);
  }
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

  ofSetupOpenGL(512, 512, OF_WINDOW);
  ofRunApp(new ofApp());
}
