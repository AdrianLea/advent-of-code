#include <iostream>
#include <fstream>
#include <String>
#include <vector>
#include <unordered_map>


int main() {
    std::ifstream file("prompt3.txt");
    std::string line;
    std::vector<std::string> engine;
    std::string row;
    std::string currentNumString;
    std::unordered_map<std::string, std::vector<int>> gearmap = {};
    int total = 0;
    int currentNum;
    bool isPart = false;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    std::string partCoords;
    while (std::getline(file, line)) {
        engine.push_back(line);
    }
    for(int i = 0; i < engine.size(); i++) {
        row = engine[i];
        for(int j = 0; j < row.length(); j++) {
            if (isdigit(row[j])) {
                currentNumString += row[j];
                for (int k = 0; k < 8; k++) {
                    if (i+dy[k] >= 0 && i+dy[k] < engine.size() && j+dx[k] >= 0 && j+dx[k] < row.length()) {
                        if (engine[i+dy[k]][j+dx[k]] == '*' && isPart == false) {
                            isPart = true;
                            partCoords = std::to_string(i+dy[k]) + "," + std::to_string(j+dx[k]);
                        }
                    }
                }

            } else {
                if (isPart) {
                    currentNum = std::stoi(currentNumString);
                    if (gearmap.find(partCoords) == gearmap.end()) {
                        gearmap[partCoords] = {currentNum};
                    } else {
                        gearmap[partCoords].push_back(currentNum);
                    }
                    isPart = false;
                    currentNumString = "";
                } else {
                    currentNumString = "";
                }
            }
        }
    }
    for (auto it = gearmap.begin(); it != gearmap.end(); it++) {
        int product;
        if (it->second.size() == 2){
            product = it->second[0] * it->second[1];
            total += product;
        }
    }
    std::cout << total << std::endl;
    return 0;
}