//
//  Command.h
//  
//
//  Created by Jula McGibbon and Bejamin Linz on 14.12.14.
//
//

#ifndef ____Command__
#define ____Command__
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

#endif
