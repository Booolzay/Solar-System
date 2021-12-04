#include "ofApp.h"
#define PI_ 3.14159265358979323846  

//--------------------------------------------------------------
void ofApp::setup() {
	//GENERAL SETUP: background, camera, lighting, loading images
	ofSetBackgroundColor(0);
	light.setPointLight();
	light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	light.setAmbientColor(ofFloatColor(0.3, 0.3, 0.3));
	light.setPosition(0, 0, 0);

	rotateLeftRight = roll = 0.0f;
	camDistance = 1000.f;
	rotateUpDown = 0.0f;

	spaceship.load("ui.png");// Source : https://www.dualshockers.com/star-citizen-pushes-past-42-million-in-crowd-funding-and-towels-for-all/

	//ON/OFF BOOL KEYS
	orbitSwitch = true;
	spaceshipSwitch = true;

	width = 150;							//Size of Buttons
	height = 10;
	yPosZero = ofGetWindowHeight() / 2.8;   //Button Positions
	xPosB = ofGetWindowWidth() / 19;
	backColor.set(0, 255, 255, 0);			//Setting Button background Color to transparent to look like Holograms
	texColor.set(0, 255, 255, 200);			//Button Text Color

	//BUTTON INSTRUCTION ON/OFF
	buttonInstruction.setup(" INSTRUCTIONS", true);
	buttonInstruction.setSize(150, 20);
	buttonInstruction.setPosition(0.45 * ofGetWidth(), 0.98 * ofGetHeight());
	buttonInstruction.setBackgroundColor(backColor);
	buttonInstruction.setTextColor(texColor);

	//BUTTONS FOR EACH PLANET's DESCRIPTIONS
	buttonMerc.setBackgroundColor(backColor);
	buttonMerc.setTextColor(texColor);
	buttonMerc.setup(" Mercury", false);
	buttonMerc.setSize(width, height);
	buttonMerc.setPosition(xPosB, yPosZero);

	buttonVenu.setBackgroundColor(backColor);
	buttonVenu.setTextColor(texColor);
	buttonVenu.setup(" Venus", false);
	buttonVenu.setSize(width, height);
	buttonVenu.setPosition(xPosB, yPosZero + 40);

	buttonEart.setBackgroundColor(backColor);
	buttonEart.setTextColor(texColor);
	buttonEart.setup(" Earth", false);
	buttonEart.setSize(width, height);
	buttonEart.setPosition(xPosB, yPosZero + 80);

	buttonMars.setBackgroundColor(backColor);
	buttonMars.setTextColor(texColor);
	buttonMars.setup(" Mars", false);
	buttonMars.setSize(width, height);
	buttonMars.setPosition(xPosB, yPosZero + 120);

	buttonJupi.setBackgroundColor(backColor);
	buttonJupi.setTextColor(texColor);
	buttonJupi.setup(" Jupiter", false);
	buttonJupi.setSize(width, height);
	buttonJupi.setPosition(xPosB, yPosZero + 160);

	buttonSatu.setBackgroundColor(backColor);
	buttonSatu.setTextColor(texColor);
	buttonSatu.setup(" Saturn", false);
	buttonSatu.setSize(width, height);
	buttonSatu.setPosition(xPosB, yPosZero + 200);

	buttonUran.setBackgroundColor(backColor);
	buttonUran.setTextColor(texColor);
	buttonUran.setup(" Uranus", false);
	buttonUran.setSize(width, height);
	buttonUran.setPosition(xPosB, yPosZero + 240);

	buttonNept.setBackgroundColor(backColor);
	buttonNept.setTextColor(texColor);
	buttonNept.setup(" Neptune", false);
	buttonNept.setSize(width, height);
	buttonNept.setPosition(xPosB, yPosZero + 280);


	//BOOL TO TOOGLE DESCRIPTIONS OF PLANETS
	showDescMercury = false;
	showDescVenus = false;
	showDescEarth = false;
	showDescMars = false;
	showDescJupiter = false;
	showDescSaturn = false;
	showDescUranus = false;
	showDescNeptune = false;


	//STARS
	for (int i = 0; i < 700; i++) {
		xPos = ofRandom(-3000, 3000);
		yPos = ofRandom(-1500, 3000);
		zPos = ofRandom(-3000, 3000);
		size = ofRandom(0.05f, 1.5f);

		Star* s = new Star{ xPos, yPos, zPos, size };
		stars.push_back(s);
	}


	//LOADING 3D MODEL OF A SHIP TO USE AS OUR SHIPS HOLOGRAM
	ofxAssimpModelLoader tempModel;			//3D model Loader
	tempModel.loadModel("r.stl");			//Loading our Model
	shipHologram = tempModel.getMesh(0);	//Storing our model into an ofVboMesh object

	//LOADING SOUND'S
	cockPitSystemSfx.load("CockpitSfx.mp3");
	cockPitSystemSfx.setVolume(0.2);

	shipEngineSfx.load("shipEngineSfx.mp3");
	shipEngineSfx.setVolume(0.2);

	cockPitSystemSfx.setLoop(true); //Loops sound for continuous playback
	shipEngineSfx.setLoop(true);

	cockPitSystemSfx.play(); //Plays the sound effect
	shipEngineSfx.play();
}
//--------------------------------------------------------------

