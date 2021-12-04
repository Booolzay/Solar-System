#ifndef BLACKHOLE_H
#define BLACKHOLE_H

#include "ofMain.h"
#include "ofMath.h" 

using namespace glm;

class BlackHole {
	public:
		BlackHole(float posX, float posY, float posZ, float radius);
		virtual void draw();
		void initSpiroMesh(ofMesh &curMesh, float r);
		void updateSpiroMesh(ofMesh &curMesh, float r, float rMult, int freqMult, float phase);

	private:
		float xPos;
		float yPos;
		float zPos;
		float size;
		int numSegments;
		ofMesh myMesh;
		ofSpherePrimitive hole;
};
#endif

