#include"fv_board.h"
void san_game() {
	char ret = 0;
	char board[ROW][COL] = { 0 };
	init_board(board, ROW, COL);
	dispaly_board(board,ROW,COL);
	//下
	while (true)
	{	
	//你下
		player_move(board, ROW, COL); dispaly_board(board, ROW, COL);
	//判断输赢
		ret=is_win(board, ROW, COL);
		if (ret != 'c')
			break;
	//pc下
		pc_move(board, ROW, COL); dispaly_board(board, ROW, COL);
	//判断输赢
		ret = is_win(board, ROW, COL);
		if (ret != 'c')break;
	}
	if (ret == 'x')
		printf("你win\n");
	else if (ret == 'O')
		printf("你爹win\n");
	else 	
		printf("你爹win\n");
	dispaly_board(board, ROW, COL);
}
int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		meun(); printf("===>"); 
		scanf("%d", &input);
		switch (input)
		{ 
		case 1:san_game(); break;
		case 0:printf("exit\n"); break;
		default:printf("Sb\n"); break;
		}
	} while (input);
	return 0;
}