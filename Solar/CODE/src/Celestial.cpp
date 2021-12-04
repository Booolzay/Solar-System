#include "Celestial.h"

Celestial::Celestial(float posX, float posY, float posZ, float radius){

	xPos = posX;
	yPos = posY;
	zPos = posZ;
	size = radius;
	sunMat.setEmissiveColor(255);
	body.setPosition(xPos, yPos, zPos);
	body.setResolution(500);
	body.setRadius(size);
}

void Celestial::draw() {
	
	sunMat.begin();
	if (texture.getWidth() > 0) {   //if the texture being load
		texture.getTexture().bind();
		body.draw();
		texture.getTexture().unbind();
	}
	else {							
		body.draw();				//if there is no texture just draw default sphere
	}
	sunMat.end();
}

void Celestial::setTexture(ofImage& _texture){
	texture = _texture;
}