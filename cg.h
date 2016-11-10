#define _BR_CG_H_

#ifndef _BR_PARSER_H_
#include "parser.h"
#endif

/*
 * ExpressionAST
 * 
 * TopLevelAST : ExpressionAST
 * OperationAST : ExpressionAST
 * 
 * SimpleOperationAST : OperationAST
 * LoopOperationAST : OperationAST
 *
 * LeftOperationAST : SimpleOperationAST
 * RightOperationAST : SimpleOperationAST
 * InputOperationAST : SimpleOperationAST
 * OutputOperationAST : SimpleOperationAST
 * IncrementOperationAST : SimpleOperationAST
 * DecrementOperationAST : SimpleOperationAST
 */

class CodeGenerator : public ASTVisitor {
    public:
    int visit(const LeftOperationAST* node);
    int visit(const RightOperationAST* node);
    int visit(const InputOperationAST* node);
    int visit(const OutputOperationAST* node);
    int visit(const IncrementOperationAST* node);
    int visit(const DecrementOperationAST* node);
    int visit(const LoopOperationAST* node);
    int visit(const TopLevelAST* node);
};