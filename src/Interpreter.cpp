#include "Interpreter.h"

Command Interpreter::interpret(char symbol) {
    Command output;

    switch (symbol) {
        case '>':
            return SHIFT_RIGHT;
        case '<':
            return SHIFT_LEFT;
        case '+':
            return INCREMENT;
        case '-':
            return DECREMENT;
        case '.':
	    return OUTPUT;
        case ',':
	    return INPUT;
        case '[':
	    return LOOP_START;
        case ']':
	    return LOOP_END;
        default:
            return UNKNOWN;
    }
}
