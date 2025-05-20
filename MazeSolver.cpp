#include "MazeSolver.h"
#include <iostream>
#include <queue>

MazeSolver::MazeSolver(std::vector<std::vector<char>> m, int r, int c)
    : maze(m), rows(2 * r + 1), cols(2 * c + 1) {}

void MazeSolver::solveWithBFS() {
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::vector<std::vector<std::pair<int, int>>> parent(rows, std::vector<std::pair<int, int>>(cols, {-1, -1}));

    q.push({0, 1});
    visited[0][1] = true;

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    std::pair<int, int> end = {-1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (maze[x][y] == 'E') {
            end = {x, y};
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
                maze[nx][ny] != '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (end.first == -1) {
        std::cout << "No path found.\n";
        return;
    }

    // Mark path
    auto p = end;
    while (p != std::make_pair(0, 1)) {
        if (maze[p.first][p.second] == ' ') {
            maze[p.first][p.second] = '.';
        }
        p = parent[p.first][p.second];
    }

    std::cout << "Solved Maze:\n";
    for (auto &row : maze) {
        for (char cell : row)
            std::cout << cell;
        std::cout << '\n';
    }
}

