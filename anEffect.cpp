#include <iostream>
#include <vector>
#include <random>
#include <unistd.h>
using namespace std;

void clearScreen() {
    cout << "\033[H"; // move cursor to (1, 1)
    cout << "\033[J"; // Clear everything
    cout.flush();
}

void printGrid(const vector<vector<char>>& grid) {
    clearScreen();
    for(int r = 0; r < grid.size(); r++) {
        for(int c = 0; c < grid[0].size(); c++) {
            cout << grid[r][c];
        }
        cout << endl;
    }
}

void generateMatrix(vector<vector<char>>& grid, int ROWS, int COLS) {
    
    // reset the grid
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            grid[r][c] = ' ';
        }
    }
    
    // put a star at a random position in the grid
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distRow(0, ROWS - 1);
    uniform_int_distribution<int> distCol(0, COLS - 1);
    
    int starRow = distRow(gen);
    int starCol = distCol(gen);
    
    grid[starRow][starCol] = '*';
}

void anEffect(int ROWS=10, int COLS=10) {
    vector<vector<char>> grid(ROWS, vector<char>(COLS, ' '));
    
    for(int i = 0; i < 10; i++) {
        generateMatrix(grid, ROWS, COLS);
    
        printGrid(grid);
        sleep(1);
    }
}

int main() {
    // Write C++ code here
    anEffect();

    return 0;
}
