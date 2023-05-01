

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void print_board() {
  printf("\n-------------\n");
  for (int i = 0; i < 3; i++) {
    printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
    printf("-------------\n");
  }
}

bool check_winner() {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2] &&
        board[i][0] != ' ')
      return true;
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i] &&
        board[0][i] != ' ')
      return true;
  }
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] &&
      board[0][0] != ' ')
    return true;
  if (board[0][2] == board[1][1] && board[0][2] == board[2][0] &&
      board[0][2] != ' ')
    return true;
  return false;
}

void play_game() {
  char player1 = '1';
  char player2 = 'O';
  char current_player = player1;
  bool winner = false;
  printf("Welcome to Tic Tac Toe\n");
  print_board();
  while (!winner) {
    int row, col;
    printf("Enter row (0-2) for %c: ", current_player);
    scanf("%d", &row);
    printf("Enter column (0-2) for %c: ", current_player);
    scanf("%d", &col);
    if (board[row][col] != ' ') {
      printf("This position is already taken. Try again!\n");
      continue;
    }
    board[row][col] = current_player;
    print_board();
    winner = check_winner();
    if (winner) {
      printf("Congratulations %c! You have won the game!\n", current_player);
      break;
    }
    bool tie = true;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == ' ') {
          tie = false;
          break;
        }
      }
      if (!tie)
        break;
    }
    if (tie) {
      printf("It's a tie!\n");
      break;
    }
    current_player = (current_player == player1) ? player2 : player1;
  }
}

int main() {
  play_game();
  return 0;
}
