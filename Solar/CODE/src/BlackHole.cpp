#include "BlackHole.h"

BlackHole::BlackHole(float posX, float posY, float posZ, float radius){

	xPos = posX;
	yPos = posY;
	zPos = posZ;
	size = radius;

	hole.setPosition(xPos, yPos, zPos);
	hole.setResolution(500);
	hole.setRadius(size);
	numSegments = 1500;

	initSpiroMesh(myMesh, 200.0f);//excessive memory usage when was called in draw
}

void BlackHole::draw() {
	ofTranslate(0.5f * ofGetWidth(), 0.5f * ofGetHeight());
	ofSetColor(0);
	ofFill();
	hole.draw();
	ofRotateXDeg(120);
	
	myMesh.draw();
	
	float time = ofGetElapsedTimef();
	float phase = 20.0f * time;
	updateSpiroMesh(myMesh, 200.0f, 0.5, 8, phase);
}

void BlackHole::initSpiroMesh(ofMesh &curMesh, float r) {
	curMesh.setMode(OF_PRIMITIVE_TRIANGLES);

	// Add vertices around the circumference
	for (int i = 0; i < numSegments; i++) {
		float theta = 360.0f * i / numSegments;
		float x = r * sin(ofDegToRad(theta));
		float y = r * cos(ofDegToRad(theta));
		curMesh.addVertex(vec3(x, y, 0));
		ofColor curColor;
		curColor.setHsb(theta * 5 / 360, 5, 5);
		curMesh.addColor(curColor);
	}
	// Add central vertex
	curMesh.addVertex(vec3(0, 0, -100));
	// Get the index of the central vertex
	int vIndexCentre = curMesh.getNumVertices() - 1;
	curMesh.addColor(ofColor::white);

	// Add the triangles using vertex indices
	for (int i = 0; i < numSegments; i++) {
		int vIndex0 = i;
		int vIndex1 = i + 1;
		if (vIndex1 >= numSegments) {
			vIndex1 = 0;
		}
		curMesh.addTriangle(vIndex0, vIndex1, vIndexCentre);
	}
}

void BlackHole::updateSpiroMesh(ofMesh &curMesh, float r, float rMult, int freqMult, float phase) {
	// Calculate new positions for the vertices around the circumference
	for (int i = 0; i < numSegments; i++) {
		float theta = 360.0f * i / numSegments;
		float x = r * sin(ofDegToRad(theta));
		float y = r * cos(ofDegToRad(theta));
		/*x += userC;
		y += userC;*/
		x += r * rMult * sin(ofDegToRad(freqMult * theta + phase));
		y += r * rMult * cos(ofDegToRad(freqMult * theta + phase));
		x += r * pow(rMult, 2) * sin(ofDegToRad(pow(freqMult, 2) * theta  + phase));
		y += r * pow(rMult, 2) * cos(ofDegToRad(pow(freqMult, 2) * theta  + phase));
		curMesh.setVertex(i, vec3(x, y, 0));
	}
}
