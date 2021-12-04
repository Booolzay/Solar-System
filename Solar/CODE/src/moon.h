#ifndef MOON_H
#define MOON_H

#include "ofMain.h"

class Moon {
	public:
		Moon(float x, float y, float z, float s);
		void draw();
		void setTexture(ofImage& _texture);
		void porbit(float longitude, float latitude, float radius, ofVec3f moonOrbitCenter);

	private:
		float xPos;
		float yPos;
		float zPos;
		float radius;
		float rotate_speed;
		float s;
		float rd;
		ofImage tex;
		ofSpherePrimitive sphere;
		ofMaterial moonMat;

		float lo, la, ra; //Variables to store Longitude, latitude, radius for porbit function
		ofVec3f vax; //stores the co-ordinate for the centerpoint of the porbit function
};

#endif MOON_H

