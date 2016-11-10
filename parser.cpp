#include <vector>
#include <cstdio>

#ifndef _BR_LEXER_H_
#include "lexer.h"
#endif

#ifndef _BR_PARSER_H_
#include "parser.h"
#endif

std::string LeftOperationAST::to_string() const { return "<"; }
std::string RightOperationAST::to_string() const { return ">"; }
std::string InputOperationAST::to_string() const { return ","; }
std::string OutputOperationAST::to_string() const { return "."; }
std::string IncrementOperationAST::to_string() const { return "+"; }
std::string DecrementOperationAST::to_string() const { return "-"; }

std::string LoopOperationAST::to_string() const { 
    std::string buffer = "[";
    for (OperationAST* child : children) {
        buffer += child->to_string();
    }
    buffer += "]";
    return buffer;         
}

std::string TopLevelAST::to_string() const { 
    std::string buffer = "";
    for (OperationAST* child : children) {
        buffer += child->to_string();
    }
    return buffer;         
}

int LeftOperationAST::accept(ASTVisitor* visitor) const { return visitor->visit(this); }
int RightOperationAST::accept(ASTVisitor* visitor) const { return visitor->visit(this); }
int InputOperationAST::accept(ASTVisitor* visitor) const { return visitor->visit(this); }
int OutputOperationAST::accept(ASTVisitor* visitor) const { return visitor->visit(this); }
int IncrementOperationAST::accept(ASTVisitor* visitor) const { return visitor->visit(this); }
int DecrementOperationAST::accept(ASTVisitor* visitor) const { return visitor->visit(this); }
int LoopOperationAST::accept(ASTVisitor* visitor) const { return visitor->visit(this); }
int TopLevelAST::accept(ASTVisitor* visitor) const { return visitor->visit(this); }

static int current_token;
static int get_next_token() { return current_token = get_token(); }

/*
 * Program ::= Operation*
 * Operation ::= '[' Operation* ']' | '<' | '>' | '.' | ',' | '+' | '-'
 */ 

// Does not consume token.
SimpleOperationAST* parse_simple_operation(ExpressionAST* parent) {
    switch (current_token) {
        case tok_left: return new LeftOperationAST(parent); break;
        case tok_right: return new RightOperationAST(parent); break;
        case tok_decrement: return new DecrementOperationAST(parent); break;
        case tok_increment: return new IncrementOperationAST(parent); break;
        case tok_input: return new InputOperationAST(parent); break;
        case tok_output: return new OutputOperationAST(parent); break;    
        //default: // FIXME throw exception
    }
}

LoopOperationAST* parse_loop_block(ExpressionAST* parent) {
    int level = 0;    
    LoopOperationAST* loop = new LoopOperationAST(parent);
    
    while (true) {
        get_next_token();
        
        if (current_token == tok_loop_begin) {
            LoopOperationAST* subloop = new LoopOperationAST(loop);
            loop->children.push_back(subloop);
            loop = subloop;
            level++;
            continue;
        }
            
        if (current_token == tok_loop_end) {
            if (level == 0) {
                return loop;
            } else if (level > 0) {
                level--;
                loop = static_cast<LoopOperationAST*>(loop->parent);
                continue;
            } else {
                // FIXME throw exception
                printf("Error: unbalanced loop end in loop block\n");
                continue;
            }
        }
            
        if (current_token == tok_eof) {
            // FIXME throw exception
            printf("Error: EOF in loop block\n");
            continue;
        }           
        
        loop->children.push_back(parse_simple_operation(loop)); 
    }
}

const TopLevelAST* parse() {    
    TopLevelAST* top_level = new TopLevelAST();
    
    while (true) {
        get_next_token();
        
        if (current_token == tok_loop_begin) {
            top_level->children.push_back(parse_loop_block(top_level));
            continue;
        }
            
        if (current_token == tok_loop_end) {
            // FIXME throw exception
            printf("Error: loop end in toplevel\n");
            continue;
        }
            
        if (current_token == tok_eof) {
            return top_level;
        }           
        
        top_level->children.push_back(parse_simple_operation(top_level));
    }
}