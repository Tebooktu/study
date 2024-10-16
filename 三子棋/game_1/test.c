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
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
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
			printf("���ʤ����\n");
			DisplayBoard(board, ROW, COL);
		}
		else if (result == '#')
		{
			printf("����ʤ����\n");
			DisplayBoard(board, ROW, COL);
		} 
		else
		{
			printf("ƽ��\n");
		}
	
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();//�˵���ѡ�����
		printf("������:>");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				game();//��Ϸ
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("�����������������\n");
				break;
		}
	} while (input);
	return 0;
}