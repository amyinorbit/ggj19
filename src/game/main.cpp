#include <iostream>
#include <string>
#include <memory>
#include <game/driver.hpp>
#include <game/ggj19.hpp>
#include <game/sdlio.hpp>

int main(int argc, const char** args) {
    SDLIO io(5, 8, 2);
    GGJ19 app;
    
    auto driver = GGJDriver(app, io);
    driver.run();
}