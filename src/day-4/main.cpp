#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <vector>

struct Direction {
    int dr;
    int dc;
};

std::int64_t partOne(const std::vector<std::string> &grid) {
    /*
        The forklifts can only access a roll of paper if there are fewer than four rolls of paper in the eight adjacent positions. 
        If you can figure out which rolls of paper the forklifts can access, they'll spend less time looking and more time breaking 
        down the wall to the cafeteria.

            - find cells where val=@ with  < 4 adjacent @s

    */

    const char paperRoll = '@';
    const char emptyCell = '.';

    const std::size_t cols = grid[0].size();
    const std::size_t rows = grid.size();

    std::size_t numRolls = 0;

    constexpr std::array<Direction, 8> directions {{
        {1,0}, {-1,0}, {0,1}, {0,-1},
        {1,1}, {1,-1}, {-1,1}, {-1,-1}
    }};


    for (std::size_t r = 0; r < rows; ++r) {
        for (std::size_t c = 0; c < cols; ++c) {
            // check if cell is @
            if (grid[r][c] == paperRoll) { 
                // check each direction
                for (const auto& d : directions) {
                    // create vars to count

                    // get new r, c
                    int newRow = r + d.dr;
                    int newCol = c + d.dc;
                    // verify cell
                    if ((newRow > 0 && newRow < rows) && (newCol > 0 && newCol < cols)) {
                        // check count criteria

                    }
                }
            }
        }
    }
    return 0;
}


int main() {
    std::vector<std::string> grid;
    std::string row;
    std::ifstream file("../src/day-4/input.txt");
    
    // read input
    while(std::getline(file, row)) {
        grid.push_back(row);
        std::cout << row << std::endl;
    }

    std::int64_t partOneResult = partOne(grid);
    std::cout << "Maximum paper rolls: "<< partOneResult << std::endl;

    file.close();
    return 0;
}
