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
    std::unordered_map<int,int> scratchCardMap = {};
    std::string numstring = "";
    int num;
    int total = 0;
    int score;
    int state;
    int scratchNum;
    while (std::getline(file, line)){
        score = 0;
        state = 0;
        for (int i = 0; i < line.length(); i++) {
            if(state == 0){
                if(isdigit(line[i])){
                    numstring += line[i];
                }
                if(line[i] == ':' & numstring != "") {
                    num = std::stoi(numstring);
                    scratchNum = num;
                    if(scratchCardMap.find(num) == scratchCardMap.end()){
                        scratchCardMap[num] = 1;
                    } else {
                        scratchCardMap[num] += 1;
                    }
                    numstring = "";
                }
            }
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
                
                score += 1;
            }
        }
        for (int i = scratchNum + 1; i <= scratchNum + score; i++) {
            if(scratchCardMap.find(i) != scratchCardMap.end()){
                scratchCardMap[i] += scratchCardMap[scratchNum];
            } else {      
                scratchCardMap[i] = scratchCardMap[scratchNum];
            }
        }
        scratchCard.clear();
        map.clear();
    }
    for (auto it = scratchCardMap.begin(); it != scratchCardMap.end(); it++) {
        if (it->first <= scratchNum) {
           
            total += it->second;
        }
    }
    std::cout << total << std::endl;
}