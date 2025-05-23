#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <functional>

// Function to split a string into tokens
std::vector<std::string> split(const std::string& input) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

// Command handler type
using CommandHandler = std::function<void(const std::vector<std::string>&)>;

// Console class
class Console {
private:
    std::map<std::string, CommandHandler> commands;
    bool running;
    std::vector<std::string> history;

public:
    Console() : running(true) {
        // Register default commands
        commands["help"] = [this](const std::vector<std::string>& args) {
            std::cout << "Available commands:\n";
            for (const auto& cmd : commands) {
                std::cout << "  " << cmd.first << "\n";
            }
        };
        commands["history"] = [this](const std::vector<std::string>& args) {
            std::cout << "Command history:\n";
            for (size_t i = 0; i < history.size(); ++i) {
                std::cout << i + 1 << ": " << history[i] << "\n";
            }
        };
        commands["exit"] = [this](const std::vector<std::string>& args) {
            running = false;
            std::cout << "Exiting console.\n";
        };
        commands["echo"] = [](const std::vector<std::string>& args) {
            for (size_t i = 1; i < args.size(); ++i) {
                std::cout << args[i] << " ";
            }
            std::cout << "\n";
        };
        commands["greet"] = [](const std::vector<std::string>& args) {
            if (args.size() > 1) {
                std::cout << "Hello, " << args[1] << "!\n";
            } else {
                std::cout << "Please provide a name.\n";
            }
        };
    }

    // Register a new command
    void registerCommand(const std::string& name, CommandHandler handler) {
        commands[name] = handler;
    }

    // Process a single input line
    void processInput(const std::string& input) {
        if (input.empty()) return;
        history.push_back(input);
        auto tokens = split(input);
        if (tokens.empty()) return;

        std::string command = tokens[0];
        auto it = commands.find(command);
        if (it != commands.end()) {
            it->second(tokens);
        } else {
            std::cout << "Unknown command: " << command << "\n";
        }
    }

    // Run the console loop
    void run() {
        std::string input;
        std::cout << "Console started. Type 'help' for commands.\n";
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
    return 0;
}