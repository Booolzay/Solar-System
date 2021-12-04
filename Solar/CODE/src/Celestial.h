#ifndef CELESTIAL_H
#define CELERSIAL_H

#include "ofMain.h"
class Celestial {
	public:
		Celestial(float posX, float posY, float posZ, float radius);
		void draw();
		void setTexture(ofImage& _texture);

	private:
		ofImage texture;
		ofSpherePrimitive body;
		ofMaterial sunMat;

		float xPos;
		float yPos;
		float zPos;
		float size;
};
#endif //CELESTIAL_H

