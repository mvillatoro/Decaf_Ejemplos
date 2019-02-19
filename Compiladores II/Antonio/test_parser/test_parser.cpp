#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>
#include <memory>
#include <cstring>
#include "doctest.h"
#include "tokens.h"
#include "lexer.h"

extern bool syn_error;
void * ParserAlloc(void *(*mallocProc)(size_t));
void Parser(void*, int yymajor, int yyminor);
void ParserFree(void*, void (*freeProc)(void*));

bool parser(ifstream &in){
    void *pParser = ParserAlloc(malloc);
    Lexer l(in);
    int token = l.getNextToken();
    while(token !=  END){
        cout<< l.getLexeme()<<endl;
        if(token != -1){
            Parser(pParser, token, 0);
        }else{
            cout<<"lexical and parser analisys fail"<<endl;
            return false;
        }
        token = l.getNextToken();
    }
    cout<<"lexical and parser analisys done succesfully."<<endl;
    Parser(pParser, token, 0);
    ParserFree(pParser, free);
    return true;
}

TEST_CASE(" Test Comments "){
    std::string filename = "../../inputs/class_comments.df";
    std::ifstream file(filename);
    REQUIRE(file.is_open());
    bool resp = parser(file); 
    CHECK(resp == true);
}

TEST_CASE(" Test Operations"){
    std::string filename = "../../inputs/class_operations.df";
    std::ifstream file(filename);
    REQUIRE(file.is_open());
    bool resp = parser(file); 
    CHECK(resp == true);
}

TEST_CASE(" Test Prints Random and Read"){
    std::string filename = "../../inputs/class_system_random.df";
    std::ifstream file(filename);
    REQUIRE(file.is_open());
    bool resp = parser(file); 
    CHECK(resp == true);
}

TEST_CASE(" Test if"){
    std::string filename = "../../inputs/class_if.df";
    std::ifstream file(filename);
    REQUIRE(file.is_open());
    bool resp = parser(file); 
    CHECK(resp == true);
}


TEST_CASE(" Test for"){
    std::string filename = "../../inputs/class_for.df";
    std::ifstream file(filename);
    REQUIRE(file.is_open());
    bool resp = parser(file); 
    CHECK(resp == true);
}


TEST_CASE(" Test while"){
    std::string filename = "../../inputs/class_while.df";
    std::ifstream file(filename);
    REQUIRE(file.is_open());
    bool resp = parser(file); 
    CHECK(resp == true);
}