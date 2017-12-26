#pragma once

class Loop {
    public:
	int loopStartPosition;
	int loopEndPosition;
	int counterPointer;

	Loop(int start) : loopStartPosition(start) {}
	Loop() {}
};
