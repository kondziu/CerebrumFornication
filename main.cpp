#include <cstdio>
#include <vector>
#include <iostream>

#include "lexer.h"
#include "parser.h"
#include "cg.h"

int main(int argc, char **argv) {
	printf("lookit me parsing\n");
        
    const TopLevelAST* abstract_syntax_tree = parse();
    CodeGenerator* generator = new CodeGenerator();
    abstract_syntax_tree->accept(generator);
    
	return 0;
}
