#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype>
#include <fstream>
#include <sstream> 
#include <array>
#include <unordered_map>
int main() {
    std::ifstream file("prompt1.txt");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string input = buffer.str();
    std::stack<char> s;
    std::string firstchar = "";
    int totalsum = 0;
    std::string temp = "";
    std::unordered_map<std::string, std::string> map = {{"one","1"},{"two","2"},{"three","3"},{"four","4"},{"five","5"},{"six","6"},{"seven","7"},{"eight","8"},{"nine","9"}};

    // please dont hate me for this
    std::string one = "";
    std::string two = "";
    std::string three = "";
    std::string four = "";
    std::string five = "";
    int clock = 0;
    for(int i = 0; i < input.length(); i++){
        if (clock < 5){
            if (clock == 0) {
                one = input[i];
            } else if (clock == 1) {
                two = input[i];
                one += input[i];
            } else if (clock == 2) {
                three = input[i];
                one += input[i];
                two += input[i];
            } else if (clock == 3) {
                four = input[i];
                one += input[i];
                two += input[i];
                three += input[i];
            } else if (clock == 4) {
                five = input[i];
                one += input[i];
                two += input[i];
                three += input[i];
                four += input[i];
            }
            clock++;
        } else {
            one += input[i];
            two += input[i];
            three += input[i];
            four += input[i];
            five += input[i];
            if (one.length() > 5) {
                one = input[i];
            }
            if (two.length() > 5) {
                two = input[i];
            }
            if (three.length() > 5) {
                three = input[i];
            }
            if (four.length() > 5) {
                four = input[i];
            }
            if (five.length() > 5) {
                five = input[i];
            }
        }
        if (isdigit(input[i]) || map.find(one) != map.end() || map.find(two) != map.end() || map.find(three) != map.end() || map.find(four) != map.end() || map.find(five) != map.end()) {
            if (isdigit(input[i])) {
                s.push(input[i]);
                if (firstchar.length() == 0){
                    firstchar = input[i];
                }
            } else if (map.find(one) != map.end()) {
                s.push(char(map[one][0]));
                if (firstchar.length() == 0){
                    firstchar = map[one];
                }
            } else if (map.find(two) != map.end()) {
                s.push(char(map[two][0]));
                if (firstchar.length() == 0){
                    firstchar = map[two];
                }
            } else if (map.find(three) != map.end()) {
                s.push(char(map[three][0]));
                if (firstchar.length() == 0){
                    firstchar = map[three];
                }
            } else if (map.find(four) != map.end()) {
                s.push(char(map[four][0]));
                if (firstchar.length() == 0){
                    firstchar = map[four];
                }
            } else if (map.find(five) != map.end()) {
                s.push(char(map[five][0]));
                if (firstchar.length() == 0){
                    firstchar = map[five];
                }
            }
            
        }
        if (input[i] == '\n' || i == input.length() - 1) {
            std::string temp = std::string(1,firstchar[0]) + std::string(1, s.top());
            int newnumber = std::stoi(temp);
            firstchar = "";
            totalsum += newnumber;
            clock = 0;
            
        }
    }

    std::cout << totalsum << std::endl;
    
    return 0;
}
