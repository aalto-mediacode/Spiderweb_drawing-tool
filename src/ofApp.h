#pragma once

#include "ofMain.h"
#include"ofxGui.h"

class Line {
public:
    ofPoint a;
    ofPoint b; //the point a and b define the beginning and end of the line
};

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
    

    bool bHide;
    
    ofPolyline currentPolyline;
    ofVec2f lastPoint;
    vector <ofPolyline> polylines;
    vector <ofColor> colors;
    vector <ofColor> colorsTwo;
    bool leftMouseButtonPressed;
    float minDistance;
    //vector <ofVec3f>; vertices;
    void playPressed();
    void stopPresse();
    
    vector < ofPoint > drawnPoints;
    //vector < Line > lines;
    // 2 new vectors are defined ofPoint and LIne
    ofxFloatSlider linesWeight;
    ofxFloatSlider colorSplit;
    ofxColorSlider color;
    ofxColorSlider color01;
    ofxFloatSlider distance;
    ofImage img;
    
    ofxPanel gui;
    ofxButton play;
    ofxButton stop;
    ofxFloatSlider volume;
    ofxFloatSlider speed;

    ofSoundPlayer mySound;
    
    
};
