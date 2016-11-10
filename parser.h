#define _BR_PARSER_H_

#include <vector>
#include <string>
#include <iostream>

#ifndef _BR_LEXER_H_
#include "lexer.h"
#endif

/*
 * TopLevel ::= Operation*
 * Operation ::= LoopOperation | SimpleOperation
 * 
 * SimpleOperation ::= LeftOperation | RightOperation 
 *                  | InputOperation | OutputOperation 
 *                  | IncrementOperation | DecrementOperation
 * 
 * LoopOperation ::= '[' Operation* ']'
 * 
 * LeftOperation ::= '<'
 * RightOperation ::= '>'
 * InputOperation ::= ','
 * OutputOperation ::= '.'
 * IncrementOperation ::= '+'
 * DecrementOperation ::= '-'
 */
 
class ExpressionAST; 
class TopLevelAST;
class OperationAST; 
class SimpleOperationAST;
class LoopOperationAST;
class LeftOperationAST;
class RightOperationAST;
class InputOperationAST;
class OutputOperationAST;
class IncrementOperationAST;
class DecrementOperationAST;
 
class ASTVisitor {
    public:
    virtual int visit(const LeftOperationAST* node) = 0;
    virtual int visit(const RightOperationAST* node) = 0;
    virtual int visit(const InputOperationAST* node) = 0;
    virtual int visit(const OutputOperationAST* node) = 0;
    virtual int visit(const IncrementOperationAST* node) = 0;
    virtual int visit(const DecrementOperationAST* node) = 0;
    virtual int visit(const LoopOperationAST* node) = 0;
    virtual int visit(const TopLevelAST* node) = 0;
};

class ExpressionAST {
    public:
    virtual ~ExpressionAST() {}
    virtual std::string to_string() const = 0;    
    virtual int accept(ASTVisitor* visitor) const = 0;
};

class OperationAST : public ExpressionAST {
    public:
    ExpressionAST* parent;
    explicit OperationAST(ExpressionAST* parent) : parent(parent) {}
};

class SimpleOperationAST : public OperationAST {
    public:
    explicit SimpleOperationAST(ExpressionAST* parent) : OperationAST(parent) {}
};

class LeftOperationAST : public SimpleOperationAST {
    public:
    explicit LeftOperationAST(ExpressionAST* parent) : SimpleOperationAST(parent) {}
    std::string to_string() const;
    int accept(ASTVisitor* visitor) const;
};

class RightOperationAST : public SimpleOperationAST {
    public:
    explicit RightOperationAST(ExpressionAST* parent) : SimpleOperationAST(parent) {}
    std::string to_string() const;
    int accept(ASTVisitor* visitor) const;
};

class InputOperationAST : public SimpleOperationAST {
    public:
    explicit InputOperationAST(ExpressionAST* parent) : SimpleOperationAST(parent) {}
    std::string to_string() const;
    int accept(ASTVisitor* visitor) const;
};

class OutputOperationAST : public SimpleOperationAST {
    public:
    explicit OutputOperationAST(ExpressionAST* parent) : SimpleOperationAST(parent) {}
    std::string to_string() const;
    int accept(ASTVisitor* visitor) const;
};

class IncrementOperationAST : public SimpleOperationAST {
    public:
    explicit IncrementOperationAST(ExpressionAST* parent) : SimpleOperationAST(parent) {}
    std::string to_string() const;
    int accept(ASTVisitor* visitor) const;
};

class DecrementOperationAST : public SimpleOperationAST {
    public:
    explicit DecrementOperationAST(ExpressionAST* parent) : SimpleOperationAST(parent) {}
    std::string to_string() const;
    int accept(ASTVisitor* visitor) const;
};

class LoopOperationAST : public OperationAST {
    public:
    std::vector<OperationAST*> children;    
    explicit LoopOperationAST(ExpressionAST* parent) : OperationAST(parent), children({}) {}
    std::string to_string() const;
    int accept(ASTVisitor* visitor) const;
};

class TopLevelAST : public ExpressionAST {
    public:
    std::vector<OperationAST*> children;
    explicit TopLevelAST() : children({}) {}
    std::string to_string() const;
    int accept(ASTVisitor* visitor) const;
};

const TopLevelAST* parse();
