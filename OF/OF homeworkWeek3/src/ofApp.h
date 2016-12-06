#pragma once

#include "ofMain.h"

//include header file of openCV

#include"ofxOpenCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //Step 2 : Member objects//
    
    ofVideoGrabber mVidGrabber;
    
    int mCamWidth;
    int mCamHeight;
    unsigned char* invertedVideoData;
    ofTexture myTexture;
    
    //step 7 : member objects/variabes for opencv
    
    // Image storage in openCV format
    
    ofxCvColorImage mColorImg;
    ofxCvGrayscaleImage mGrayImage;
    ofxCvGrayscaleImage mGrayBg;
    ofxCvGrayscaleImage mGrayDiff;
    

    
    
    
    
    ofxCvColorImage im_color;
    ofxCvGrayscaleImage im_red, im_green, im_blue;
    ofxCvGrayscaleImage im_gray;
    ofxCvGrayscaleImage im_value;
    
    
    
    
    
    // For blob detection:
    
    ofxCvContourFinder mContourFinder;
    
    int mThreshold; //threshold for the difference image
    bool mLearnBackground; // indicates whether the background image for difference needs updating
    bool bShowBlended;
    
    
    
		
};
