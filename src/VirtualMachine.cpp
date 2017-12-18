#include "VirtualMachine.h"

void VirtualMachine::shiftRight() {
    if (this->memoryPointer == VirtualMachine::MEMORY_SIZE - 1) {
        return;
    }

    this->memoryPointer++;
    
    return;
}

int VirtualMachine::getMemoryPointer() {
    return this->memoryPointer;
}
