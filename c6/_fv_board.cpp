#include"fv_board.h"
//前头
void meun() {
	printf("————————————————————\n");
	printf("——————1.  play——————————\n");
	printf("——————0.  exit——————————\n");
	printf("————————————————————\n");
}

//初始化棋盘
void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0; int j = 0;
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}
/// 打印棋盘
void dispaly_board(char board[ROW][COL], int row, int col){
	int i = 0; int j = 0;
	for (i = 0; i < row; i++){
		//打印数据
		for (j = 0; j < col; j++){	
			printf(" %c ", board[i][j]); 
			if(j<col-1)
				printf("|"); 			
		}
		printf("\n");
		//打印分割信息
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		printf("\n");
		}
		
	}
}
//你下
void player_move(char board[ROW][COL], int row, int col)
{
	int x = 0; int y = 0;
	while (true)
	{	printf("输入坐标(空格隔开)=>"); scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else
			{
				printf("傻鸟\n");
			}
		}
		else
		{
			printf("傻鸟\n");
		}
	}
	
}
//电脑下
void pc_move(char board[ROW][COL], int row, int col)
{
	printf("你爹下\n"); int x = 0; int y = 0;
	while (true)
	{
		x = rand() % row; y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = 'O'; break;
		}
	}
}
//判断满盘
//满就返回1  无则返回0
int is_full(char board[ROW][COL], int row, int col) {
	for (size_t i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			if (board[i][j] == ' ')
				return 0;
	}			
	return 1;
}
//判断输赢
//1.你win‘x’ 
//2.你爹win‘O’ 
//3.平局‘q’ 
//4.继续‘c
char is_win(char board[ROW][COL], int row, int col)
{	//行
	int i = 0; int j = 0;
	for ( i = 0; i < row; i++)
	{
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];
	}
	//列		
	for (j = 0; j < col; j++)
	{
		if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
			return board[0][j];
	}
	//对角线
	if (board[0][0] != ' ' && board[0][0]== board[1][1] && board[2][2] == board[1][1])
		return board[0][0];
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[2][0] == board[1][1])
		return board[0][2];
	//ping
	if (is_full(board,row,col))
	{
		return 'q';
	}
	return 'c';
}
