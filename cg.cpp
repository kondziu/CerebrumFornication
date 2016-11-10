//#include "llvm/ADT/APFloat.h"
//#include "llvm/ADT/STLExtras.h"
//#include "llvm/IR/BasicBlock.h"
//#include "llvm/IR/Constants.h"
//#include "llvm/IR/DerivedTypes.h"
//#include "llvm/IR/Function.h"
//#include "llvm/IR/IRBuilder.h"
//#include "llvm/IR/LLVMContext.h"
//#include "llvm/IR/Module.h"
//#include "llvm/IR/Type.h"
//#include "llvm/IR/Verifier.h"
//#include <cctype>
//#include <cstdio>
//#include <cstdlib>
//#include <map>
//#include <memory>
//#include <string>
//#include <vector>

#include <iostream>

#ifndef _BR_PARSER_H_
#include "parser.h"
#endif

#ifndef _BR_CG_H_
#include "cg.h"
#endif

//static LLVMContext TheContext;
//static IRBuilder<> Builder(TheContext);
//static std::unique_ptr<Module> TheModule;
//static std::map<std::string, Value *> NamedValues;

//Value *LogErrorV(const char *Str) {
//    LogError(Str);
//    return nullptr;
//}

int CodeGenerator::visit(const LeftOperationAST* node) {
    std::cout << "visiting (left) " << node->to_string() << "\n";
}

int CodeGenerator::visit(const RightOperationAST* node) {
    std::cout << "visiting (right) " << node->to_string() << "\n";
}

int CodeGenerator::visit(const InputOperationAST* node) {
    std::cout << "visiting (input) " << node->to_string() << "\n";
}

int CodeGenerator::visit(const OutputOperationAST* node) {
    std::cout << "visiting (output) " << node->to_string() << "\n";
}

int CodeGenerator::visit(const IncrementOperationAST* node) {
    std::cout << "visiting (increment) " << node->to_string() << "\n";
}

int CodeGenerator::visit(const DecrementOperationAST* node) {
    std::cout << "visiting (decrement) " << node->to_string() << "\n";
}

int CodeGenerator::visit(const LoopOperationAST* node) {
    std::cout << "visiting (loop) " << node->to_string() << "\n";
    
    for (const OperationAST* operation : node->children) {    
        operation->accept(this);
    }
}

int CodeGenerator::visit(const TopLevelAST* node) {
    std::cout << "visiting (top) " << node->to_string() << "\n";
    
    for (const OperationAST* operation : node->children) {    
        operation->accept(this);
    }
}