#include "saLEI.h"
void SA_game() {
	char mine[ROWS][COLS] = { 0 };//�洢���úõ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//�����Ų�����׵���Ϣ
	//��ʼ�����������Ϊָ��Ԫ��
	initial_board(mine,ROWS,COLS,'0');//û��==0
	initial_board(show, ROWS, COLS,'$');//û����==$	
    //����
	set_mine(mine, ROW, COL);
	//����
	display_board(mine, ROW, COL);
	//������
	display_board(show, ROW, COL);
	//����
	find_mine(mine, show, ROW, COL);
}
int main() {
	int input = 0;
	//�������������
	do
	{
		srand((unsigned int)time(NULL));
		meun();
		printf("==>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������saLEI����������\n");
			SA_game();
			break;
		case 0: 
			printf("��������unsaLEI��������\n");
			break;
		default:
			printf("ɵ��\n");
			break;			
		}
	} while (input);
	return 0;
}