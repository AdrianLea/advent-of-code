#include <iostream>
#include <fstream>
#include <String>
#include <vector>


int main() {
    std::ifstream file("prompt3.txt");
    std::string line;
    std::vector<std::string> engine;
    std::string row;
    std::string currentNumString;
    int total = 0;
    int currentNum;
    bool isPart = false;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
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
                        if (ispunct(engine[i+dy[k]][j+dx[k]]) && engine[i+dy[k]][j+dx[k]] != '.') {
                            isPart = true;
                        }
                    }
                }

            } else {
                if (isPart) {
                    currentNum = std::stoi(currentNumString);
                    total += currentNum;
                    isPart = false;
                    currentNumString = "";
                } else {
                    currentNumString = "";
                }
            }
        }
    }
    std::cout << total << std::endl;
    return 0;
}