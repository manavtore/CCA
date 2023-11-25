#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(vector<vector<int>>& board, int row) {
    if (row == N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            board[row][i] = 1;
            if (solveNQUtil(board, row + 1))
                return true;
            board[row][i] = 0;
        }
    }

    return false;
}

void solveNQ() {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQUtil(board, 0))
        cout << "Solution does not exist";
    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
}

int main() {
    solveNQ();
    return 0;
}
