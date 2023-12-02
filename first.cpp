#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype>
#include <fstream>
#include <sstream> 
int main() {
    std::ifstream file("prompt1.txt");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string input = buffer.str();
    std::stack<char> s;
    std::string firstchar = "";
    int totalsum = 0;
    std::string temp = "";
    for(int i = 0; i < input.length(); i++){
        if (isdigit(input[i])) {
            s.push(input[i]);
            if (firstchar.length() == 0){
                firstchar = input[i];
            }
        }
        if (input[i] == '\n' || i == input.length() - 1) {
            std::string temp = std::string(1,firstchar[0]) + std::string(1, s.top());
            int newnumber = std::stoi(temp);
            firstchar = "";
            totalsum += newnumber;
        }
    }

    std::cout << totalsum << std::endl;
    
    return 0;
}
