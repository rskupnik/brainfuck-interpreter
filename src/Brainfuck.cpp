#include "Brainfuck.h"
#include "Loop.h"
#include <iostream>
#include <stack>

using namespace std;

stack<Loop> loops;

void Brainfuck::executeProgram(const string& program) {
    map<int, Command> commands = translate(program);
    map<int, Command>::iterator it;
    for (it = commands.begin(); it != commands.end(); it++) {
	int instructionNumber = it->first;
	Command c = it->second;
	this->executeCommand(instructionNumber, c);
    }
    return;
}

map<int, Command> Brainfuck::translate(const string& program) {
    map<int, Command> output;
    for (int i = 0; i < program.length(); i++) {
	char c = program[i];
	Command cmd = this->interpreter.interpret(c);
	output[i] = cmd;
    }
    return output;
}

void Brainfuck::executeCommand(const int instructionNumber, const Command& cmd) {
    char val;
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
	    val = this->vm.readValue();
	    cout << val;
	    break;
	case INPUT:
	    cin >> val;
	    this->vm.loadValue(val);
	    break;
	case LOOP_START:
	    loops.push(Loop(instructionNumber, this->vm.getMemoryPointer())); 
	    break;
	case LOOP_END:
	    Loop loop = loops.top();
	    loops.pop();
	    loop.loopEndPosition = instructionNumber;
	    break;
    }

    return;
}
