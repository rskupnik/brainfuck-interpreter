#pragma once

#include "Interpreter.h"
#include "VirtualMachine.h"
#include "Command.h"
#include <vector>
#include <string>

class Brainfuck {
    public:
        void executeProgram(const std::string&);

    private:
	Interpreter interpreter;
	VirtualMachine vm;

	std::vector<Command> translate(const std::string&);
	void executeCommand(const Command&);
};
