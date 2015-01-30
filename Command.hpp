//
//  Command.hpp
//  
//
//  Created by Jula McGibbon and Bejamin Linz on 14.12.14.
//
//

#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <queue>

class Command {
public:
    Command(std::string conversion, std::string value_string);
    bool execute();
    std::string getDescription() const;
    double getInput() const;
    double getOutput() const;

private:
    std::string conversion, value_string;
    std::string description;
    double input, output;
};

typedef std::queue<Command> CommandQueue;

#endif //COMMAND_H
