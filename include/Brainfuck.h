#pragma once

#include "Interpreter.h"
#include "VirtualMachine.h"
#include "Command.h"
#include <vector>
#include <string>

class Brainfuck {
    public:
        void execute(std::string);

    private:
	Interpreter interpreter;
	VirtualMachine vm;

	std::vector<Command> translate(std::string);
};
