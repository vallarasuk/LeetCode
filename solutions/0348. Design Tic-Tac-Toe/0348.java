class TicTacToe {
  public TicTacToe(int n) {
    this.n = n;
    rows = new int[n];
    cols = new int[n];
  }

  /**
   * Player {player} makes a move at ({row}, {col}).
   *
   * @param row    The row of the board.
   * @param col    The column of the board.
   * @param player The player, can be either 1 or 2.
   * @return The current winning condition, can be either: 0: No one wins. 1:
   *         Player 1 wins. 2: Player 2 wins.
   */
  public int move(int row, int col, int player) {
    final int toAdd = player == 1 ? 1 : -1;
    final int target = player == 1 ? n : -n;

    if (row == col) {
      diagonal += toAdd;
      if (diagonal == target)
        return player;
    }

    if (row + col == n - 1) {
      antiDiagonal += toAdd;
      if (antiDiagonal == target)
        return player;
    }

    rows[row] += toAdd;
    if (rows[row] == target)
      return player;

    cols[col] += toAdd;
    if (cols[col] == target)
      return player;

    return 0;
  }

  private int n;
  // record count('X') - count('O')
  private int[] rows;
  private int[] cols;
  private int diagonal = 0;
  private int antiDiagonal = 0;
}