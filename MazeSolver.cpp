#include "MazeSolver.h"
#include <iostream>

using namespace std;

MazeSolver::MazeSolver() {
    maze = {
        {1, 0, 0},
        {1, 1, 0},
        {0, 1, 1}
    };

    rows = maze.size();
    cols = maze[0].size();
    visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
}

bool MazeSolver::isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols &&
           maze[x][y] == 1 && !visited[x][y];
}

bool MazeSolver::dfs(int x, int y) {
    if (x == rows - 1 && y == cols - 1) {
        path.push_back({x, y});
        return true;
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY) && dfs(newX, newY)) {
            path.push_back({x, y});
            return true;
        }
    }

    return false;
}

void MazeSolver::solve() {
    if (dfs(0, 0)) {
        cout << "Path found using DFS:\n";
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            cout << "(" << it->first << "," << it->second << ") ";
        }
        cout << endl;
    } else {
        cout << "No path found!" << endl;
    }
}

