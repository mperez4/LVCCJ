#pragma once

#include "ofMain.h"
#include "ofxJSONElement.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        ofxJSONElement json;
        ofxJSONElement result;
        string test;
        float posX, posY, posX2, posY2, posX3, posY3;
        Boolean generateVars();
        Boolean fetch;
        Boolean foo;
        Boolean bar;
        ofTrueTypeFont myfont;
        ofTrueTypeFont myfont2;
        vector<string> messagesData;
        vector<string> TO;
        vector<string> FROM;
        vector<string> MESSAGE;
        ofImage myimage, bg;
        int v;
        float mwidth;
        float mwidth2;
        float textHeight, textHeight2;
        bool parsingSuccessful;        
};
