#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>

/*
Goal: find invalid IDs. Find repeated sequences of digits.

Since the young Elf was just doing silly patterns, you can find the invalid IDs by looking for any ID
which is made only of some sequence of digits repeated twice. 
So, 55 (5 twice), 6464 (64 twice), and 123123 (123 twice) would all be invalid IDs.

None of the numbers have leading zeroes; 0101 isn't an ID at all. (101 is a valid ID that you would ignore.)

Result: What do you get if you add up all of the invalid IDs?
*/


int main() {
    // sum of invalid IDs
    std::int64_t sumOfIDs = 0;

    constexpr char RANGE_DELIM = '-';
    constexpr char INPUT_DELIM = ',';
    
    std::string inputRange = "";
    // loop through input
    while(std::getline(std::cin, inputRange, INPUT_DELIM)) {
        std::size_t rangeDelimIdx = inputRange.find(RANGE_DELIM);
        std::string leftBoundStr = inputRange.substr(0, rangeDelimIdx);
        std::string rightBoundStr = inputRange.substr(rangeDelimIdx + 1);
        std::int64_t leftBound = std::stol(leftBoundStr);
        std::int64_t rightBound = std::stol(rightBoundStr);
        // this loop goes through the numbers within the range
        while (leftBound <= rightBound) {
            const std::string currNum = std::to_string(leftBound);
            const std::size_t len = currNum.size();
            const std::size_t midIdx = len / 2;
            // if it's odd, it can't be a repeated sequence
            if ((len % 2 == 0 ) && (currNum.substr(0, midIdx) == currNum.substr(midIdx, midIdx))) {
                sumOfIDs += leftBound;
            }
            ++leftBound;
        }
    }
    std::cout << "Final sum of invalid IDs: " << sumOfIDs << std::endl;
    return 0;
}
