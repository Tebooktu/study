#include<stdio.h>
#include<time.h>
#define ROW 3
#define COL 3
//≥ı ºªØ∆Â≈Ã
void InitBoard(char board[ROW][COL], int row, int col);
//¥Ú”°∆Â≈Ã
void DisplayBoard(char board[ROW][COL], int row, int col);
//œ¬∆Â
void PlayerMove(char board[ROW][COL],int row,int col);
void ComeputMove(char board[ROW][COL], int row, int col);
//≈–∂œ ‰”Æ
char IsWin(char board[ROW][COL], int row, int col);
