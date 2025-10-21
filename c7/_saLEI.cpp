#include "saLEI.h"
//ǰͷ
void meun() {
	printf("����������������������������������������\n");
	printf("������������1.  play��������������������\n");
	printf("������������0.  exit��������������������\n");
	printf("����������������������������������������\n");
}
//��ʼ������
void initial_board(char board[ROWS][COLS], int rows, int cols, char set) {
	int i = 0; int j = 0;
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			board[i][j] = set;
}
//��ӡ����
void display_board(char board[ROWS][COLS], int row, int col) {
	printf("���������������� SA-LEI ������������������\n");
	int i = 0; int j = 0;
	for (j = 0; j <= col; j++) {
		printf("%d ", j);//��ӡ�к�
	}	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);//��ӡ�к�
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//����
void set_mine(char board[ROWS][COLS], int row, int col) {
	int count = FV_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//ͳ�Ʒ��񼸸��� 	
int get_mine_count(char board[ROWS][COLS], int x, int y) {
	return(   board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1]
			+ board[x]    [y - 1]                   + board[x]    [y + 1]
			+ board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1]
			- 8  *  '0');
}			//��1��askii��-��0��askii��= ����1		
//���������������������������������õݹ��ų���Χû���׵����򡪡���������������������
static void no_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int ret = get_mine_count(mine, x, y);
	if (ret == 0)
	{
		show[x][y] = ' ';
		if ((x - 1) > 0 && (y - 1) > 0 && (show[x - 1][y - 1] == '*'))
			no_mine(mine, show, x - 1, y - 1);
		if ((x - 1) > 0 && (y) > 0 && (show[x - 1][y] == '*'))
			no_mine(mine, show, x - 1, y);
		if ((x - 1) > 0 && (y + 1) > 0 && (show[x - 1][y + 1] == '*'))
			no_mine(mine, show, x - 1, y + 1);
		if ((x) > 0 && (y - 1) > 0 && (show[x][y - 1] == '*'))
			no_mine(mine, show, x, y - 1);
		if ((x) > 0 && (y + 1) > 0 && (show[x][y + 1] == '*'))
			no_mine(mine, show, x, y + 1);
		if ((x + 1) > 0 && (y - 1) > 0 && (show[x + 1][y - 1] == '*'))
			no_mine(mine, show, x + 1, y - 1);
		if ((x + 1) > 0 && (y) > 0 && (show[x + 1][y] == '*'))
			no_mine(mine, show, x + 1, y);
		if ((x + 1) > 0 && (y + 1) > 0 && (show[x + 1][y + 1] == '*'))
			no_mine(mine, show, x + 1, y + 1);
	}
	else
		show[x][y] = ret + '0';//+��0��askii��ת���ַ�
}

//����
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0; int y = 0; int win = 0;//û�ﵽ�׵Ĵ���
	while (win<row*col-FV_COUNT )
	{
		printf("��ѡ���Ⱦ��Ǹ�==>"); scanf("%d %d", &x, &y);
		if(x >= 1 && x <= row && y >= 1 && y <= col){
			if(mine[x - 1][y - 1] == '1' && show[x - 1][y - 1] == '$' && win == 0)
			{
				initial_board(mine, ROWS, COLS, '0');
				set_mine(mine, ROW, COL);
				win++;
			}
			if (mine[x - 1][y - 1] == '0' && show[x - 1][y - 1] == '$')
			{
				no_mine(mine, show, x - 1, y - 1);
				display_board(show, ROW, COL);
				win = win + 8;
			}
			if (mine[x - 1][y - 1] == '1' && show[x - 1][y - 1] == '$' && win != 0)
			{
				show[x - 1][y - 1] = 'S';
				display_board(show, ROW, COL);
				printf("���ź����㱻ը����\n\n");
				display_board(mine, row, col);
				break;
				}
			}
		else printf("ɵ��\n");			
	}		
	if (win > row * col - FV_COUNT)
		printf("666\n");						
}


