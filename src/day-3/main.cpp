#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

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

std::int64_t partTwo(const std::vector<std::string>& allBanks) {
    int64_t totalJolts = 0;

    // find the idx of the largest number with at least 11 numbers following it
    // find the idx of the next largest number with at least 10 numbers following it
    // find the idx of the next largest number with at least 9 numbers following it
    // ...

    for (const std::string& bankJolts : allBanks) {
        int bankLen = bankJolts.size();
        int batteriesRemaining = 12;
        std::size_t leftIdx = 0;
        while (batteriesRemaining > 0) {
            std::size_t probeIdx = leftIdx + 1;
            int largestNum = 0;
            while ((bankLen - probeIdx >= batteriesRemaining)) {
                if ((bankJolts[leftIdx] < bankJolts[probeIdx])) {
                    leftIdx = probeIdx;
                }
                ++probeIdx;
            }
            largestNum = bankJolts[leftIdx] - '0';
            totalJolts += largestNum * pow(10, batteriesRemaining-1);
            --batteriesRemaining;
            ++leftIdx;
        }
    }
    return totalJolts;
}

int main() {
    std::vector<std::string> allBanks;
    std::string bank;
    while (std::getline(std::cin, bank)) {
        allBanks.push_back(bank);
    }

    // std::int64_t totalJoltsPartOne = partOne(allBanks);
    // std::cout << "Part one total output joltage: " << totalJoltsPartOne << std::endl;

    std::int64_t totalJoltsPartTwo = partTwo(allBanks);
    std::cout << "Part two total output joltage: " << totalJoltsPartTwo << std::endl;

    return 0;
}