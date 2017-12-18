#include <iostream>
#include "Interpreter.h"
#include "VirtualMachine.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    cout << "Hello World" << endl;    

    //Interpreter interpreter;
    //char input = '.';
    //Command cmd = interpreter.interpret(input);
    //cout << cmd << endl;

    VirtualMachine vm;
    vm.shiftRight();
    cout << vm.getMemoryPointer() << endl;

    return 0;
}
