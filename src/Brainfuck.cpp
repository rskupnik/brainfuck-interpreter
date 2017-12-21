#include "Brainfuck.h"
#include <iostream>

using namespace std;

void Brainfuck::execute(string program) {
    vector<Command> commands = translate(program);
    for (Command c : commands) {
	cout << c;
    }
    return;
}

vector<Command> Brainfuck::translate(string program) {
    vector<Command> output(1);
    cout << "Hello" << endl;
    cout << program.length() << endl;
    for (char c : program) {
	cout << c << endl;
//	Command cmd = this->interpreter.interpret(c);
	//cout << cmd << endl;
	//output.push_back(cmd);
    }
    return output;
}
