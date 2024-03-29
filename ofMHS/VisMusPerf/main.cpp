#include "ofApp.h"
#include "ofMain.h"

//========================================================================
int main() {
  ofGLWindowSettings settings;
  settings.setGLVersion(3, 3);
  settings.windowMode = OF_FULLSCREEN;
  ofCreateWindow(settings);

  // this kicks off the running of my app
  // can be OF_WINDOW or OF_FULLSCREEN
  // pass in width and height too:
  ofRunApp(new ofApp());
}
