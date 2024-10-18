#include <iostream>
#include <stack>
#include <cstring>  // for memcpy

using namespace std;
#define N 12

// Cell structure to represent a position in the maze
struct Cell {
    int row;
    int col;
};

// Function to display the current state of the maze
void display(char maze[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << maze[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool findPath (char maze[N][N], char visited[N][N], Cell* current, Cell* end) {
    // Base case, if current cell is the end, return true
    if (current->row == end->row && current->col == end->col) {
        return true;
    }

    // Mark the current cell as visited
    visited[current->row][current->col] = 'v';

    // Display the current state of the maze
    display(visited);

    // Define the possible moves: up, down, left, right
    int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; ++i) {
        int newRow = current->row + moves[i][0];
        int newCol = current->col + moves[i][1];

        // Check if new position is within bounds, not a wall, not visited
        if (newRow >= 0 && newRow < N && newCol >= 0 && maze[newRow][newCol] == '.' && visited[newRow][newCol] != 'v') {
            // Create a new cell for the new position
            Cell next = {newRow, newCol};

            // Recursively call findPath with the new position
            if (findPath(maze, visited, &next, end)) {
                return true; // If the path is found, return true
            }
        }
    }
    // If no path is found, backtrack
    visited[current->row][current->col] = '.';
    return false;
}

int main() {
    // Original maze
    char maze[N][N] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
        {'#', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '.', '#', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '.', '#', '#', '#', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
    
    // Visited array to keep track of the path
    char visited[N][N];
    memcpy(visited, maze, sizeof(maze));  // Copy original maze to visited array

    // Starting and ending points
    Cell start = {1, 1};  // Start position
    Cell end = {10, 10};  // End position

    // Start the recursive backtracking from the start cell
    if (findPath(maze, visited, &start, &end)) {
        std::cout << "Path found!" << std::endl;
    } else {
        std::cout << "No path found!" << std::endl;
    }

    // Final display of the maze with the path
    display(visited);

    return 0;
}