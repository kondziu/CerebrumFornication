#define _BR_LEXER_H_

enum Token {
    tok_eof = 0,

    // shifts
    tok_left = 1,
    tok_right = 2,
      
    // modifications
    tok_increment = 4,
    tok_decrement = 8,

    // I/O
    tok_input = 16,
    tok_output = 32,
      
    // loop
    tok_loop_begin = 64,
    tok_loop_end = 128,    
};

int get_token();
char char_of_token(int token);
char *string_of_token(int token);