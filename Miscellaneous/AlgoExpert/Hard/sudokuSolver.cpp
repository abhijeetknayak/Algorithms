#include <vector>
using namespace std;

#define ROWS 9
#define COLS 9

bool isValidAtPosition(int value, int row, int col, vector<vector<int>> board);
bool tryNumberAtPosition(int row, int col, vector<vector<int>>& board);
bool recursive_helper(int row, int col, vector<vector<int>>& board);


bool isValidAtPosition(int value, int row, int col, vector<vector<int>> board) {
	for (int i = 0; i < COLS; i++) { if (board[row][i] == value) return false; }
	for (int i = 0; i < ROWS; i++) { if (board[i][col] == value) return false; }
	
	int rowStart = row / 3, colStart = col / 3;
	int rowEnd = rowStart * 3 + 3, colEnd = colStart * 3 + 3;
	for (int i = rowStart * 3; i < rowEnd; i++) {
		for (int j = colStart * 3; j < colEnd; j++) {
			if (board[i][j] == value) return false;
		}
	}
	return true;
}

bool tryNumberAtPosition(int row, int col, vector<vector<int>>& board) {
	for (int num = 1; num <= 9; num++) {
		if (isValidAtPosition(num, row, col, board)) {
			board[row][col] = num;
			if (recursive_helper(row, col + 1, board)) return true;
		} 
	}
	board[row][col] = 0;
	return false;
}

bool recursive_helper(int row, int col, vector<vector<int>>& board) {
	int currentRow = row, currentCol = col;
	if (currentCol == board[0].size()) {
		currentCol = 0;
		currentRow += 1;
		if (currentRow == board.size()) return true;
	}
	
	if (board[currentRow][currentCol] == 0) return tryNumberAtPosition(currentRow, currentCol, board);
	
	return recursive_helper(currentRow, currentCol + 1, board);
}

vector<vector<int>> solveSudoku(vector<vector<int>> board) {
	recursive_helper(0, 0, board);
  return board;
}
