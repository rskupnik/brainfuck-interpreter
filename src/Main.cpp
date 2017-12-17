#include <iostream>
#include "Interpreter.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    cout << "Hello World" << endl;    

    Interpreter interpreter;
    char input = '.';
    Command cmd = interpreter.interpret(&input);

    cout << cmd << endl;

    return 0;
}