void ofApp::update() {
	// Camera rotation codes adapted from -> Source "https://forum.openframeworks.cc/t/simple-camera-positioning-and-lookat/19514/2"
	cam.orbitDeg(rotateLeftRight, 0, camDistance);
	cam.rollDeg(roll);
	shipxRot += 2;
	shipyRot += 2;
	shipzRot += 2;


	if (spaceshipSwitch == true) {
		//SETTING THE CAMERA SO WE CAN SEE THE PLANET WE'RE READING ABOUT
		if (showDescMercury == 1) {
			ofVec3f merc = Mercury.getPlanetPosition();
			cam.setPosition(merc.x + 15, merc.y - 1, merc.z + 38);   // *30 CAUSE RADIUS * 10
			cam.lookAt(ofVec3f(merc.x, merc.y, merc.z));
		}
		else if (showDescVenus == 1) {
			ofVec3f venu = Venus.getPlanetPosition();
			cam.setPosition(venu.x + 15, venu.y - 3, venu.z + 95);
			cam.lookAt(ofVec3f(venu.x, venu.y, venu.z));
		}
		else if (showDescEarth == 1) {
			ofVec3f eart = Earth.getPlanetPosition();
			cam.setPosition(eart.x + 15, eart.y - 2, eart.z + 100);
			cam.lookAt(ofVec3f(eart.x, eart.y, eart.z));
		}
		else if (showDescMars == 1) {
			ofVec3f mar = Mars.getPlanetPosition();
			cam.setPosition(mar.x + 15, mar.y - 2, mar.z + 53);
			cam.lookAt(ofVec3f(mar.x, mar.y, mar.z));
		}
		else if (showDescJupiter == 1) {
			ofVec3f jupi = Jupiter.getPlanetPosition();
			cam.setPosition(jupi.x + 15, jupi.y - 2, jupi.z + 500);
			cam.lookAt(ofVec3f(jupi.x, jupi.y, jupi.z));
		}
		else if (showDescSaturn == 1) {
			ofVec3f satr = Saturn.getPlanetPosition();
			cam.setPosition(satr.x + 15, satr.y - 2, satr.z + 380);
			cam.lookAt(ofVec3f(satr.x, satr.y, satr.z));
		}
		else if (showDescUranus == 1) {
			ofVec3f uran = Uranus.getPlanetPosition();
			cam.setPosition(uran.x + 15, uran.y - 2, uran.z + 200);
			cam.lookAt(ofVec3f(uran.x, uran.y, uran.z));
		}
		else if (showDescNeptune == 1) {
			ofVec3f nept = Neptune.getPlanetPosition();
			cam.setPosition(nept.x + 15, nept.y - 2, nept.z + 220);
			cam.lookAt(ofVec3f(nept.x, nept.y, nept.z));
		}

	}
	else {
		showDescMercury = false, showDescVenus = false, showDescEarth = false, showDescMars = false, showDescJupiter = false, showDescSaturn = false, showDescUranus = false, showDescNeptune = false;
	}

	//BOOL TO SET IN ONE POSITION ALL OF THE PLANETS
	if (oneLineSwitch == true) {
		Mercury.oneLineON();
		Venus.oneLineON();
		Earth.oneLineON();
		Mars.oneLineON();
		Jupiter.oneLineON();
		Saturn.oneLineON();
		Uranus.oneLineON();
		Neptune.oneLineON();
	}
	else if (oneLineSwitch == false) {
		Mercury.oneLineOFF();
		Venus.oneLineOFF();
		Earth.oneLineOFF();
		Mars.oneLineOFF();
		Jupiter.oneLineOFF();
		Saturn.oneLineOFF();
		Uranus.oneLineOFF();
		Neptune.oneLineOFF();
	}

	r -= 0.132;//MOON Movements speed around Sun
	v += 4;//MOON Movement Speed Around Earth
}

