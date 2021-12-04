#include "Planet.h"
#include "ofMain.h"

Planet::Planet(float x, float y, float z, float s, float rs){
	xPos = x;
	yPos = y;
	zPos = z;
	radius = s;
	rotate_speed = rs;
	terraMat.setDiffuseColor(ofFloatColor(0.8f, 0.8f, 0.8f));
	sphere.setResolution(80);
	sphere.setRadius(s);

	cosine = 0;
	sine = 0;
	line = false;
}

void Planet::draw(){
	this->update();

	terraMat.begin();
		if (tex.getWidth() > 0) {		//if the texture being load
			tex.getTexture().bind();
			sphere.setPosition(point);
			sphere.draw();
			tex.getTexture().unbind();
		}
		else {
			sphere.draw();				//if there is no texture just draw default sphere
		}
		terraMat.end();	
}

void Planet::setTexture(ofImage& _texture){
	tex = _texture;
}

void Planet::update() { //function to rotate and update the positon of the planet
	ang += this->rotate_speed * 0.00001; //It's * 0.01 to set everything properly, we should change the rotation speed of planets in header file, but it is simpler to have one irrational number, than 8 of them =
	if (ang >= TWO_PI) {
		ang = 0;
	}
	 
	cosine = cos(ang);
	sine = sin(ang);

	if (line == false) {
		point.set(cosine * xPos, 0, sine * xPos);   //setting the updated position of the planet
		line = false;
	}
	else if (line == true) {
		point.set(xPos, yPos, zPos);				//while 'L' key pressed, set all of the planets in one line, beginning position
		line = true;
	}
}

void Planet::torus(int numc, int numt, float div){
// https://forum.openframeworks.cc/t/torus-not-displyed-solved/7242/3 <- CODE TO CREATE A TORUS

	int i, j, k;
	double s, t, x, y, z, twopi;

	twopi = 2 * PI;
	for (i = 0; i < numc; i++) {
		glBegin(GL_QUAD_STRIP);
		for (j = 0; j <= numt; j++) {
			for (k = 1; k >= 0; k--) {
				s = (i + k) % numc + 0.5;
				t = j % numt;
				x = (1 + .1*sin((s/div)*twopi / numc))*cos(t*twopi / numt);
				y = (1 + .1*sin((s/div)*twopi / numc))*sin(t*twopi / numt);
				z = .01 * sin(s * twopi / numc);
				glVertex3f(x, y, z);
			}
		}
		glEnd();
	}
}

void Planet::drawRing(int numc, int numt, float div, ofColor color, float degrees) {
	ofPushMatrix();
	
	ofSetColor(color);
	ofTranslate(point.x, point.y + 5, point.z); //so the ring moves with the planet
	ofRotateXDeg(90 + degrees);
	ofScale(70, 70);

	this->torus(numc, numt, div);

	ofPopMatrix();
}

void Planet::drawOrbit() {
	ofPushMatrix();

	ofRotateXDeg(90);
	ofSetColor(50, 50, 50, 150);
	ofScale(xPos, xPos);
	this->torus(16, 50, 120);

	ofPopMatrix();
}

ofVec3f Planet::getPlanetPosition(){    //function which returns the updated position of the planet
	return point;
}

void Planet::oneLineON() {
	line = true;
}

void Planet::oneLineOFF() {
	line = false;
}