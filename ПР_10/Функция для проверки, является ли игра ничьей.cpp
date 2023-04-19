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