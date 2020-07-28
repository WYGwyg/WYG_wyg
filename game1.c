#include"game.h"
void Menu()
{
	printf("############################################################\n");
	printf("************************************************************\n");
	printf("************************************************************\n");
	printf("***********        ��ӭ�����ҵ���Ϸ����        *************\n");
	printf("*********1��������                        2��ɨ��***********\n");
	printf("*********                                        ***********\n");
	printf("*********3��������                        4���˳�***********\n");
	printf("************************************************************\n");
	printf("************************************************************\n");
	printf("############################################################\n");
	printf("Please Enter select!!!\n");
}
Init_board(char board[][COL], int row, int col)//���������̳�ʼ��--->ȫΪ��
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}
Show_board(char board[][COL], int row, int col)//��ʾ����������
{
	printf("   | 1 | 2 | 3 |\n");
	printf("----------------\n");
	int i = 1;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		printf(" %d |", i);
		for (j = 0; j < col; j++)
		{
			printf(" %c |", board[i-1][j]);
		}
		printf("\n----------------\n");
	}
}
Computer(char board[][COL], int row, int col)//��������ĵ�������
{
	while (1)
	{
		int x = rand() % ROW;
		int y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = computer;
			break;
		}
	}
}
Judge(char board[][COL], int row, int col)//�����������ж�˭Ӯ˭��
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] != ' '&&\
			board[i][0] == board[i][1] && \
			board[i][1] == board[i][2])
			return board[i][0];
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] != ' '&&\
			board[0][i] == board[1][i] && \
			board[1][i] == board[2][i])
			return board[0][i];
	}
	if (board[1][1] != ' ' &&\
		board[0][0] == board[1][1] && \
		board[1][1] == board[2][2])
	{
		return board[1][1];
	}
	if (board[1][1] != ' ' &&\
		board[0][2] == board[1][1] && \
		board[1][1] == board[2][0])
	{
		return board[1][1];
	}
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'N';
			}
		}
	}
	return 'F';
}
void game()//��������Ҫ���
{
	printf(" --------------------------------------- \n");
	printf("| ��ӭ������������Ϸ��ף����ˣ�����!!! |\n");
	printf(" --------------------------------------- \n");
	srand((unsigned long)time(NULL));
	char board[ROW][COL];
	Init_board(board, ROW, COL);//���̳�ʼ��
	Show_board(board, ROW, COL);//��ʾ����
	char result = 0;
	do
	{
		int x = 0;
		int y = 0;
		printf("������<x,y>������:\n");
		scanf("%d %d", &x, &y);
		if (x<0 || x>3 || y<0 || y>3)
		{
			printf("������λ����������������:\n");
			continue;
		}
		if (board[x - 1][y - 1] != ' ')
		{
			printf("�������λ���ѱ�ռ�У�����������:\n");
			continue;
		}
		board[x - 1][y - 1] = player;
		result = Judge(board, ROW, COL);//�жϽ������
		Show_board(board, ROW, COL);
		system("cls");
		if (result != 'N')
		{
			break;
		}
		Computer(board, ROW, COL);
		result = Judge(board, ROW, COL);
		Show_board(board, ROW, COL);
		if (result != 'N')
		{
			break;
		}
	} while (1);
	if (result == player)
	{
		printf("��ϲ�㣬��Ӯ��!!!\n");
	}
	else if (result == computer)
	{
		printf("������˼��������!!!\n");
	}
	else
	{
		printf("������ƽ��!!!\n");
	}
	printf("����Ļ�����Ҫ��Ҫ����һ��!!!\n");
}
void set_mine(char board[][COL1], int row1, int col1, int *x_p, int *y_p)//ɨ����Ϸ����
{
	int num = 80;
	while (num > 0)
	{
		int x = rand() % (row1 - 2) + 1;
		int y = rand() % (col1 - 2) + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			num--;
		}
	}
	int i = 1;
	int j = 1;
	for (i = 1; i < 11; i++)
	{
		for (j = 1; j < 11; j++)
		{
			if (board[i][j] == '0')
			{
				*x_p = i;
				*y_p = j;
				return;
			}
		}
	}
}
void showboard(char board[][COL1], int row1, int col1)//��ʾɨ������
{
	printf("    |");
	int i = 1;
	for (i = 1; i < 11; i++)
	{
		printf(" %d |", i);
	}
	printf("\n");
	printf("--------------------------------------------\n");
	for (i = 1; i < 11; i++)
	{
		printf(" %2d |", i);
		int j = 0;
		for (j = 0; j < 10; j++)
		{
			printf(" %c |", board[i-1][j]);
		}
		printf("\n");
		printf("--------------------------------------------\n");
	}
}
int Getcount(char board[][COL1], int x, int y)//��ʾ��Χ�׵ĸ���
{
	return board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] + board[x][y - 1] + \
		board[x][y + 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0';
}
void Game()//ɨ��
{
	printf(" ------------------------------------- \n");
	printf("| ��ӭ����ɨ����Ϸ��ף����ˣ�����!!! |\n");
	printf(" ------------------------------------- \n");
	srand((unsigned long)time(NULL));
	char mine_board[ROW1][COL1];
	char show_board[ROW1][COL1];
	memset(mine_board, '0', sizeof(mine_board));//��ʼ��������
	memset(show_board, '*', sizeof(show_board));//��ʼ���û�����
	int no_x = 0;
	int no_y = 0;
	set_mine(mine_board, ROW1, COL1, &no_x, &no_y);//����
	int x = 0;
	int y = 0;
	int time = 80;
	while (time > 0)
	{
		system("cls");
		showboard(show_board, ROW1, ROW1);//��ʾ�û�����
		printf("������<x,y>�����꣺\n");
		scanf("%d %d", &x, &y);
		if (x <= 0 || x > 10 || y <= 0 || y > 10)
		{
			printf("������λ����������������:\n");
			continue;
		}
		if (show_board[x-1][y-1] != '*')
		{
			printf("�õط��ѱ��ų�������������:\n");
			continue;
		}
		if (mine_board[x-1][y-1] == '1')
		{
			if (time == 80)
			{
				mine_board[x - 1][y - 1] = '0';
				showboard(mine_board, ROW1, COL1);
				break;
			}
		}
		int count = Getcount(mine_board,x, y);//ͳ�Ƹõ���Χ�׵ĸ���
		show_board[x - 1][y - 1] = count + '0';
		time--;
	}
}
void play()//��������Ϸ
{
	int n = rand() % 100 + 1;
	int x = 0;
	do
	{
		printf("����������µ�ֵ:\n");
		scanf("%d", &x);
		if (x > n)
		{
			printf("������˼����´���!!!\n");
		}
		else if (x < n)
		{
			printf("������˼�����С��!!1\n");
		}
		else
		{
			printf("��ϲ�㣬��¶���!!!\n");
			break;
		}
	} while (1);
}
void GAme()
{
	printf(" -------------------------------------------- \n");
	printf("|��ӭ��������������Ϸ,�뿪ʼ��ı��ݣ�����!!!|\n");
	printf(" -------------------------------------------- \n");
	srand((unsigned long)time(NULL));
	play();
}