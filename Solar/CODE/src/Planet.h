#ifndef PLANET_H
#define PLANET_H
#include "ofMain.h"

class Planet {
	public:
		//x: x-axis, y: y-axis, z: z-axis, s: radius, rs: rotate speed, 
		Planet(float x, float y, float z, float s, float rs);
		void draw();
		void setTexture(ofImage& _texture);
		void update();
		void torus(int numc, int numt, float div);
		void drawRing(int numc, int numt, float div, ofColor color, float degrees);
		void drawOrbit();
		void oneLineON();
		void oneLineOFF();
		ofVec3f getPlanetPosition();

	private:
		float xPos;
		float yPos;
		float zPos;
		float radius;
		float rotate_speed;
		float s;

		ofImage tex;
		ofSpherePrimitive sphere;
		ofMaterial terraMat;

		//Updating planets positions
		ofPoint point;
		float ang;
		float cosine;
		float sine;

		bool line;
};
#endif PLANET_H