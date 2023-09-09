#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("*************三子棋游戏***************\n");
	printf("***选“1”进入游戏，选“0”退出游戏***\n");
	printf("**************************************\n");
	printf("请选择：>");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board,ROW,COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);//画出棋盘
	while (1)
	{
    PlayerMove(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	ret = IsWin(board, ROW, COL);
	if (ret != 'C')
	{
		break;
	}
	ComputerMove(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	ret= IsWin(board, ROW, COL);
	if (ret != 'C')
	{
		break;
	}
	
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
        printf("平局\n");
	}
		
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
		}
	} while (input);
}
int IsFull(char board[ROW][COL], int row, int col)//返回1表示棋盘满了，0表示棋盘没满
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
int main()
{
	test();
	return 0;
}