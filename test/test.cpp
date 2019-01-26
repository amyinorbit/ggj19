#include <iostream>
#include <language/lexer.hpp>

int main() {
    
    NLLexer lex("go to the red door");
    
    
    while (!lex.end()) {
        std::cout << "token: " << lex.currentToken().first << "\n";
        lex.nextToken();
    }
}