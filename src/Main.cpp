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
    cout << "Test shiftRight() - should be: 1" << endl << endl;

    vm.shiftLeft();
    cout << vm.getMemoryPointer() << endl;
    cout << "Test shiftLeft() - should be: 0" << endl << endl;

    vm.shiftLeft();
    cout << vm.getMemoryPointer() << endl;
    cout << "Test shiftLeft() 2 - should be: 0" << endl << endl;

    vm.increment();
    char val = vm.readValue();
    cout << (int)val << endl;
    cout << "Test increment() - should be: 1" << endl << endl;

    vm.decrement();
    val = vm.readValue();
    cout << (int)val << endl;
    cout << "Test decrement() - should be: 0" << endl << endl;

    val = 'a';
    vm.loadValue(val);
    val = vm.readValue();
    cout << val << endl;
    cout << "Test loadValue() - should be: a" << endl << endl;

    return 0;
}
