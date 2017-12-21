#pragma once

#include "Interpreter.h"
#include "VirtualMachine.h"
#include "Command.h"

class Brainfuck {
    public:
        void execute(char*);

    private:
	Interpreter interpreter;
	VirtualMachine vm;

	Command* translate(char*);
};
