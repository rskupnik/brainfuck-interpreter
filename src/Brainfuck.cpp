#include "Brainfuck.h"
#include "Loop.h"
#include <iostream>
#include <stack>

using namespace std;

stack<Loop> loops;		// Used two times - once on the loop finding stage and once during command processing
map<int, Loop> foundLoops;	// Stores the result of loop finding stage - the key is the index of the start of the loop

void findLoops(map<int, Command>&);

void Brainfuck::executeProgram(const string& program) {
    map<int, Command> commands = translate(program);
    findLoops(commands);
    while (true) {
	int pc = this->programCounter;
	if (pc >= commands.size()) {
	    this->programCounter = 0;
	    break;
	}
	Command c = commands[pc];
	this->executeCommand(pc, c);
	this->programCounter++;
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
	case LOOP_START: {
	    Loop loop = foundLoops[instructionNumber];
	    val = this->vm.readValue();
	    if (val == 0) {
		this->programCounter = loop.loopEndPosition;
	    } else {
	        loops.push(loop);
	    }
	    break;
	}
	case LOOP_END: {
	    Loop loop2 = loops.top();
	    val = this->vm.readValue();
	    if (val != 0) {
		this->programCounter = loop2.loopStartPosition;
	    } else {
	        loops.pop();
	    }
	    break;
	}
    }

    return;
}

void findLoops(map<int, Command>& commands) {
    map<int, Command>::iterator it;
    for (it = commands.begin(); it != commands.end(); it++) {
	int pos = it->first;
	Command cmd = it->second;
	switch (cmd) {
	    case LOOP_START:
  	        loops.push(Loop(pos));
		break;
	    case LOOP_END:
		Loop loop = loops.top();
		loops.pop();
		loop.loopEndPosition = pos;
		foundLoops[loop.loopStartPosition] = loop;
		break;
	}
    }
}
