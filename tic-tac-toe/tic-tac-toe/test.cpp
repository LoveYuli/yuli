#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("*************��������Ϸ***************\n");
	printf("***ѡ��1��������Ϸ��ѡ��0���˳���Ϸ***\n");
	printf("**************************************\n");
	printf("��ѡ��>");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board,ROW,COL);//��ʼ������
	DisplayBoard(board, ROW, COL);//��������
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
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
        printf("ƽ��\n");
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
		}
	} while (input);
}
int IsFull(char board[ROW][COL], int row, int col)//����1��ʾ�������ˣ�0��ʾ����û��
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