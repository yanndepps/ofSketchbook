/*
 * e17
 * psychedelic video player
 */

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	threshold = 120;
	video.load("keng.mov");
	video.setVolume(0);
	video.setSpeed(1.0);
	video.setLoopState(OF_LOOP_NORMAL);
	video.play();
	image = video.getPixels();
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
	image = video.getPixels();
	image.update();

	ofColor col;
	for (int y = 0; y < image.getHeight(); y++) {
		for (int x = 0; x < image.getWidth(); x++) {
			col = image.getColor(x,y);
			if (col.r > threshold) {
				col.setHsb(ofMap(x, 0, image.getWidth(), 0, 255), 255, 255);
			} else {
				col.set(0);
			}
			image.setColor(x, y, col);
		}
	}
	image.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	/* video.draw(0, 0, ofGetWidth(), ofGetHeight()); */
	image.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key) {
		case 'f':
		case 'F':
			ofToggleFullscreen();
			break;
		case OF_KEY_UP:
			if (threshold < 250) {
				threshold += 5;
			}
			break;
		case OF_KEY_DOWN:
			if (threshold > 10) {
				threshold -=5;
			}
			break;
		case OF_KEY_LEFT:
			video.setSpeed(video.getSpeed() - 0.1);
			break;
		case OF_KEY_RIGHT:
			video.setSpeed(video.getSpeed() + 0.1);
			break;
		default:
			break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
