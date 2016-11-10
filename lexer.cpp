#include <cstdio>
#include "lexer.h"

// Return the next token from standard input.
int get_token() {
    int last_char = getchar();
    
    while (true) {
        if (last_char == '<') return tok_left;      
        if (last_char == '>') return tok_right;        
        if (last_char == '.') return tok_output;        
        if (last_char == ',') return tok_input;        
        if (last_char == '+') return tok_increment;        
        if (last_char == '-') return tok_decrement;        
        if (last_char == '[') return tok_loop_begin;        
        if (last_char == ']') return tok_loop_end;        
        if (last_char == EOF) return tok_eof;
        
        // consume and ignore other characters
        last_char = getchar();
    }
}

char char_of_token(int token) {
    switch (token) {
        case tok_left: return '<';
        case tok_right: return '>';
        case tok_decrement: return '-';
        case tok_increment: return '+';
        case tok_input: return ',';
        case tok_output: return '.';
        case tok_loop_begin: return '[';
        case tok_loop_end: return ']';        
    }
    
    return '\0';
}

char *string_of_token(int token) {
    switch (token) {
        case tok_left: return "<";
        case tok_right: return ">";
        case tok_decrement: return "-";
        case tok_increment: return "+";
        case tok_input: return ",";
        case tok_output: return ".";
        case tok_loop_begin: return "[";
        case tok_loop_end: return "]";        
    }
    
    return "";    
}