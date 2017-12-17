#include <iostream>
#include "Interpreter.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    cout << "Hello World" << endl;    

    Interpreter interpreter();
    Command cmd = interpreter.interpret(argv[]);

    cout << cmd << endl;

    return 0;
}
