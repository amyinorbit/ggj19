#include <iostream>
#include <string>
#include <memory>
#include <game/driver.hpp>
#include <game/ggj19.hpp>
#include <game/sdlio.hpp>

int main(int argc, const char** args) {
    auto io = std::make_shared<SDLIO>(5, 8, 2);
    auto app = std::make_shared<GGJ19>();
    
    auto driver = GGJDriver(app, io);
    driver.run();
}