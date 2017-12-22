#include "Brainfuck.h"
#include <iostream>

using namespace std;

void Brainfuck::executeProgram(const string& program) {
    vector<Command> commands = translate(program);
    for (int i = 0; i < commands.size(); i++) {
	Command c = commands[i];
	this->executeCommand(c);
    }
    return;
}

vector<Command> Brainfuck::translate(const string& program) {
    vector<Command> output(1);
    for (int i = 0; i < program.length(); i++) {
	char c = program[i];
	Command cmd = this->interpreter.interpret(c);
	output.push_back(cmd);
    }
    return output;
}

void Brainfuck::executeCommand(const Command& cmd) {
    switch (cmd) {
	case SHIFT_RIGHT:
	    this->vm.shiftRight();
	    break;
	case SHIFT_LEFT:
	    this->vm.shiftLeft();
	    break;
	case INCREMENT:
	    this->vm.increment();
	    break;
	case DECREMENT:
	    this->vm.decrement();
	    break;
	case OUTPUT:
	    char val = this->vm.readValue();
	    cout << val;
	    break;
	//case INPUT:
	    //char val = 0;
	    //val << cin;
	    //this->vm.loadValue(val);
	    //break;
    }

    return;
}
