/**
1.Magnus Carlsen,has finally managed to write a program to solve the N queens problem.
However, his version of the N queens problem is not really all that similar to the classical one.

Recall that in the N queens problem, there is a square chessboard of size NxN.
The goal is to put N queens on the chessboard so that no two queens would be able to attack each other.

In Magnus's version of the problem (which he states to be "much harder" than the original one),
there are K "blocked" squares given on the chessboard. The goal is still the same:
to put N queens on the chessboard such that no two queens would be able to attack each other.
However, there are some differences due to the existence of blocked squares.
First, a queen cannot be put on a blocked square.
Secondly, two queens are considered to be able to attack each other only if there
is no blocked square between them. Finally, there must be exactly one queen on
every column of the board.

Magnus claims that his program solves the above problem very effectively.
He generates some test cases (which his program can solve within minutes) to challenge you.
You know the method Magnus used to generate the test case.
For a given N, Magnus randomly picks a number K between 1 and N2/2 with equal probability.
After that, Magnus picks K blocked squares on the chess board. Any combinations
of K squares can be picked with equal probability.

Write a program that can solve Magnus's test cases within seconds.
*/


#include <stdio.h>

int ROW_OFFSET[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int COL_OFFSET[] = {0, 1, 1, 1, 0, -1, -1, -1};

// Function to fill up queen space and its attack area
void fillBoard(int N, int row, int col, int* board, int dir){
  if(dir == 8){
    *(board + col + (row*N)) = 2;
    for(int i=0;i<8;i++){
      fillBoard(N, row+ROW_OFFSET[i], col+COL_OFFSET[i], board, i);
    }
  } else {
    if(*(board + col + (row*N)) != -1 && row >= 0 && row < N && col >= 0 && col < N)
    {
      *(board + col + (row*N)) = 1;
      fillBoard(N, row+ROW_OFFSET[dir], col+COL_OFFSET[dir], board, dir);
    }
  }
}

// recursive function to set queens
short fillQueen(int N, int col, int* board){
  int answer[N][N];

  if(col == N-1) {
    for(int i=0; i<N; i++) {
      if(*(board + col + (i*N)) == 0) {
        *(board + col + (i*N)) = 2;
        return 1;
      }
    }
    return 0;
  }
  for(int i=0; i<N; i++){
    if(*(board + col + (i*N)) == 0){
      for(int j=0;j<N*N; j++) *(&answer[0][0] + j) = *(board + j); //Make a copy for each iteration
      fillBoard(N, i, col, &answer[0][0], 8);
      if(fillQueen(N, col+1, &answer[0][0])){
        for(int j=0;j<N*N; j++) *(board + j) = *(&answer[0][0] + j); //Copy back upon true;
        return 1;
      }
    }
  }
  return 0;
}


int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int N,K;
    scanf("%d %d",&N, &K);
    int board[N][N];
    for(int i=0;i<N*N;i++) *(&board[0][0] + i) = 0;
    for(int i=0;i<K;i++){
      int tmp1, tmp2;
      scanf("%d %d", &tmp1, &tmp2);
      board[tmp1-1][tmp2-1] = -1;
    }

    fillQueen(N, 0, &board[0][0]);

    int queens[N];
    for(int i=0; i<N;i++){
      for(int j=0;j<N;j++){
        if(board[j][i] == 2) queens[i] = j+1;
      }
    }

    for(int i=0;i<N;i++) printf("%d ",queens[i]);
  }
  return 0;
}
