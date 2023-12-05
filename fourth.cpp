#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
int main() {
    std::string line;
    std::ifstream file("prompt4.txt");
    std::unordered_map<int, int> map = {};
    std::vector<int> scratchCard;
    std::string numstring = "";
    int num;
    int total = 0;
    int score;
    int state;
    while (std::getline(file, line)){
        score = 0;
        state = 0;
        for (int i = 0; i < line.length(); i++) {
            if(state == 1){
                if(isdigit(line[i])){
                    numstring += line[i];
                }
                if(line[i] == ' ' & numstring != "") {
                    num = std::stoi(numstring);
                    map[num] = 1;
                    numstring = "";
                }
            } else if(state == 2){
                if(isdigit(line[i])){
                    numstring += line[i];
                }
                if((line[i] == ' ' || i == line.length()-1) & numstring != "") {
                    num = std::stoi(numstring);
                    scratchCard.push_back(num);
                    numstring = "";
                }
            }
            if (line[i] == ':') {
                state = 1;
            } else if (line[i] == '|') {
                state = 2;
            }
        }
        for (int i = 0; i < scratchCard.size(); i++) {
            if (map.find(scratchCard[i]) != map.end()) {
                
                if (score  == 0){
                    score = 1;
                } else {
                    score *= 2;
                }
            }
        }
        total += score;
        scratchCard.clear();
        map.clear();
    }
    std::cout << total << std::endl;
}