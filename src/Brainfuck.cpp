#include "Brainfuck.h"
#include "Loop.h"
#include <iostream>
#include <stack>

using namespace std;

stack<Loop> loops;
map<int, Loop> foundLoops;
Loop currentLoop = 0;

void findLoops(map<int, Command>&);

void Brainfuck::setProgramCounter(const int val) {
    this->programCounter = val;
}

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
    //map<int, Command>::iterator it;
    //for (it = commands.begin(); it != commands.end(); it++) {
//	int instructionNumber = it->first;
//	Command c = it->second;
//	this->executeCommand(instructionNumber, c);
    //}
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
	    cout << "Shuffled right, memory pointer is now " << this->vm.getMemoryPointer() << endl << endl;
	    break;
	case SHIFT_LEFT:
	    this->vm.shiftLeft();
	    cout << "Shuffled left, memory pointer is now " << this->vm.getMemoryPointer() << endl << endl;
	    break;
	case INCREMENT:
	    this->vm.increment();
	    cout << "Incremented value at pointer " << this->vm.getMemoryPointer() << " to value " << ((int) this->vm.readValue()) << endl << endl;
	    break;
	case DECREMENT:
	    this->vm.decrement();
	    cout << "Decremented value at pointer " << this->vm.getMemoryPointer() << " to value " << ((int) this->vm.readValue()) << endl << endl;
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
	    cout << "Found a loop that starts at " << loop.loopStartPosition << " and ends at " << loop.loopEndPosition << endl << endl; 
	    val = this->vm.readValue();
	    cout << "Val is: " << ((int) val) << " and was read at memoyr pointer " << this->vm.getMemoryPointer() << endl << endl;
	    if (val == 0) {
		this->programCounter = loop.loopEndPosition + 1;
		cout << "Set program counter to point to " << this->programCounter << endl << endl;
	    }
	    currentLoop = loop;
	    break;
	}
	case LOOP_END: {
	    Loop loop2 = currentLoop;
	    val = this->vm.readValue();
	    cout << "End of loop found, val is: " << ((int) val) << " and was read at memory pointer " << this->vm.getMemoryPointer()  << endl << endl;
	    if (val != 0) {
		this->programCounter = loop2.loopStartPosition;
		cout << "Set memory pointer to " << this->programCounter << endl << endl;
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
		cout << "Identified start of loop at " << pos << endl << endl;
  	        loops.push(Loop(pos));
		break;
	    case LOOP_END:
		Loop loop = loops.top();
		loops.pop();
		loop.loopEndPosition = pos;
		foundLoops[loop.loopStartPosition] = loop;
		cout << "Identified end of loop at " << pos << endl << endl;
		break;
	}
    }
}
