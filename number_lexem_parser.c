#include "number_lexem_parser.h"
#include "helpers.h"
#include <ctype.h>

typedef enum {
    INITIAL,
    MAYBE_HEX,
    HEX_PREFIX,
    DECIMAL,
    HEX,
    FINISH_STATES,
    F_DECIMAL,
    F_HEX,
    F_FAILED
} NumbericLexemState;


Lexem* read_number_lexem(FILE* file) {
    int c;
    NumbericLexemState state = INITIAL;
    Lexem* lexem = empty_lexem();

    while (1)
    {
        c = fpeek(file);
        switch (state)
        {
        case INITIAL:
            if(c == '0') {
                state = MAYBE_HEX;
            } else if(isdigit(c)) {
                state = DECIMAL;
            } else {
                state = F_FAILED;
            }
            break;
        case MAYBE_HEX:
            if(c == 'x' || c == 'X') {
                state = HEX_PREFIX;
            } else if (!isalpha(c)) {
                state = F_DECIMAL;
            } else {
                state = F_FAILED;
            }
            break;    
        case DECIMAL:
            if(isdigit(c)) {
                break;
            }
            if(!isalpha(c)) {
                state = F_DECIMAL;
            } else {
                state = F_FAILED;
            }
            break;
        case HEX_PREFIX:
            if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' 
            || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F'
            || isdigit(c)) {
                state = HEX;
                break;
            }
            state = F_FAILED;
            break;
        case HEX:
            if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' 
            || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F'
            || isdigit(c)) {
                break;
            }
            if(!isalpha(c)) {
                state = F_HEX;
            } else {
                state = F_FAILED;
            }
            break;
        default:
            return NULL;

        }
        if(state > FINISH_STATES) {
            break;
        }
        add_letter_to_str(lexem->name, c);
        fgetc(file);
    }

    if(state == F_HEX) {
        lexem->type = NUMERIC_LITERAL_HEX;
    } else if (state == F_DECIMAL) {
        lexem->type = NUMERIC_LITERAL_DECIMAL;
    } else {
        lexem->type = FAILED;
    }

    return lexem;
}
