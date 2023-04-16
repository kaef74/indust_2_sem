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
