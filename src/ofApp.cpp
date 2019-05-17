#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground (255,255,255);
    play.addListener(this,&ofApp::playPressed);
    stop.addListener(this,&::ofApp::stopPresse);
    //if (oneShot){
    //ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".svg", false);
    //    }
    //if (oneShot){
    //        ofEndSaveScreenAsSVG();
    //        onShot = false;
    //    }
    
    gui.setup();
    gui.add(colorSplit.setup("ColorSplit",0.5,0,0.99));
    gui.add(color.setup("color", ofColor(100,100,140), ofColor(0,0), ofColor(255,255)));
    gui.add(color01.setup("color01", ofColor(255,100,140), ofColor(0,0), ofColor(255,255)));
    gui.add(distance.setup("dist",30,10,300));
    gui.add(play.setup("play"));
    gui.add(stop.setup("stop"));
    gui.add(volume.setup("volume", 1.0,0.0,1.0));
    gui.add(speed.setup("speed", 1.0,-3.0,3.0));
    //gui.add(linesWeight.setup("linesWeight",0.1,0.1,1.5));
    
    
    bHide =false;
    
    mySound.load("Sound_BG.mp3");
    mySound.play();
    mySound.setLoop(true);{
        
    
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if (leftMouseButtonPressed){
        ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
        if(lastPoint.distance(mousePos)> minDistance){
            currentPolyline.curveTo(mousePos.x, mousePos.y);
            lastPoint = mousePos;
        }
        
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // ofSetLineWidth(linesWeight);
    ofEnableAlphaBlending();
    
    int firstPolylines=colorSplit*polylines.size();
    
    for (int i=0; i<firstPolylines-1;i++) {
        ofSetColor(colors[i]);
        polylines[i].draw();
        
        //        ofSetColor(color);
        //        ofPolyline(polylines.a, polylines.b).draw();
        //currentPolyline.draw(polylines.a, polylines.b);
    }
    
    
    
    if(polylines.size()>firstPolylines){
        int lastPolyline = polylines.size()-1;
        for(int i=firstPolylines; i<lastPolyline; i++){
            ofSetColor(colorsTwo[i]);
            polylines[i].draw();
            //            oflastPoint(polylines[i].a, polylines[i].b );
        }
        
        if (!bHide){
            gui.draw();
        }
        mySound.setVolume(volume);
        mySound.setSpeed(speed);
        
    }
}
void ofApp::playPressed(){
    mySound.play();
    
}
void ofApp::stopPresse(){
    mySound.stop();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'x'){
        img.grabScreen (0,0, ofGetWidth(), ofGetHeight());
        img.save("Screenshot.png");
    }
    
    if (key == OF_KEY_BACKSPACE) {
        polylines.clear();
        colors.clear();
        colorsTwo.clear();
    }
    
    if (key == 'p'){
        mySound.play();
    }
    if (key == ' '){
    ofToggleFullscreen();
        
    }
    if (key == 'h'){
        bHide = !bHide;
    
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
    for (auto point : drawnPoints ){
        ofPoint mouse;
        mouse.set(x,y);
        float dist = (mouse - point).length();
        if (dist < distance){
            ofPolyline polylinesTemp;
            polylinesTemp.addVertex(mouse);
            polylinesTemp.addVertex(point);
            
            //                Line myLine;
            //                myLine.a = mouse;
            
            
            //                polylinesTemp.a = mouse;
            //                polylinesTemp.b = point;r
            colors.push_back(color);
            colorsTwo.push_back(color01);
            polylines.push_back(polylinesTemp);
        }
    }
    drawnPoints.push_back(ofPoint(x,y));
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (button == OF_MOUSE_BUTTON_LEFT){
        leftMouseButtonPressed = true;
        currentPolyline.curveTo(x,y);
        lastPoint.set(x,y);
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (button == OF_MOUSE_BUTTON_LEFT){
        leftMouseButtonPressed = false;
        polylines.push_back(currentPolyline);
        currentPolyline.clear();
        
        
    }
    
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
