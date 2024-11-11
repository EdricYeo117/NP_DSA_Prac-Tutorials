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
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool findPathWithStack(char maze[N][N], char visited[N][N], Cell start, Cell end) {
    // Stack to keep track of the path
    stack<Cell> pathStack;
    // Push the starting cell onto the stack
    pathStack.push(start);

    // Mark the starting cell as visited
    visited[start.row][start.col] = 'v';

    // Define the possible moves: up, down, left, right
    int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Loop until the stack is empty
    while (!pathStack.empty()) {
        // Get the current cell from the top of the stack
        Cell current = pathStack.top();

        // Check if we've reached the end cell
        if (current.row == end.row && current.col == end.col) {
            return true;
        }

        bool moved = false;

        // Try to move in all possible directions
        for (int i = 0; i < 4; ++i) {
            // Calculate the new position
            int newRow = current.row + moves[i][0];
            int newCol = current.col + moves[i][1];

            // Check if the new position is within bounds and is not visited or a wall
            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N &&
                maze[newRow][newCol] == '.' && visited[newRow][newCol] != 'v') {
                
                // Mark the cell as visited and push it onto the stack
                visited[newRow][newCol] = 'v';
                pathStack.push({newRow, newCol});
                moved = true;

                // Display the current state of the maze
                display(visited);
                break;
            }
        }

        // If no move was possible (dead-end), backtrack by popping from the stack
        if (!moved) {
            pathStack.pop();
        }
    }

    return false; // If we exit the loop, no path was found
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

    // Start the stack-based pathfinding from the start cell
    if (findPathWithStack(maze, visited, start, end)) {
        cout << "Path found!" << endl;
    } else {
        cout << "No path found!" << endl;
    }

    // Final display of the maze with the path
    display(visited);

    return 0;
}
