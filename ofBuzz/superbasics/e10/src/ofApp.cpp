#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0);
	ofSetCircleResolution(100);
	// smooth or shard colors
	ofSetDepthTest(true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	float time = ofGetElapsedTimef();
	for (int x = 1; x < 40; x++) {
		for (int i = 0; i < 900; i+= 5) {
			/* ofSetCircleResolution(53 + 50 * sin(i * 0.001 +  time)); */

			ofSetColor(127 + 127 * sin(i * 0.01 + time + x),
					127 + 127 * sin(i * 0.011 + time),
					127 + 127 * sin(i * 0.012 + time));
			// choose
			/* ofDrawCircle(ofGetWidth()/2, i, 100); */

			/* ofDrawCircle(ofGetWidth()/2 + 100 * sin(i * 0.01 + time), i, 50 + 40 * sin(i * 0.005 + time)); */

			ofDrawCircle(50 * x + 100 * sin(i * 0.01 + time + x), 50 + i, 50 + 40 * sin(i * 0.005 + time + x));

			/* ofDrawSphere(50 * x + 100 * sin(i * 0.01 + time + x), 50 * x + 100 * sin(i * 0.01 + time + x), 50 + i, 50 + 40 * sin(i * 0.005 + time + x)); */
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key) {
		case 'f':
		case 'F':
			ofToggleFullscreen();
			break;
		default:
			break;
	}
}

