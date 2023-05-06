#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 3;
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

// Функция печати доски Tic-Tac-Toe
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для проверки, выиграл ли игрок
bool checkWin(const vector<vector<char>>& board, char player) {
    // Проверить строки
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    // Проверить столбцы
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }

    // Проверить диагонали
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Функция для проверки, является ли игра ничьей
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY)
                return false;
        }
    }
    return true;
}

// Функция, чтобы сделать ход на доске Tic-Tac-Toe
void makeMove(vector<vector<char>>& board, int row, int col, char player) {
    board[row][col] = player;
}

// Функция для оценки текущего состояния доски
int evaluate(const vector<vector<char>>& board) {
    if (checkWin(board, PLAYER_X))
        return -1;
    else if (checkWin(board, PLAYER_O))
        return 1;
    else
        return 0;
}

// Минимаксная функция для нахождения наилучшего результата для заданного состояния доски.
int minimax(vector<vector<char>>& board, int depth, bool isMaximizingPlayer) {
    int score = evaluate(board);

    if (score != 0)
        return score;

    if (checkDraw(board))
        return 0;

    if (isMaximizingPlayer) {
        int bestScore = -1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O;
                    int score = minimax(board, depth + 1, false);
                    board[i][j] = EMPTY;
                    bestScore = max(bestScore, score);
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = 1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_X;
                    int score = minimax(board, depth + 1, true);
                    board[i][j] = EMPTY;
                    bestScore = min(bestScore, score);
                }
            }
        }
        return bestScore;
    }
}

// Функция поиска наилучшего хода с использованием алгоритма Минимакс
void findBestMove(vector<vector<char>>& board) {
    int bestScore = -1000;
    int bestRow = -1;
    int bestCol = -1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_O;
                int score = minimax(board, 0, false);
                board[i][j] = EMPTY;
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }

    makeMove(board, bestRow, bestCol, PLAYER_O);
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<vector<char>> board(SIZE, vector<char>(SIZE, EMPTY));
    // Основной игровой цикл
    bool gameOver = false;
    char currentPlayer = PLAYER_X;
    // вывод поля
    cout << " 0 0" << " | " << "0 1" << " | " << "0 2" << endl;
    cout << "_____|_____|_____" << endl;
    cout << " 1 0" << " | " << "1 1" << " | " << "1 2" << endl;
    cout << "_____|_____|_____" << endl;
    cout << " 2 0" << " | " << "2 1" << " | " << "2 2" << endl;
    cout << "     |     |  " << endl;
    while (!gameOver) {
        printBoard(board);

        if (currentPlayer == PLAYER_X) {
            int row, col;
            cout << "Игрок X, введите свой ход (строка и столбец разделены пробелом):";
            cin >> row >> col;

            if (board[row][col] == EMPTY) {
                makeMove(board, row, col, PLAYER_X);
                currentPlayer = PLAYER_O;
            }
            else {
                cout << "Неверный ход. Пожалуйста, попробуйте еще раз." << endl;
            }
        }
        else {
            findBestMove(board);
            currentPlayer = PLAYER_X;
        }

        // Проверить условия игры
        if (checkWin(board, PLAYER_X)) {
            printBoard(board);
            cout << "Игрок X выигрывает!" << endl;
            gameOver = true;
        }
        else if (checkWin(board, PLAYER_O)) {
            printBoard(board);
            cout << "Игрок О побеждает!" << endl;
            gameOver = true;
        }
        else if (checkDraw(board)) {
            printBoard(board);
            cout << "Это ничья!" << endl;
            gameOver = true;
        }
    }

    return 0;
}