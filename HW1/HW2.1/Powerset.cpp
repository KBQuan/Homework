#include <iostream>
#include <vector>
#include <string>


void generatePowerSet(const std::vector<char>& set, int index, std::vector<char> currentSet, std::vector<std::vector<char> >& allSubsets) {

    if (index == set.size()) {
        allSubsets.push_back(currentSet);
        return;
    }


    generatePowerSet(set, index + 1, currentSet, allSubsets);


    currentSet.push_back(set[index]);
    generatePowerSet(set, index + 1, currentSet, allSubsets);
}

int main() {
    std::vector<char> set; 
    std::vector<std::vector<char> > allSubsets;

    std::string input;
    std::cout << "請輸入集合元素（例如：abc）：";
    std::getline(std::cin, input);


    for (size_t i = 0; i < input.size(); ++i) {
        set.push_back(input[i]);
    }


    generatePowerSet(set, 0, std::vector<char>(), allSubsets);

    std::cout << "冪集:\n";
    for (size_t i = 0; i < allSubsets.size(); ++i) {
        std::cout << "{ ";
        for (size_t j = 0; j < allSubsets[i].size(); ++j) {
            std::cout << allSubsets[i][j] << " ";
        }
        std::cout << "}\n";
    }

    return 0;
}

