#include "instruction.h"

Instruction::Instruction(){
	xPos = ofGetWindowWidth();
	yPos = ofGetWindowHeight();
}

void Instruction::drawDescription(int a){

	ofSetColor(0, 255, 255, 200);
	//ofSetColor(255, 38, 52, 200);

	if (a == 1){
		//INSTRUCTON: SPACESHIP ON && DESCRIPTION OFF
		ofDrawBitmapString("Accelerate / Decelerate : UP-ARROW, DOWN-ARROW",  0.38 * xPos, yPos * 0.1);
		ofDrawBitmapString("         Line-Up Planets ON/OFF : L",             0.38 * xPos, yPos * 0.12);
		ofDrawBitmapString("         Spaceship Movement : A, D",              0.38 * xPos, yPos * 0.14);
		ofDrawBitmapString("           Turn Orbit ON/OFF : O",                0.38 * xPos, yPos * 0.16);
		ofDrawBitmapString("            Spaceship ON/OFF : U",                0.38 * xPos, yPos * 0.18);
	}

	else if (a == 2) {
		//INSTRUCTION: SPACEHIP ON && DESCRIPTION ON
		ofDrawBitmapString("     Line-Up Planets ON/OFF : L", 0.41 * xPos, yPos * 0.1);
		ofDrawBitmapString("         Spaceship ON/OFF : U"   , 0.41 * xPos, yPos * 0.12);
	}

	else if (a == 3) {
		//INSTRUCTION: SPACESHIP OFF
		ofDrawBitmapString("Zoom-IN / Zoom-OUT : UP-ARROW, DOWN-ARROW", 0.38 * xPos, yPos * 0.05);
		ofDrawBitmapString("  Camera Movement : W, A, S, D, E, Q",      0.38 * xPos, yPos * 0.07);
		ofDrawBitmapString("      Line-Up Planets ON/OFF : L",          0.38 * xPos, yPos * 0.09);
		ofDrawBitmapString("         Turn Orbit ON/OFF : O",            0.38 * xPos, yPos * 0.11);
		ofDrawBitmapString("          Spaceship ON/OFF : U",            0.38 * xPos, yPos * 0.13);
	}
}

