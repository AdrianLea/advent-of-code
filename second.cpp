#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

int getPower(std::string input) {
    std::string numstring = "";
    std::string colourstring = "";
    std::unordered_map<std::string, int> maxmap = {{"red",0},{"blue",0},{"green",0}};
    int number;
    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i])){
            numstring += input[i];
        } else if (isalpha(input[i])) {
            colourstring += input[i];
        }

        if (input[i] == ',' || input[i] == ';' || i == input.length()-1) {
            maxmap[colourstring] = std::max(maxmap[colourstring], std::stoi(numstring));
            numstring = "";
            colourstring = "";
        }
    }
    return (maxmap["red"] * maxmap["blue"] * maxmap["green"]);
}

int main() {
    std::ifstream file("prompt2.txt");
    std::string line;
    std::string game;
    std::string idstring;
    int id;
    int startindex;
    int total = 0;
    
    while (std::getline(file, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ':') {
                startindex = i+1;
                break;
            }
        }
        game = line.substr(startindex);
        total += getPower(game);
    }
    std::cout << total << std::endl;
    return 0;
}

