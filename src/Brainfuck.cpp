#include "Brainfuck.h"
#include <iostream>

using namespace std;

void Brainfuck::execute(char program[]) {
    Command commands[] = {};
    commands = translate(program);
    for (int i = 0; i < sizeof(commands)/sizeof(*commands); i++) {
	cout << commands[i];
    }
    return;
}

Command* Brainfuck::translate(char program[]) {
    Command output[sizeof(program)];
    for (int i = 0; i < sizeof(program); i++) {
        char c = program[i];
	output[i] = this->interpreter.interpret(c);
    }
    return output;
}
