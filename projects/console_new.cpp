#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <sstream>
#include <vector>

using CommandHandler = std::function<void(const std::vector<std::string> &)>;

std::vector<std::string> split(const std::string &input) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
};

class Console {
    private:
        std::map<std::string, CommandHandler> commands;
        bool running;
    public:
        Console() : running(true) {
            commands["help"] = [this](const std::vector<std::string> &args){
                std::cout << "Available commands: \n";
                for (const auto &cmd : commands) {
                    std::cout << " " << cmd.first << "\n";
                }
            };

            commands["exit"] = [this](const std::vector<std::string> &args) {
                std::cout << "Exiting console.\n";
                running = false;
            };

            commands["echo"] = [](const std::vector<std::string> &args){
                for (size_t i = 1; i < args.size(); i++) {
                    std::cout << args[i] << " ";
                }
                std::cout << "\n";
            };
        }

        void registerNewCommands(const std::string &name, CommandHandler commandHandler) {
            commands[name] = commandHandler;
        }

        void processInput(const std::string &input) {
            if (input.empty()) return;
            auto tokens = split(input);
            if (tokens.empty()) return;

            std::string command = tokens[0];
            auto it = commands.find(command);
            if (it != commands.end()) {
                it->second(tokens);
            } else {
                std::cout << "Invalid command: " << command << "\n";
            }
        }

        void run() {
            std::string input;
            std::cout << "Running console. Type 'help' for commands.\n";
            while (running) {
                std::cout << "> ";
                std::getline(std::cin, input);
                processInput(input);
            }
        }
};

int main() {
    Console console;
    console.run();
}