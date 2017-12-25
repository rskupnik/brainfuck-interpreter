#pragma once

class Loop {
    public:
	int loopStartPosition;
	int loopEndPosition;
	int counterPointer;

	Loop(int start, int counterPtr) : loopStartPosition(start), counterPointer(counterPtr) {}
};
