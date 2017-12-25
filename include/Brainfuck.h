#pragma once

#include "Interpreter.h"
#include "VirtualMachine.h"
#include "Command.h"
#include <map>
#include <string>

class Brainfuck {
    public:
        void executeProgram(const std::string&);

    private:
	Interpreter interpreter;
	VirtualMachine vm;

	std::map<int, Command> translate(const std::string&);
	void executeCommand(const int, const Command&);
};
