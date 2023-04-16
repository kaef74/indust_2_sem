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
