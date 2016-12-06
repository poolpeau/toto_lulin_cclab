#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // step 3 : setup video grabber
    
    ofBackground(128);
    
    mCamWidth = 320;
    mCamHeight = 240;
    
    mVidGrabber.setDeviceID(0);
    mVidGrabber.setDesiredFrameRate(60);
    mVidGrabber.initGrabber(mCamWidth,mCamHeight);
    
    //step8 : Setup openCV objects
    
    mColorImg.allocate(mCamWidth, mCamHeight);
    mGrayImage.allocate(mCamWidth, mCamHeight);
    mGrayBg.allocate(mCamWidth, mCamHeight);
    mGrayDiff.allocate(mCamWidth, mCamHeight);
    
    mThreshold = 80;
    mLearnBackground = true;
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //step 4: grab data from webcam
    
    mVidGrabber.update();
    
    //step9 : CV
    //only do this when there is a new frame from webcam
    
    if(mVidGrabber.isFrameNew()){
    
        //convert webcam to cv format
        
        mColorImg.setFromPixels(mVidGrabber.getPixels());
        //convert to grayscale image (channels==> 1 channel)
        
        mGrayImage = mColorImg;
        
        if(mLearnBackground == true) {
        
            mGrayBg= mGrayImage;
            mLearnBackground = false;
        }
        
        //take absolute value  :
        mGrayDiff.absDiff(mGrayBg, mGrayImage);
        mGrayDiff.threshold(mThreshold); // pixels that have value >< mthreshold becomes whitte, others become black
        
        //step 12: blob detection
        //find contour which are between the size of 20 pixels and 1/3 the w*h pixels
        
        mContourFinder.findContours(mGrayDiff, 20, (mCamWidth*mCamHeight)/3, 20, true);
        
        
        
    }
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // step5
    
    ofSetColor(255);
    mVidGrabber.draw(20,20);
    
    //step 10
    
    mGrayImage.draw(360,20);
    mGrayBg.draw(20,280);
    mGrayDiff.draw(360,280);
    
    //step13: draw
    
    ofFill();
    ofSetColor(0);
    ofDrawRectangle(360, 540, 320, 240);
    ofSetColor(255);
    
    mContourFinder.draw(360,540);
    // now draw blobs over webcam image
    //first draw webcam image
    mVidGrabber.draw(20,540);
    
    //
    
    for(int i = 0; i < mContourFinder.nBlobs; i++){
        mContourFinder.blobs[i].draw(20,540);
        if(mContourFinder.blobs[i].hole){
            ofDrawBitmapString("hole", mContourFinder.blobs[i].boundingRect.getCenter().x+20, mContourFinder.blobs[i].boundingRect.getCenter().y+540);
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    //step 11:
    switch(key){
    case' ':
        mLearnBackground = true;
        break;
            
            //step14: use s key to save snapshot image to disk/bin
            
            case 's':
            ofImage snapshot;
            snapshot.allocate(ofGetWindowWidth(), ofGetWindowHeight(), OF_IMAGE_COLOR);
            snapshot.grabScreen(0,0,ofGetWindowWidth(), ofGetWindowHeight());
            snapshot.save("snapshot.png");
            break;
            
            
            
    
    
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
