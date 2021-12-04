#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "ofMain.h"

class Instruction {
	public:
		Instruction();
		void drawDescription(int a);

	private:
		float xPos;
		float yPos;
};
#endif //INSTRUCTION_H