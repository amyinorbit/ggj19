#include <iostream>
#include <string>
#include <language/parser.hpp>

int main() {
    
    NLParser parser;
    
    auto goVerb = NLVerb("go");
    goVerb.synonyms.push_back("enter");
    
    auto useVerb = NLVerb("use");
    useVerb.synonyms.push_back("toggle");
    useVerb.synonyms.push_back("touch");
    
    parser.addVerb(goVerb);
    parser.addVerb(useVerb);
    
    parser.addArticle("the");
    parser.addArticle("a");
    parser.addArticle("an");
    parser.addArticle("to");
    
    while(1) {
        
        std::cout << "> ";
        std::string phrase;
        std::getline(std::cin, phrase);
        auto [success, command] = parser.parse(phrase);
        
        std::cout << "\tsuccess: " << (success ? "true" : "false") << "\n";
        std::cout << "\tcommand.verb:   " << command.verb << "\n";
        std::cout << "\tcommand.object: " << command.object << "\n";
        // NLLexer lex(phrase);
        //
        // std::cout << "> ";
        // while (!lex.end()) {
        //     std::cout << "[" << lex.currentToken().first << "] ";
        //     lex.nextToken();
        // }
        std::cout << "\n";
    }
}