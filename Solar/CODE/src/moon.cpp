#include "moon.h"
#include "ofMain.h"

Moon::Moon(float x, float y, float z, float s) {
	xPos = x;
	yPos = y;
	zPos = z;
	radius = s;

	moonMat.setDiffuseColor(ofFloatColor(0.8f, 0.8f, 0.8f));
	sphere.setResolution(100);
	sphere.setPosition(xPos, yPos, zPos);
	sphere.setRadius(s);
}

void Moon::draw() {

	moonMat.begin();
	if (tex.getWidth() > 0) {
		tex.getTexture().bind();
		ofRotateYDeg(rd);
		sphere.draw();
		tex.getTexture().unbind();
	}
	else {
		sphere.draw();
	}
	moonMat.end();
}

void Moon::setTexture(ofImage& _texture) {
	tex = _texture;
}

void Moon::porbit(float longitude, float latitude, float radius, ofVec3f moonOrbitCenter) {
	lo = longitude;
	la = latitude;
	ra = radius;
	vax = moonOrbitCenter;
}