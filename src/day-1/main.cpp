#include <iostream>
#include <string>
#include <unordered_map>

/*
    The attached document (your puzzle input) contains a sequence of rotations,
   one per line, which tell you how to open the safe. A rotation starts with an
   L or R which indicates whether the rotation should be to the left (toward
   lower numbers) or to the right (toward higher numbers). Then, the rotation
   has a distance value which indicates how many clicks the dial should be
   rotated in that direction.

    The actual password is the number of times the dial is left pointing at 0
    after any rotation in the sequence.

    Dial starts at 50
*/

int main() {
  constexpr int DIAL_SIZE = 100;
  int dialPosition = 50;
  int password = 0;
  int dialMagnitude = 0;
  int dialTurn = 0;
  char dialDirection = ' ';
  std::string dialInput = "";

  std::istream &file = std::cin;

  //   cout << "Dial position: " << dialPosition << endl;
  while (std::getline(file, dialInput)) {
    if (dialInput.empty()) {
      continue;
    };
    dialDirection = dialInput[0];
    dialMagnitude = stoi(dialInput.substr(1));
    if (dialDirection == 'L' || dialDirection == 'R') {
      dialTurn = (dialDirection == 'L' ? -dialMagnitude : dialMagnitude);
      //   cout << "Turning the dial " << dialMagnitude << " to the " <<
      //   (dialDirection == 'L' ? "left" : "right")
      //        << endl;
      dialPosition = (dialPosition + dialTurn + DIAL_SIZE) % DIAL_SIZE;
      //   cout << "New dial position: " << dialPosition << endl;
      if (dialPosition == 0) {
        ++password;
      }
    } else {
      std::cerr << "Read an invalid character: " << dialDirection << std::endl;
      return 1;
    }
  }

  std::cout << "Password: " << password << std::endl;

  return 0;
}
