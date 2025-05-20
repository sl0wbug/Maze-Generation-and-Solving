#pragma once
#include <vector>

class MazeGenerator {
private:
    int rows, cols;
    std::vector<std::vector<char>> maze;
    void dfs(int x, int y);

public:
    MazeGenerator(int r, int c);
    void generateMaze();
    void printMaze();
    std::vector<std::vector<char>> getMaze();
};

