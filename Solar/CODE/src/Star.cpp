#include "Star.h"

Star::Star(float x, float y, float z, float s){
	xPos = x;
	yPos = y;
	zPos = z;
	size = s;
	
	sphere.setResolution(4);
	sphere.setRadius(size);
	sphere.setPosition(xPos, yPos, zPos);
	material.setEmissiveColor(ofFloatColor(0.0f, 0.0f, 0.0f));
}

void Star::draw(){	
	material.begin();
	sphere.draw();
	material.end();
}

