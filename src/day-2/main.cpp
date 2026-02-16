#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>

std::int64_t partOne(const std::string &input) {
  /*
  Goal: find invalid IDs. Find repeated sequences of digits.

  Since the young Elf was just doing silly patterns, you can find the invalid
  IDs by looking for any ID which is made only of some sequence of digits
  repeated twice. So, 55 (5 twice), 6464 (64 twice), and 123123 (123 twice)
  would all be invalid IDs.

  None of the numbers have leading zeroes; 0101 isn't an ID at all. (101 is a
  valid ID that you would ignore.)

  Result: What do you get if you add up all of the invalid IDs?
  */

  // sum of invalid IDs
  std::int64_t sumOfIDs = 0;

  constexpr char RANGE_DELIM = '-';
  constexpr char INPUT_DELIM = ',';

  std::stringstream ss(input);
  std::string inputRange;

  // loop through input
  while (std::getline(ss, inputRange, INPUT_DELIM)) {
    std::size_t rangeDelimIdx = inputRange.find(RANGE_DELIM);
    std::string leftBoundStr = inputRange.substr(0, rangeDelimIdx);
    std::string rightBoundStr = inputRange.substr(rangeDelimIdx + 1);
    std::int64_t leftBound = std::stoll(leftBoundStr);
    std::int64_t rightBound = std::stoll(rightBoundStr);
    // this loop goes through the numbers within the range
    while (leftBound <= rightBound) {
      const std::string currNum = std::to_string(leftBound);
      const std::size_t len = currNum.size();
      const std::size_t midIdx = len / 2;
      // if it's odd, it can't be a repeated sequence
      if ((len % 2 == 0) &&
          (currNum.substr(0, midIdx) == currNum.substr(midIdx, midIdx))) {
        sumOfIDs += leftBound;
      }
      ++leftBound;
    }
  }
  return sumOfIDs;
}

std::int64_t partTwo(const std::string &input) {
  /*
  Goal: find invalid IDs. Find repeated sequences of digits.

  Now, an ID is invalid if it is made only of some sequence of digits repeated
  at least twice. So, 12341234 (1234 two times), 123123123 (123 three times),
  1212121212 (12 five times), and 1111111 (1 seven times) are all invalid IDs.

  Result: What do you get if you add up all of the invalid IDs?
  */

  // sum of invalid IDs
  std::int64_t sumOfIDs = 0;

  constexpr char RANGE_DELIM = '-';
  constexpr char INPUT_DELIM = ',';

  std::stringstream ss(input);
  std::string inputRange;

  // loop through input
  while (std::getline(ss, inputRange, INPUT_DELIM)) {
    // construct range bounds
    std::size_t rangeDelimIdx = inputRange.find(RANGE_DELIM);
    std::string leftBoundStr = inputRange.substr(0, rangeDelimIdx);
    std::string rightBoundStr = inputRange.substr(rangeDelimIdx + 1);
    std::int64_t leftBound = std::stoll(leftBoundStr);
    std::int64_t rightBound = std::stoll(rightBoundStr);
    // this loop goes through the numbers within the range
    while (leftBound <= rightBound) {
      const std::string currNum = std::to_string(leftBound);
      const std::size_t len = currNum.size();
      // check num split into i subdivisions
      for (std::size_t i = 2; i <= len; ++i) {
        // check if number subdivision is valid
        if (len % i != 0) {
          continue;
        }
        int sequenceSize = len / i;
        int numEqual = 0;
        // check if all subdivisions are equal
        for (std::size_t  j = 0; j < i; ++j) {
          if (currNum.substr(sequenceSize * j, sequenceSize) ==
              currNum.substr(0, sequenceSize)) {
            ++numEqual;
          } else {
            break;
          }
        }
        if (numEqual == i) {
          sumOfIDs += leftBound;
          break;
        }
      }
      ++leftBound;
    }
  }
  return sumOfIDs;
}

int main() {
  std::string fullInput;
  std::getline(std::cin, fullInput);

  std::int64_t partOneSolution = partOne(fullInput);
  std::cout << "Part 1 -- sum of invalid IDs: " << partOneSolution << std::endl;
  std::int64_t partTwoSolution = partTwo(fullInput);
  std::cout << "Part 2 -- sum of invalid IDs: " << partTwoSolution << std::endl;

  return 0;
}