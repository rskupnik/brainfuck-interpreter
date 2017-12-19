#pragma once

class VirtualMachine {
    public:
        static const int MEMORY_SIZE = 100;

	VirtualMachine() : memory{0}, memoryPointer(0) {}

        void shiftRight();
	void shiftLeft();

	int getMemoryPointer();

    private:
        char memory[MEMORY_SIZE];
	int memoryPointer;

};
