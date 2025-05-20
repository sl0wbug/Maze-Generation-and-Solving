#include "MazeGenerator.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

MazeGenerator::MazeGenerator(int r, int c) : rows(r), cols(c) {
    maze.resize(2 * rows + 1, std::vector<char>(2 * cols + 1, '#'));
}

void MazeGenerator::dfs(int x, int y) {
    int dx[] = {0, 0, 2, -2};
    int dy[] = {2, -2, 0, 0};
    std::vector<int> dir = {0, 1, 2, 3};
    std::random_shuffle(dir.begin(), dir.end());

    for (int i : dir) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx > 0 && ny > 0 && nx < 2 * rows && ny < 2 * cols && maze[nx][ny] == '#') {
            maze[nx][ny] = ' ';
            maze[x + dx[i] / 2][y + dy[i] / 2] = ' ';
            dfs(nx, ny);
        }
    }
}

void MazeGenerator::generateMaze() {
    srand(time(0));
    maze[1][1] = ' ';
    dfs(1, 1);
    maze[0][1] = 'S'; // Start
    maze[2 * rows][2 * cols - 1] = 'E'; // End
}

void MazeGenerator::printMaze() {
    for (auto &row : maze) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << '\n';
    }
}

std::vector<std::vector<char>> MazeGenerator::getMaze() {
    return maze;
}

