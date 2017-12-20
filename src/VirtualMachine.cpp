#include "VirtualMachine.h"

void VirtualMachine::shiftRight() {
    if (this->memoryPointer == VirtualMachine::MEMORY_SIZE - 1) {
        return;
    }

    this->memoryPointer++;
    
    return;
}

void VirtualMachine::shiftLeft() {
    if (this->memoryPointer == 0) {
	return;
    }

    this->memoryPointer--;

    return;
}

void VirtualMachine::increment() {
    this->memory[this->memoryPointer]++;
}

void VirtualMachine::decrement() {
    this->memory[this->memoryPointer]--;
}

char VirtualMachine::readValue() {
    return this->memory[this->memoryPointer];
}

void VirtualMachine::loadValue(char val) {
    this->memory[this->memoryPointer] = val;
}

int VirtualMachine::getMemoryPointer() {
    return this->memoryPointer;
}
