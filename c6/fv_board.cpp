#include"fv_board.h"
void san_game() {
	char ret = 0;
	char board[ROW][COL] = { 0 };
	init_board(board, ROW, COL);
	dispaly_board(board,ROW,COL);
	//��
	while (true)
	{	
	//����
		player_move(board, ROW, COL); dispaly_board(board, ROW, COL);
	//�ж���Ӯ
		ret=is_win(board, ROW, COL);
		if (ret != 'c')
			break;
	//pc��
		pc_move(board, ROW, COL); dispaly_board(board, ROW, COL);
	//�ж���Ӯ
		ret = is_win(board, ROW, COL);
		if (ret != 'c')break;
	}
	if (ret == 'x')
		printf("��win\n");
	else if (ret == 'O')
		printf("���win\n");
	else 	
		printf("���win\n");
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