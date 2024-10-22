#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	while (1)
	{
		printf("你的电脑将于60秒后关机，请输入正确口令取消程序！\n");
		scanf("%s", input);
		if (strcmp(input, "别搞，不关") == 0)
		{
			system("cls");
			system("shutdown -a");
			printf("关机取消！\n");
			break;
		}
	}
	return 0;
}