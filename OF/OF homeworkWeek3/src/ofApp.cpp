#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // step 3 : setup video grabber
    
    ofBackground(128);
    
    
    mCamWidth = 320;
    mCamHeight = 240;
    bShowBlended = false;

    
    mVidGrabber.setDeviceID(0);
    mVidGrabber.setDesiredFrameRate(1);
    mVidGrabber.initGrabber(mCamWidth,mCamHeight);
    
    //step8 : Setup openCV objects
    
    mColorImg.allocate(mCamWidth, mCamHeight);
    mGrayImage.allocate(mCamWidth, mCamHeight);
    mGrayBg.allocate(mCamWidth, mCamHeight);
    mGrayDiff.allocate(mCamWidth, mCamHeight);
    
 
    
    
    
    im_color.allocate(mCamWidth, mCamHeight);
    im_red.allocate(mCamWidth, mCamHeight);
    im_green.allocate(mCamWidth, mCamHeight);
    im_blue.allocate(mCamWidth, mCamHeight);
    im_gray.allocate(mCamWidth, mCamHeight);
    im_value.allocate(mCamWidth, mCamHeight);
    

    
    
    
    
    
    mThreshold = 1.0;
    mLearnBackground = true;
    
    invertedVideoData = new unsigned char [mCamWidth * mCamHeight * 3];
    myTexture.allocate (mCamWidth,mCamHeight, GL_RGB);
    
    

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
         mColorImg.undistort(1, 1,1,1, 200, 200, mCamWidth/2, mCamHeight/2 );
        //mColorIMG.undistort(<#float radialDistX#>, <#float radialDistY#>, <#float tangentDistX#>, <#float tangentDistY#>, <#float focalX#>, <#float focalY#>, <#float centerX#>, <#float centerY#>)

        //convert to grayscale image (channels==> 1 channel)
        
        mGrayImage = mColorImg;
        
        if(mLearnBackground == true) {
        
            mGrayBg= mGrayImage;
            mLearnBackground = false;
        }
        
        //take absolute value  :
        mGrayDiff.absDiff(mGrayBg, mGrayImage);
        mGrayDiff.threshold(mThreshold*30); // pixels that have value >< mthreshold becomes whitte, others become black
        
        //step 12: blob detection
        //find contour which are between the size of 20 pixels and 1/3 the w*h pixels
        
        mContourFinder.findContours(mGrayDiff, 100, (mCamWidth*mCamHeight)/2, 1000, true);
        
        
        
    }
    
     //image2.resize( image2.width * 0.5, image2.height * 0.5 );
     //image2.undistort( -0.5, 1, 0.2, 0.1, 2000, 150, w/2, h/2 );
    
    
    
    
    if(mVidGrabber.isFrameNew()){
        // copy the pixels from the camera object into an ofxCvColorImage object
        im_color.setFromPixels(mVidGrabber.getPixels(), mCamWidth, mCamHeight);
        im_color.undistort( -0.5, 1, 0.2, 0.1, 200, 150, mCamWidth/2, mCamHeight/2 );
        
        im_gray = im_color;
        
        // get each color channel
        im_color.convertToGrayscalePlanarImages(im_red, im_green, im_blue);
        
        im_color.convertRgbToHsv();
        im_color.convertToGrayscalePlanarImage(im_value, 2);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    // step5
    
    ofSetColor(255);
    mVidGrabber.draw(30,30);
    
    //step 10
    
    mGrayImage.draw(350,50);
    
    //mGrayBg.draw(20,280);
    mGrayDiff.draw(650,50);
    
    //step13: draw
    
    ofFill();
    ofSetColor(0);
    ofDrawRectangle(360, 540, 320, 240);
    ofSetColor(255);
    
    //mContourFinder.draw(360,520);
    // now draw blobs over webcam image
    //first draw webcam image
    mVidGrabber.draw(30,30);
    
    //
    
    for(int i = 0; i < mContourFinder.nBlobs; i++){
        mContourFinder.blobs[i].draw(650,50);
        if(mContourFinder.blobs[i].hole){
            ofDrawBitmapString("I DID MY HOMEWORK!", mContourFinder.blobs[i].boundingRect.getCenter().x+650, mContourFinder.blobs[i].boundingRect.getCenter().y+50);
        }
    }
    
    //ofSetColor(255, 255, 255);
    //mVidGrabber.draw(mCamWidth * 0,0);
    
    if(bShowBlended)
    {
        // blending mode for adding pictures together
        ofEnableAlphaBlending();
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        
        // full red energy
        ofSetColor(255, 0, 0);
        im_red.draw(mCamWidth * 1,0);
        
        // full green energy
        ofSetColor(200, 255, 150);
        
        // draw using an offset from the center of the screen determined by the mouse position
        im_green.draw(mCamWidth * 1 + (mouseX - ofGetScreenWidth()/2) / 10.0,0);
        
        // full blue energy
        ofSetColor(0, 0, 255);
        
        // offset just like above, but 2x as much
        im_blue.draw(mCamWidth * 1 + (mouseX - ofGetScreenWidth()/2) / 5.0,0);
        
        ofDisableAlphaBlending();
    }
    else
    {
        ofSetColor(255, 0, 0);
        im_red.draw(350,300);
        
        ofSetColor(200, 255, 150);
        im_green.draw(30,300);
        
        ofSetColor(100, 70, 255);
        im_blue.draw(670,300);
    }
    
    ofSetColor(255, 255, 255);
    im_gray.draw(mCamWidth * 4, 0);
    im_value.draw(mCamWidth * 5, 0);
    
    
    
    
    
    
    
    
    
    
    
    
    

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
