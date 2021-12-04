#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxGui.h"
#include "Planet.h"
#include "Celestial.h"
#include "BlackHole.h"
#include "Star.h"
#include "instruction.h"
#include "moon.h"

#define PI_ 3.14159265358979323846

class ofApp : public ofBaseApp {

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
		void descTexts();
		void drawUIButtons();
		void updateUI();
		void descriptionTokenizer(string description);

		ofLight light;

		//PLANETS
		Celestial sun{ 0, 0, 0, 200 };
		Planet Mercury{ 400, 0, 0, 3.8, 370 };
		Planet Venus { 440, 0, 0, 9.5, 300 };
		Planet Earth { 480, 0, 0, 10, 230 };
		Planet Mars { 525, 0, 0, 5.3, 160 };
		Planet Jupiter { 685, 0, 0, 50, 100 };
		Planet Saturn { 850, 0, 10, 38, 70 };
		Planet Uranus { 960, 0, 10, 22, 40 };
		Planet Neptune { 1030, 0, 10, 20, 30 };

		//MOON
		Moon moon{ 20, 0, 0, 1 };
		float r;
		float v;
		ofMaterial moonMat;


		//BLACK HOLE
		BlackHole BlackHole { 0,0, 50, 120 };

		//USER INTERFACE
		ofxButton buttonMerc, buttonVenu, buttonEart, buttonMars, buttonJupi, buttonSatu, buttonUran, buttonNept;
		bool showDescMercury, showDescVenus, showDescEarth, showDescMars, showDescJupiter, showDescSaturn, showDescUranus, showDescNeptune; 		
		
		ofxButton buttonInstruction;
		Instruction instruction;			//calling the instruction class 

	private:
		//TEXTURES FOR PLANETS AND SUN
		ofImage sunTex{ "sun.jpg" };
		ofImage merTex{"mercury.jpg"};
		ofImage venTex{"venus.jpg"};
		ofImage earthTex{"earth.png"};
		ofImage marTex{"mars.png"};
		ofImage jupTex{"jupiter.jpg"};
		ofImage satTex{"saturn.jpg"};
		ofImage uraTex{ "uranus.jpg" };
		ofImage nepTex{"neptune.jpg"};
		ofImage moonTex{ "moon.png" };    //!!!!!!!!!!!!!!!!!DECIDE IF WE NEED THAT 
		ofImage spaceship;

		//3D Ship Hologram model and rotations
		ofVboMesh shipHologram;
		float shipxRot, shipyRot, shipzRot;
		
		//SOUND PLAYERS
		ofSoundPlayer cockPitSystemSfx;
		ofSoundPlayer shipEngineSfx;

		//CAMERA
		ofCamera cam;
		float rotateLeftRight, roll, camDistance;
		float rotateUpDown;

		//STARS
		std::vector <Star*> stars;
		float xPos;
		float yPos;
		float zPos;
		float size;

		//ON/OFF BOOL key 
		bool orbitSwitch;
		bool spaceshipSwitch;
		bool oneLineSwitch;

		//BUTTONS
		ofColor backColor;
		ofColor texColor;
		float widthButton;
		float lengthButton;
		float yPosZero;
		float xPosB;
		float width;
		float height;
};
