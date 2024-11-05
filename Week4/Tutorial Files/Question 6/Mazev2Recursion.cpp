#include <iostream>
#include <cstring>  // for memcpy

using namespace std;

#define N 12

// Cell structure to represent a position in the maze
struct Cell {
    int row;
    int col;
};

// MazeSolver class to handle all maze operations
class MazeSolver {
private:
    char maze[N][N];
    char visited[N][N];
    Cell start;
    Cell end;

    // Display the current state of the maze
    void display() const {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << visited[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    // Check if the move is valid
    bool isValidMove(int row, int col) const {
        return (row >= 0 && row < N &&
                col >= 0 && col < N &&
                maze[row][col] == '.' &&
                visited[row][col] != 'v');
    }

    // Recursive function to find the path
    bool findPathRecursive(const Cell &current) {
        // Base case: if current cell is the end, return true
        if (current.row == end.row && current.col == end.col) {
            return true;
        }

        // Mark the current cell as visited
        visited[current.row][current.col] = 'v';
        display();

        // Define the possible moves: up, down, left, right
        int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; ++i) {
            int newRow = current.row + moves[i][0];
            int newCol = current.col + moves[i][1];

            // Check if new position is a valid move
            if (isValidMove(newRow, newCol)) {
                Cell next = {newRow, newCol};
                if (findPathRecursive(next)) {
                    return true;  // If path found, return true
                }
            }
        }

        // If no path is found, backtrack
        visited[current.row][current.col] = '.';
        return false;
    }

public:
    // Constructor to initialize the maze solver
    MazeSolver(char initialMaze[N][N], Cell start, Cell end)
        : start(start), end(end) {
        memcpy(maze, initialMaze, sizeof(maze));
        memcpy(visited, initialMaze, sizeof(maze));
    }

    // Find the path from start to end
    bool findPath() {
        return findPathRecursive(start);
    }

    // Display the final result
    void displayResult() const {
        display();
    }
};

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

    // Starting and ending points
    Cell start = {1, 1};  // Start position
    Cell end = {10, 10};  // End position

    // Create a MazeSolver object and solve the maze
    MazeSolver solver(maze, start, end);

    if (solver.findPath()) {
        cout << "Path found!" << endl;
    } else {
        cout << "No path found!" << endl;
    }

    // Final display of the maze with the path
    solver.displayResult();

    return 0;
}
