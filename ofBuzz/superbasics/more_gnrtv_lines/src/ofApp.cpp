#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("more generative lines");
    ofBackground(33, 33, 33);
    ofSetFrameRate(15);
    linePercent = 0.0;
}

//--------------------------------------------------------------
void ofApp::update(){
    linePercent += 0.01;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    ofSetLineWidth(3);
    myLine.draw();
    ofSetColor(200, 0, 0);
    ofDrawCircle(myLine.getPointAtPercent(linePercent), 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // toggle fullscreen
    if (key == 'f') {
        ofToggleFullscreen();
    }
    // draw some lines
    if (key == 'd') {
        myLine.clear();
        for (int i = 0; i < 20; i++) {
            myLine.curveTo(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        }
        myLine.close();
        linePercent = 0.0;
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
