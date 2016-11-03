#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(30,210, 100);
    background.load("Cluttered.jpg");
    ofSetBackgroundAuto(false);
    

    
    myImage.load("browser.png");
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    
//    //ofEnableBlendMode(OF_BLENDMODE_SCREEN);
//    ofPushMatrix();
//    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2 );
//    ofRotate (cos( ofGetElapsedTimef())*200);
//    r = ofRandom(0,255);
//    g = ofRandom (0,255);
//    b = ofRandom (0,255);
//
//    //myImage.draw(0, 0, 600,400);
//    myImage.draw(ofGetMouseX()/4, ofGetMouseY()/5, 300,300);
//    ofSetColor(r, g, b);
//      ofNoFill();
//    ofPushMatrix();
    
   // background.draw(0,0, 1064,768);
     //myImage.draw(ofGetMouseX()/4, ofGetMouseY()/5, 300,300);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    //background.draw(0,0, 1064,768);
    
    //ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    ofPushMatrix();

    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2 );
    ofRotate (cos( ofGetElapsedTimef())*50);
    r = ofRandom(0,255);
    g = ofRandom (0,255);
    b = ofRandom (0,255);
    
    //myImage.draw(0, 0, 600,400);
    myImage.draw(ofGetMouseX()/4, ofGetMouseY()/5, 300,300);
    ofSetColor(r, g, b);
 
    ofPushMatrix();

    
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
