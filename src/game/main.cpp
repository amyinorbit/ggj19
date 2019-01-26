#include <iostream>
#include <fstream>
#include <string>
#include <language/parser.hpp>
#include <house/file.hpp>
#include <house/loader.hpp>

int main(int argc, const char** args) {
    
    GGJLoader loader("intro.txt");
    auto rooms = loader.compileGraph();
    
    // std::ifstream in("/Users/amy/Desktop/foyer.txt");
    // assert(in.is_open());
    // auto file = GGJFile("foyer.txt", in);
    
    // while (1) {
    //     const auto& tok = file.nextToken();
    //     if (tok.kind == GGJToken::End) break;
    //
    //     std::cout << "[ " << tok.kind << " ] " << tok.text << "\n";
    // }
    
    // auto room = file.compile();
    //
    // std::cout << room.name << "\n\n";
    // std::cout << room.desc << "\n\n";
    //
    // std::cout << "Links\n";
    // for(const auto& link: room.links) {
    //     std::cout << " - " << link.verb << "(" << link.object << ") -> " << link.key << "\n";
    // }
    
    
    
    
    
    
    
    // NLParser parser;
    //
    // auto goVerb = NLVerb("go");
    // goVerb.synonyms.push_back("enter");
    //
    // auto useVerb = NLVerb("use");
    // useVerb.synonyms.push_back("toggle");
    // useVerb.synonyms.push_back("touch");
    //
    // parser.addVerb(goVerb);
    // parser.addVerb(useVerb);
    //
    // parser.addArticle("the");
    // parser.addArticle("a");
    // parser.addArticle("an");
    // parser.addArticle("to");
    //
    // while(1) {
    //
    //     std::cout << "> ";
    //     std::string phrase;
    //     std::getline(std::cin, phrase);
    //     auto [success, command] = parser.parse(phrase);
    //
    //     std::cout << "\tsuccess: " << (success ? "true" : "false") << "\n";
    //     std::cout << "\tcommand.verb:   " << command.verb << "\n";
    //     std::cout << "\tcommand.object: " << command.object << "\n";
    //     std::cout << "\n";
    // }
}