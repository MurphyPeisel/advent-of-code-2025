#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <vector>

struct Direction {
    int dr;
    int dc;
};

constexpr std::array<Direction, 8> directions {{
    {1,0}, {-1,0}, {0,1}, {0,-1},
    {1,1}, {1,-1}, {-1,1}, {-1,-1}
}};

const char paperRoll = '@';

std::uint64_t partOne(const std::vector<std::string> &grid) {
    /*
        The forklifts can only access a roll of paper if there are fewer than four rolls of paper in the eight adjacent positions. 
        If you can figure out which rolls of paper the forklifts can access, they'll spend less time looking and more time breaking 
        down the wall to the cafeteria.
            - find cells where val=@ with  < 4 adjacent @s
    */

    const int cols = grid[0].size();
    const int rows = grid.size();

    std::uint64_t numRolls = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            // check if cell is @
            if (grid[r][c] == paperRoll) { 
                int adjRolls = 0;
                // check each direction
                for (const auto& d : directions) {
                    if (adjRolls > 3) {
                        break;
                    }
                    // get new r, c
                    int newRow = r + d.dr;
                    int newCol = c + d.dc;
                    // verify cell is within bounds
                    if (newRow >= 0 && newRow < rows && 
                        newCol >= 0 && newCol < cols) {
                        // check count criteria
                        if (grid[newRow][newCol] == paperRoll) {
                            ++adjRolls;
                        }
                    }
                }
                if (adjRolls < 4) {
                    ++numRolls;
                }
            }
        }
    }
    return numRolls;
}

std::uint64_t partTwo(std::vector<std::string> &grid) {
    /*
        Once a roll of paper can be accessed by a forklift, it can be removed. Once a roll of paper is removed, 
        the forklifts might be able to access more rolls of paper, which they might also be able to remove. 
        How many total rolls of paper could the Elves remove if they keep repeating this process?
            - repeat roll search while removing rolls until no more rolls can be removed
    */

    const char removedRoll = 'x';

    const int cols = grid[0].size();
    const int rows = grid.size();
    
    bool removed = true;

    std::uint64_t numRemoved = 0;

    while (removed) {
        removed = false;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // check if cell is @
                if (grid[r][c] == paperRoll) { 
                    int adjRolls = 0;
                    // check each direction
                    for (const auto& d : directions) {
                        if (adjRolls > 3) {
                            break;
                        }
                        // get new r, c
                        int newRow = r + d.dr;
                        int newCol = c + d.dc;
                        // verify cell is within bounds
                        if (newRow >= 0 && newRow < rows && 
                            newCol >= 0 && newCol < cols) {
                            // check count criteria
                            if (grid[newRow][newCol] == paperRoll) {
                                ++adjRolls;
                            }
                        }
                    }
                    if (adjRolls < 4) {
                        ++numRemoved;
                        grid[r][c] = removedRoll;
                        removed = true;
                    }
                }
            }
        }
    }
    return numRemoved;
}

int main() {
    std::vector<std::string> grid;
    std::string row;
    std::ifstream file("../src/day-4/input.txt");

    if (!file) {
        std::cerr << "Failed to open file!" << std::endl;
        return -1;
    }
    
    // read input
    while(std::getline(file, row)) {
        grid.push_back(row);
    }

    std::uint64_t partOneResult = partOne(grid);
    std::cout << "Maximum paper rolls: "<< partOneResult << std::endl;

    std::uint64_t partTwoResult = partTwo(grid);
    std::cout << "Removable rolls: "<< partTwoResult << std::endl;

    return 0;
}
