#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    std::string url = "";
    myfont.loadFont("BanglaSangamMN.ttf", 442);
    myfont2.loadFont("BanglaSangamMN.ttf", 142);
    bg.loadImage("bg.jpg");
    textHeight = myfont.stringHeight("I")/2;
    
    textHeight2 = myfont2.stringHeight("I")/2;
    
    posX = ofGetWidth() * 2;
    posX2 = ofGetWidth();
    posX3 = ofGetWidth();
    posY = ofGetHeight()*.66 + textHeight;
    
    posY2 = ofGetHeight()/4 - textHeight2;
    posY3 = posY2 + textHeight2*3;
    
    foo = false;
    bar = false;
    
    v = 0;
    // Parse the JSON
	parsingSuccessful = json.open(url);
	if (parsingSuccessful) {
        cout << "Parsing Successfull" << endl;

	} else {
		cout  << "Failed to parse JSON" << endl;        
	}
    
}

//--------------------------------------------------------------
void testApp::update(){
    posX = posX-3;
    if (posX < mwidth){
        foo = true;                 
    }
    if(!bar){
        posX2 = posX2-3;
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    //if we are able to get the data:
    if(parsingSuccessful && generateVars()){
        ofEnableAlphaBlending();
        ofSetColor(255,210,210,150);
        bg.draw(0,0);
        ofDisableAlphaBlending();

        if (v < json.size()){
            ofSetColor(255);
            
            myfont.drawString(messagesData[v], posX,posY);
            myfont2.drawString(TO[v], posX2 , posY2);
            myfont2.drawString(FROM[v], posX2 , posY3);
            
            if (posX2 == 0){
                bar = true;
                posX2 = 0;
            }
            mwidth = myfont.stringWidth(messagesData[v]) * -1; //width of the current string
            //if the full message text passes the width limit, go to the next message
            if(foo == true){
                v++;
                posX = ofGetWidth();
                foo = false;
            }
        }else {
            v = 0;
        }
    }
}


Boolean testApp::generateVars(){
    for(int i=0; i < json.size(); i++)
    {
        string to = json[i]["to"].asString();
        string from = json[i]["from"].asString();
        string message = json[i]["message"].asString();
        string currentMessage = "To: " + to +"  From: "+ from + "  " + message ;
        messagesData.push_back(message);
        //individual arrays 
        TO.push_back("To: " + to);
        FROM.push_back("From: " + from);
        MESSAGE.push_back("Message: " + message);
//        cout << messagesData[i] << endl;
    }
    return true;
    
}
