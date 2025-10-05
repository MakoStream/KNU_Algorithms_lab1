#pragma once
#include "Command.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class CommandsManager {
private:
    std::vector<std::unique_ptr<Command>> commands;
public:
    CommandsManager();
    void execute(std::string& cmdName, std::vector<std::string>& args);
};

extern CommandsManager commandManager;