#include <iostream>
#include "MazeGenerator.h"
#include "MazeSolver.h"

int main() {
    int rows, cols;
    std::cout << "Enter number of rows and columns: ";
    std::cin >> rows >> cols;

    MazeGenerator generator(rows, cols);
    generator.generateMaze();
    generator.printMaze();

    char choice;
    std::cout << "Do you want to solve the maze? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        std::cout << "Choose algorithm:\n1. BFS\n2. DFS (not implemented)\nEnter choice: ";
        int algoChoice;
        std::cin >> algoChoice;

        MazeSolver solver(generator.getMaze(), rows, cols);
        if (algoChoice == 1) {
            solver.solveWithBFS();
        } else {
            std::cout << "Only BFS is implemented right now.\n";
        }
    }

    return 0;
}
