#include"game.h"
void menu()
{
	printf("**************************\n");
	printf("*******   1.play   *******\n");
	printf("*******   0.exit   *******\n");
	printf("**************************\n");
}
void game()
{
	char result;
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		PlayerMove(board, ROW, COL);
		result = IsWin(board, ROW, COL);
		if (result != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		ComeputMove(board, ROW, COL);
		result = IsWin(board, ROW, COL);
		if (result != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
		if (result == '*')
		{
			printf("玩家胜利！\n");
			DisplayBoard(board, ROW, COL);
		}
		else if (result == '#')
		{
			printf("电脑胜利！\n");
			DisplayBoard(board, ROW, COL);
		} 
		else
		{
			printf("平局\n");
		}
	
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();//菜单，选择界面
		printf("请输入:>");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				game();//游戏
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
		}
	} while (input);
	return 0;
}