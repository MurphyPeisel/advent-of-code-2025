#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

std::int64_t partOne(const std::vector<std::string>& allBanks) {
    int64_t totalJolts = 0;

    for (const std::string& bankJolts : allBanks) {
        std::size_t leftIdx = 0;
        std::size_t rightIdx = leftIdx + 1;
        std::size_t probeIdx = rightIdx;
        int leftNum;
        int rightNum;
        while (probeIdx < bankJolts.size()) {
             if ((bankJolts[leftIdx] < bankJolts[probeIdx]) && (probeIdx < bankJolts.size() - 1)) {
                leftIdx = probeIdx;
                ++probeIdx;
                rightIdx = probeIdx;
            } else if (bankJolts[rightIdx] < bankJolts[probeIdx]) {
                rightIdx = probeIdx;
                ++probeIdx;
            } else {
                ++probeIdx;
            }
        }
        leftNum = bankJolts[leftIdx] - '0';
        rightNum = bankJolts[rightIdx] - '0';
        totalJolts += leftNum * 10 + rightNum;
    }
    return totalJolts;
}

int main() {
    std::vector<std::string> allBanks;
    std::string bank;
    while (std::getline(std::cin, bank)) {
        allBanks.push_back(bank);
    }

    std::int64_t totalJolts = partOne(allBanks);
    std::cout << "Total output joltage: " << totalJolts << std::endl;
    return 0;
}