#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <language/parser.hpp>
#include <house/file.hpp>
#include <house/loader.hpp>

std::pair<bool, std::string> checkCommand(const NLCommand& cmd, const GGJEntity& entity) {
    
    const auto it = std::find_if(entity.links.begin(), entity.links.end(), [&](const GGJLink& link) {
        return link.verb == cmd.verb && link.object == cmd.object;
    });
    
    if (it != entity.links.end()) {
        return std::make_pair(true, it->key);
    }
    
    return std::make_pair(false, "");
}

int main(int argc, const char** args) {
    
    
    NLParser parser;

    auto goVerb = NLVerb("go");
    goVerb.synonyms.push_back("enter");

    auto useVerb = NLVerb("use");
    useVerb.synonyms.push_back("toggle");
    useVerb.synonyms.push_back("touch");

    parser.addVerb(goVerb);
    parser.addVerb(useVerb);
    parser.addVerb(NLVerb("get"));
    parser.addVerb(NLVerb("look"));
    parser.addVerb(NLVerb("take"));
    

    parser.addArticle("the");
    parser.addArticle("a");
    parser.addArticle("an");
    parser.addArticle("to");
    parser.addArticle("at");

    
    GGJLoader loader("intro.txt", "assets/");
    auto rooms = loader.compileGraph();
    
    GGJEntity* current = &rooms.at("intro.txt");
    
    for(;;) {
        std::cout << current->name << "\n";
        for(int i = 0; i < current->name.size(); ++i)
            std::cout << "=";
        std::cout << "\n\n";
        std::cout << current->desc << "\n\n";
        

        for(;;) {
            std::cout << "> ";

            std::string phrase;
            std::getline(std::cin, phrase);
        
            auto [parseSuccess, command] = parser.parse(phrase);
            if(!parseSuccess) {
                std::cout << "nope\n";
                continue;
            }
            
            auto [linkSuccess, key] = checkCommand(command, *current);
            if(!linkSuccess) {
                std::cout << "nuh-uh\n";
                continue;
            }
            
            
            current = &rooms.at(key);
            std::cout << "\n\n";
            break;
        }
    }

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