//-------------------------------------------------------------
void ofApp::draw() {	

	cam.begin();
	ofEnableLighting();
	ofEnableDepthTest();
	ofRotateXDeg(rotateUpDown);
	ofEnableNormalizedTexCoords();
	light.enable();

	//STARS
	for (Star* s : stars) {
		s->draw();
	}

	//SUN
	sun.draw();
	sun.setTexture(sunTex);

	//MERCURY
	Mercury.draw();
	Mercury.setTexture(merTex);

	//VENUS
	Venus.draw();
	Venus.setTexture(venTex);

	//EARTH
	Earth.draw();
	Earth.setTexture(earthTex);

	//MOON
	ofPushMatrix();
	ofTranslate(0, 0, 0);
	ofPushMatrix();
	if (oneLineSwitch == true) {// Stops MOON from moving around SUN when Earth is not Moving
		ofRotateYDeg(0);
	}
	else {
		ofRotateYDeg(r);
	}
	ofTranslate(480, 0, 0);
	ofPushMatrix();
	ofRotateYDeg(v); //Rotate Moon Around Earths Orbit;
	moon.porbit(500, 0, 10, { 20,0,0 });//SETTING UP MOON's ORBIT AROUND EARTH
	moon.draw();
	moon.setTexture(moonTex);
	ofPopMatrix();
	ofPopMatrix();
	ofPopMatrix();

	//MARS
	Mars.draw();
	Mars.setTexture(marTex);

	//JUPITER
	Jupiter.draw();
	Jupiter.setTexture(jupTex);

	//SATURN
	Saturn.draw();
	Saturn.setTexture(satTex);
	Saturn.drawRing(8, 25, 0.2, ofColor(217, 173, 160, 50), 10); //SATURN'S RING

	//URANUS
	Uranus.draw();
	Uranus.setTexture(uraTex);

	//NEPTUNE
	Neptune.draw();
	Neptune.setTexture(nepTex);

	//ORBITS
	//setting the orbits so they can be turn on only if the descriptions are not showed
	if (showDescMercury == 0 && showDescVenus == 0 && showDescEarth == 0 && showDescMars == 0 && showDescJupiter == 0 && showDescSaturn == 0 && showDescUranus == 0 && showDescNeptune == 0) {
		if (orbitSwitch == true) {
			Mercury.drawOrbit();
			Venus.drawOrbit();
			Earth.drawOrbit();
			Mars.drawOrbit();
			Jupiter.drawOrbit();
			Saturn.drawOrbit();
			Uranus.drawOrbit();
			Neptune.drawOrbit();
		}
	}

	//BLACK HOLE
	ofPushMatrix();
	ofTranslate(1100, 0, -6000);
	BlackHole.draw();
	ofPopMatrix();

	ofDisableNormalizedTexCoords();
	ofDisableDepthTest();
	light.disable();
	ofDisableLighting();
	cam.end();


//OUTSIDE THE CAMERA

	//COCKPIT
	ofEnableAlphaBlending();
	ofSetColor(255);
	ofFill();
	
	//LOGIC TO DRAW THE RIGHT INSTRUCTIONS, AND ENABLE OR DISABLE SOME OF THE FUNCTIONS
	if(spaceshipSwitch == true) {
		spaceship.draw(0, 0, ofGetWidth(), ofGetHeight());
		drawUIButtons();
		ofPushMatrix();
		descTexts();
		ofPopMatrix();
		updateUI();

		ofPushMatrix();
		ofTranslate(ofGetWidth() / 2.04, ofGetHeight() / 1.28);
		ofRotateXDeg(shipxRot);		//rotation of the spaceship hologram
		ofRotateYDeg(shipyRot);		//rotation of the spaceship hologram
		ofRotateZDeg(shipzRot);		//rotation of the spaceship hologram
		ofSetColor(0, 255, 200, 100);
		ofFill();
		shipHologram.draw();
		ofPopMatrix();

		rotateUpDown = 0;		//disable rotating up/down so the world coordinates are not changing, so then cam.lookAt works properly
		roll = 0;				//disable roll function so the world coordinates are not changing, so then cam.lookAt works properly

		if (buttonInstruction == true && (showDescMercury == 1 || showDescVenus == 1 || showDescEarth == 1 || showDescMars == 1 || showDescJupiter == 1 || showDescSaturn == 1 || showDescUranus == 1 || showDescNeptune == 1)){
			instruction.drawDescription(2);
		}
	}
	else if (spaceshipSwitch == false) {
		if (buttonInstruction == true) {
			instruction.drawDescription(3);
		}
	}
	
	buttonInstruction.draw();	//drawing the instruction button, outside camera so it's always visable

	if (spaceshipSwitch == true) {
		if (showDescMercury == 0 && showDescVenus == 0 && showDescEarth == 0 && showDescMars == 0 && showDescJupiter == 0 && showDescSaturn == 0 && showDescUranus == 0 && showDescNeptune == 0) {
				if (buttonInstruction == true) {
					instruction.drawDescription(1);
				}
		}
	}
	ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::descTexts() { //function to store the descriptions

	ofDrawBitmapString("Planet Description", ofGetWidth() / 1.18, ofGetHeight() / 3.2);

	ofPushMatrix();
	ofSetColor(65, 244, 190);
	if (showDescMercury == 1) {
		descriptionTokenizer("Mercury, the first planet#of our Solar System. Hence#the hottest.Situated at about#57.91 million kilometres from the#Sun.It is the second most dense#planet of the Solar System, since 70%#of this planet is made of Metallic and#Silicatematerial.It takes 87.97 Earth days#to complete one rotation around the sun.#However days in mercury are terrible long#since it rotates extremely slow on its own#axis It was named after the Roman messenger#god Mercury.");
	}
	else if (showDescVenus == 1) {
		descriptionTokenizer("Venus the second planet in#our Solar System. Also known#as Earth’s sister planet due to#its similar size to Earth. It has#an atmosphere that consists of 96.5%#Carbon Dioxide and 3.5% Nitrogen. It is#108.2 million km far from our Sun, but #still heats up to 460°C during both day and#night. It’s tilted poles are the reason behind#the consistency of heat. A full rotation#of Venus around the Sun takes about 225 Earth#days. However a Single day on Venus is equal to 117#Earth Days.");
	}
	else if (showDescEarth == 1) {
		descriptionTokenizer("Our home planet Earth is#the third planet in the Solar#System. It is the only planet#capable or have the right#conditions for sustaining life.#Earth’s atmosphere is made up of 78%#Nitrogen 21% oxygen and trace amounts#of carbon dioxide, neon, helium, methane,#krypton, hydrogen, nitrous oxide, xenon,#ozone, iodine, carbon, monoxide and ammonia.#The average temperature on the surface of Earth#is around 14°C. A year on Earth consists of 365 days#which are 24h long.#");
	}
	else if (showDescMars == 1) {
		descriptionTokenizer("Mars is the 4th planet in#the Solar System and the only#planet apart from Earth considered#to have had held life in it and#what is more, shows the potential to#be repopulated with life due to the#atmospheric environment. At its current#state cannot sustain life as Earth does,#but the traces of certain bacteria fossils#and water is keeping the hopes up for the#scientists to spend time on the planet.#Temperature on Mars can reach up to 20°C during#the day time andabout -153°C during the night time.#Years on Mars are equal to 687 Earth days.");
	}
	else if (showDescJupiter == 1) {
		descriptionTokenizer("Jupiter is the largest #planet in our Solar System.#Unlike the the first four#planets of our Solar System,#starting from Jupiter the rest of#the planets are Gas Giants, meaning#that the planets have mostly gas on#surface with a relatively tiny solid core.#Jupiter is big enough to fit 1300 planets#the size of Earth in it. Temperature ranges#from 4° C to -128°C due to being about 778.5mln km#from the Sun and being composed of mostly gases.#Days in Jupiter are 10h long and years are equal to#12 Earth Years.");
	}
	else if (showDescSaturn == 1) {
		descriptionTokenizer("Saturn is the second gas#giant in our Solar System. It# is about 1.434 billion km away#from the Sun. It is made up of#mostly hydrogen and helium as well#with trace amount of methane and#ammonia. Saturn has a ring consisting#of rocks sizing from a grain of salt to#the size of a mountain spinning around the#planet.Saturn’s surface temperature is ranges#from about -113° to -173°C. Days are 10 hours long#and years are equal to 29 Earth years, due to being#so far from the Sun.");
	}
	else if (showDescUranus == 1) {
		descriptionTokenizer("Uranus is the 3rd gas giant#in our Solar System. It is also#a ringed planet however its ring#is barely visible and very thin#compared to Saturn’s. Uranus is a#frozen gaseous planet with a molten#core. Uranus' atmosphere consists of#83% hydrogen, 15% helium and 2% methane.#The surface temperature of this planet is#-224°C. Days in Uranus are 17h long on Earth#and a year on the planet is about 87 years on#Earth. Basically a lifetime of an average person.");
	}
	else if (showDescNeptune == 1) {
		descriptionTokenizer("Neptune is the last planet#of our Solar System. It is#about 4.495 billion km away#from the Sun making it the#coldest planet of our Solar System#at present. Temperature on the surface#ranges from -218 °C -200 °C. The planet is#composed of 80% Hydrogen, 19% Helium,#and 1.5% Methane. Days on Neptune are 16h#long on Earth. However, a year on Neptune is#equal to 165 years on earth. Only the luckiest#would have been able to enjoy the New Year’s if#life was to exist on that planet.");
	}
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::drawUIButtons() {
	buttonMerc.draw();
	buttonVenu.draw();
	buttonEart.draw();
	buttonMars.draw();
	buttonJupi.draw();
	buttonSatu.draw();
	buttonUran.draw();
	buttonNept.draw();
}
//--------------------------------------------------------------
void ofApp::updateUI() {
	if (buttonMerc == true) {
		showDescMercury = true;
		showDescVenus = false, showDescEarth = false, showDescMars = false, showDescJupiter = false, showDescSaturn = false, showDescUranus = false, showDescNeptune = false;
	}
	if (buttonVenu == true) {
		showDescVenus = true;
		showDescMercury = false, showDescEarth = false, showDescMars = false, showDescJupiter = false, showDescSaturn = false, showDescUranus = false, showDescNeptune = false;
	}
	if (buttonEart == true) {
		showDescEarth = true;
		showDescMercury = false, showDescVenus = false, showDescMars = false, showDescJupiter = false, showDescSaturn = false, showDescUranus = false, showDescNeptune = false;
	}
	if (buttonMars == true) {
		showDescMars = true;
		showDescMercury = false, showDescVenus = false, showDescEarth = false, showDescJupiter = false, showDescSaturn = false, showDescUranus = false, showDescNeptune = false;
	}
	if (buttonJupi == true) {
		showDescJupiter = true;
		showDescMercury = false, showDescVenus = false, showDescEarth = false, showDescMars = false, showDescSaturn = false, showDescUranus = false, showDescNeptune = false;
	}
	if (buttonSatu == true) {
		showDescSaturn = true;
		showDescMercury = false, showDescVenus = false, showDescEarth = false, showDescMars = false, showDescJupiter = false, showDescUranus = false, showDescNeptune = false;
	}
	if (buttonUran == true) {
		showDescUranus = true;
		showDescMercury = false, showDescVenus = false, showDescEarth = false, showDescMars = false, showDescJupiter = false, showDescSaturn = false, showDescNeptune = false;
	}
	if (buttonNept == true) {
		showDescNeptune = true;
		showDescMercury = false, showDescVenus = false, showDescEarth = false, showDescMars = false, showDescJupiter = false, showDescSaturn = false, showDescUranus = false;
	}
}

//-------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key) {
	case 'd':
	case 'D':
		rotateLeftRight += 2;
		break;
	case 'a':
	case 'A':
		rotateLeftRight -= 2;
		break;
	case 'e':
	case 'E':
		if (spaceshipSwitch == false) {
			roll += 2;
		}
		else { roll = 0; }
		break;
	case 'q':
	case 'Q':
		if (spaceshipSwitch == false) {
			roll -= 2;
		}
		else { roll = 0; }
		break;
	case 'w':
	case 'W':
		if (spaceshipSwitch == true) {			//The world is not rotating, because cam coords or planet cords are not changing, while xRotation, so it's difficult to calculate anything 
			rotateUpDown += 0;
		}
		else {
			rotateUpDown += 5;
		}
		break;
	case 's':
	case 'S':
		if (spaceshipSwitch == true) {
			rotateUpDown += 0;
		}
		else {
			rotateUpDown -= 5;
		}
		break;
	case OF_KEY_UP:
		camDistance = MAX((camDistance -= 5), 500);		 //Sets max Zoom-in Distance so you don't get sucked in by the Sun's gravity :D
		break;
	case OF_KEY_DOWN:
		camDistance = (camDistance += 5);
		break;
	case 'o':
	case 'O':
		if (orbitSwitch == true) {
			orbitSwitch = false;
		}
		else if (orbitSwitch == false) {
			orbitSwitch = true;
		}
		break;
	case 'u':
	case 'U':
		if (spaceshipSwitch == true) {
			spaceshipSwitch = false;
			cockPitSystemSfx.stop();	//Stops CockPitSystemSfx sound when UI is OFF
		}
		else if (spaceshipSwitch == false) {
			spaceshipSwitch = true;
			cockPitSystemSfx.play(); //Starts CockPitSystemSfx sound back ON when UI is ON
		}
		break;
	case 'l':
		if (oneLineSwitch == true) {
			oneLineSwitch = false;
		}
		else if (oneLineSwitch == false) {
			oneLineSwitch = true;
		}
		break;
	}
}

//--------------------------------------------------------------
//DESCRIPTION TOKENIZER FUNCTION
void ofApp::descriptionTokenizer(string description) { // WE LEARNED ABOUT THE TOKENIZER IN A C++ LAB
	string tempString = description; //Loads passed string to a temporary string
	vector<string> splitString = ofSplitString(tempString, "#");//Splits the string at given Splitting points
	//change for loop to sth else
	
	for (int i = 0; i < splitString.size(); i++) {
		ofPushMatrix();
		ofTranslate(ofGetWidth() / 1.23, ofGetWindowHeight() / 2.7);
		ofDrawBitmapString(splitString[i], ofGetWidth() / 1.26* (i*-0.015), (ofGetHeight() / 2.7)* (i*0.05));
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

