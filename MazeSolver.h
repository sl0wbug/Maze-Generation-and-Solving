
#pragma once
#include <vector>

class MazeSolver {
private:
    std::vector<std::vector<char>> maze;
    int rows, cols;

public:
    MazeSolver(std::vector<std::vector<char>> m, int r, int c);
    void solveWithBFS();
};
