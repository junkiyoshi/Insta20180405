#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofEnableSmoothing();
	ofSetColor(39);

	this->font.loadFont("fonts/Kazesawa-Extrabold.ttf", 16, true, false, true);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 60;
	for (int x = span; x < ofGetWidth() + span; x += span * 2) {

		for (int y = span; y < ofGetHeight() + span; y += span * 2) {

			int minute = ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.005) * 720;
			this->draw_clock(ofPoint(x, y), minute, span * 0.95);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw_clock(ofPoint point, int minute, int radius){

	ofPushMatrix();
	ofTranslate(point);

	ofNoFill();

	ofBeginShape();
	for (int deg = 0; deg < 360; deg += 1) {

		ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
	}
	ofEndShape(true);

	int time = minute / 60;
	minute = minute - time * 60;
	int time_deg = time * 30 + ofMap(minute, 0, 59, 0, 30);
	int minute_deg = minute * 6;

	ofSetLineWidth(5);
	ofDrawLine(ofPoint(), ofPoint(radius * 0.6 * cos(time_deg * DEG_TO_RAD), radius * 0.6 * sin(time_deg * DEG_TO_RAD)));

	ofSetLineWidth(3);
	ofDrawLine(ofPoint(), ofPoint(radius * 0.8 * cos(minute_deg * DEG_TO_RAD), radius * 0.8 * sin(minute_deg * DEG_TO_RAD)));

	ofFill();
	ofDrawCircle(ofPoint(), 5);

	ofPopMatrix();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}