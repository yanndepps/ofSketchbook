#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("more colors");
    ofBackground(255, 255, 255);
    ofSetFrameRate(15);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor myDrawCol;

    for (int y = 0; y < ofGetHeight(); y += 20) {
        for (int x = 0; x < ofGetWidth(); x += 20) {
            myDrawCol.setHsb(
                    ofMap(x, 0, ofGetWidth(), 0, 255), 
                    ofMap(y, 0, ofGetHeight(), 0, 255), 
                    ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 255)
                    );
            ofSetColor(myDrawCol);
            ofDrawRectangle(x, y, 20, 20);
        }
    }
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
