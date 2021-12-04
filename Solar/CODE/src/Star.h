#ifndef STAR_H
#define STAR_H

#include "ofMain.h"

class Star {
	public:
		Star(float x, float y, float z, float s);
		void draw();

	private:
		float xPos;
		float yPos;
		float zPos;
		float size;

		ofSpherePrimitive sphere;
		ofMaterial material;
	};

#endif //STAR_H

