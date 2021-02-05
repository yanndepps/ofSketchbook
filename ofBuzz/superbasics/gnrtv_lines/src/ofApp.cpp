#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("generative lines");
    ofBackground(200, 200, 200);
    ofSetFrameRate(15);
}

//--------------------------------------------------------------
void ofApp::update(){
    myLine.addVertex(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor myDrawCol;
    myDrawCol.setHsb(255, 255, 255, 100);
    ofSetColor(myDrawCol);
    ofSetLineWidth(3);
    myLine.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f') {
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
