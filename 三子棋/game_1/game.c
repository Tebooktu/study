#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i; i < row; i++)
	{
		int j = 0;
		//board[i][0] = 'c'; board[i][1] = 'c'; board[i][2] = ' ';
		for (j; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i; i < row; i++)
	{
		int j = 0;
		/*printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if(i<row-1)
		printf("---|---|---\n");*/
		for (j; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col-1)
			{
				printf("|");
			}
			
		}
		printf("\n");
		if (i < row-1)
		{
			int j = 0;
			for (j; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("玩家行动：>");
	while (1)
	{
		int x = 1;
		int y = 1;
		scanf("%d %d", &x, &y);
		if (x>=1&&x <= row && y>=1&&y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该位置已被占用，请重新输入：>");
		}
		else
				printf("超出范围，请重新输入:>");
	}
}
void ComeputMove(char board[ROW][COL], int row, int col)
{
	printf("电脑行动：\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i; i < row; i++)
	{
		int j = 0;
		for (j; j < col; j++)
		{
			if (board[i][j] == ' ')
			    return 0;
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
	//行
	int i = 0;
	for (i; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	//列
	int j = 0;
	for (j; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
			return board[0][j];
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	//平局
	if (IsFull(board, row, col))
	{
		return 'Q';
	}
	//游戏继续
    return 'c';
}



