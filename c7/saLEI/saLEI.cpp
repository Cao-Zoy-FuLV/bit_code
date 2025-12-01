#include "../saLEI.h"
void SA_game() {
	char mine[ROWS][COLS] = { 0 };//存储布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//储存排查出的雷的信息
	//初始话数组的内容为指定元素
	initial_board(mine,ROWS,COLS,'0');//没雷==0
	initial_board(show, ROWS, COLS,'$');//没茬雷==$	
    //雷普
	set_mine(mine, ROW, COL);
	//开挂
	display_board(mine, ROW, COL);
	//基本盘
	display_board(show, ROW, COL);
	//撅雷
	find_mine(mine, show, ROW, COL);
}
int main() {
	int input = 0;
	//设置随机数生成
	do
	{
		srand((unsigned int)time(NULL));
		meun();
		printf("==>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("————saLEI—————\n");
			SA_game();
			break;
		case 0: 
			printf("————unsaLEI————\n");
			break;
		default:
			printf("傻鸟\n");
			break;			
		}
	} while (input);
	return 0;
}