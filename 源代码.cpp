#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define LINE 3
int symbol1, symbol2;
char a[10];
void initialize()		//������Ԫ�س�ʼ��Ϊ�ո�
{
	int i;
	for (i = 1; i <= 9; i++)
	{
		a[i] = ' ';
	}

}

void start_game()		//��ӡ��ʼ���沢��P1��P2ѡ����������
{
	printf("                              ||************************************************************||\n");
	printf("                              ||************************************************************||\n");
	printf("                              ||***********       ��ӭ�������Ͳ�����Ϸ           ***********||\n");
	printf("                              ||***********                                      ***********||\n");
	printf("                              ||************         ��ͳ������PVP��            ************||\n");
	printf("                              ||************                                    ************||\n");
	printf("                              ||**************       ���������ʼ��Ϸ         **************||\n");
	printf("                              ||************************************************************||\n");
	printf("                              ||************************************************************||\n");
	system("PAUSE");
	printf("                                    ��ѡ��P1Ҫʹ�õķ���(����X��O)(��д)\n\n");
	while (1)
	{
		symbol1 = getchar();											
		if (symbol1 == 'X' || symbol1 == 'O')						//P1,P2ѡ������
		{
			if (symbol1 == 'X')
				symbol2 = 'O';
			else symbol2 = 'X';
			printf("                                        P1ʹ��%c,P2ʹ��%c\n\n", symbol1, symbol2);
			break;
		}
		printf("�������,����������:\n");
	}

}
void print()		//��ӡ����
{
	printf("                                               |       |         \n");
	printf("                                           %c   |   %c   |    %c   \n", a[1], a[2], a[3]);
	printf("                                        -------| ------| ------- \n");
	printf("                                               |       |         \n");
	printf("                                           %c   |   %c   |   %c    \n", a[4], a[5], a[6]);
	printf("                                               |       |         \n");
	printf("                                        -------|-------| ------- \n");
	printf("                                           %c   |   %c   |   %c    \n", a[7], a[8], a[9]);
	printf("                                               |       |         \n");
}

void player1_step()		//P1�Ļغ�
{
	int location;
	printf("��P1����Ҫ�ŵ�λ��:\n");
	while (1)
	{
		scanf("%d", &location);
		if ((char)(location+48)<'1' || (char)(location+48)>'9')								//��ֹ����1~9���������
		{
			printf("�����������������:\n");
			continue;
		}
		if (a[location] != symbol1&&a[location] != symbol2)			//����λ��Ϊ������Է�������
		{
			a[location] = symbol1;
			print();												//��ӡ���ú������
			break;
		}
		else printf("��λ�ñ�ռ��,����������:\n");
	}
}
void player2_step()		//P2�Ļغ�
{
	int location;
	printf("��P2����Ҫ�ŵ�λ��:\n");
	while (1)
	{
		scanf("%d", &location);
		if ((char)(location + 48)<'1' || (char)(location + 48)>'9')								//��ֹ����1~9���������
		{
			printf("�����������������:\n");
			continue;
		}
		if (a[location] != symbol1&&a[location] != symbol2)			//����λ��Ϊ������Է�������
		{
			a[location] = symbol2;
			print();												//��ӡ���ú������
			break;
		}
		else printf("��λ�ñ�ռ��,����������:\n");
	}
}
int row(int n, char symbol)					//ͨ���ж�ÿһ������Ԫ���Ƿ���symbol�������Ƿ���winner
{
	int i, flag = 0;
	for (i = (1 + ROW*(n - 1)); i <= ROW*n; i++)
	{
		if (a[i] == symbol)
			flag++;							//�ۼ�ѭ���������������ж�

	}
	if (flag == ROW)							
		return 1;
	else
		return 0;
}
int line(int n, char symbol)					//ͨ���ж�ÿһ������Ԫ���Ƿ���symbol�������Ƿ���winner
{
	int i, flag = 0;
	for (i = n; i <= (n + LINE*(ROW - 1)); i = i + ROW)
	{
		if (a[i] == symbol)
			flag++;						//�ۼ�ѭ���������������ж�
	}
	if (flag == LINE)
		return 1;
	else
		return 0;
}
int digonal(char symbol)
{
	int i, flag = 0;
	for (i = 1; i <= ROW*LINE; i = i + ROW + 1)
	{
		if (a[i] == symbol)
			flag++;						//�ۼ�ѭ���������������ж�
	}

	if (flag == LINE)
		return 1;
	flag = 0;
	for (i = ROW; i <= 1 + ROW*(LINE - 1); i = i + ROW - 1)
	{
		if (a[i] == symbol)
			flag++;						//�ۼ�ѭ���������������ж�
	}
	if (flag == LINE)
		return 1;
	return 0;
}
int judge(char symbol)								//�ж���Ϸ�Ƿ����ʤ����
{
	int i;
	if (digonal(symbol) == 1)					
		return 1;
	for (i = 1; i <= ROW; i++)
	{
		if (row(i, symbol) == 1)
			return 1;
	}
	for (i = 1; i <= LINE; i++)
	{
		if (line(i, symbol) == 1)
			return 1;
	}
	return 0;

}
int choose_continue()				    //ѡ���Ƿ����������һ���ʾ����
{
	printf("�Ƿ�Ҫ�����棿(����1�������棬2���˳�)\n");
	int choice;
	while (1)
	{
		scanf("%d", &choice);
		if (choice == 1)					//����
		{
			initialize();
			start_game();				
			return 1;							
		}
		else if (choice == 2)
			exit(0);						//�˳���Ϸ
		else
			printf("                                           û�и�ָ���������:\n");
	}
	   return 0;
}
void choose()									//ѡ��Ҫ�������Ҳ���ӡ�ж���Ϣ
{
	int step = 0, t;
	while (step <= 9)
	{
		player1_step();						//��P1��ʼ��
		step++;								//�ۼƲ����ж��Ƿ�ﵽƽ�֣���ͬ
		if (t = judge(symbol1) > 0)				//�ж�P1�Ƿ�Ӯ��
		{
			printf("\n\n                                          ��ϲP1���ʤ��\n");
			if (choose_continue() == 1)
				choose;							//����choose������һ��,���ܵ����������ĺ������Բ��ܷŴ������choose��
		}
		player2_step();
		step++;
		if (judge(symbol2) > 0)
		{
			printf("\n\n                                           ��ϲP2���ʤ��\n");
			if (choose_continue() == 1)
				choose;
		}
	}
	if (step >= 9 && t != 1)						//ƽ������
		printf("\n\n                                         ���˴�ƽ��û��winner\n");
		if (choose_continue() == 1)
		choose;
}

int main()						//������
{
	initialize();				//��ʼ������Ϊ��
	start_game();				//��ʼ��Ϸ
	choose();
}
