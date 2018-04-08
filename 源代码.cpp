#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define LINE 3
int symbol1, symbol2;
char a[10];
void initialize()		//将棋盘元素初始化为空格
{
	int i;
	for (i = 1; i <= 9; i++)
	{
		a[i] = ' ';
	}

}

void start_game()		//打印开始界面并让P1，P2选择所持棋子
{
	printf("                              ||************************************************************||\n");
	printf("                              ||************************************************************||\n");
	printf("                              ||***********       欢迎来到大型博弈游戏           ***********||\n");
	printf("                              ||***********                                      ***********||\n");
	printf("                              ||************         传统井字棋PVP版            ************||\n");
	printf("                              ||************                                    ************||\n");
	printf("                              ||**************       按任意键开始游戏         **************||\n");
	printf("                              ||************************************************************||\n");
	printf("                              ||************************************************************||\n");
	system("PAUSE");
	printf("                                    请选择P1要使用的符号(输入X或O)(大写)\n\n");
	while (1)
	{
		symbol1 = getchar();											
		if (symbol1 == 'X' || symbol1 == 'O')						//P1,P2选择棋子
		{
			if (symbol1 == 'X')
				symbol2 = 'O';
			else symbol2 = 'X';
			printf("                                        P1使用%c,P2使用%c\n\n", symbol1, symbol2);
			break;
		}
		printf("输入错误,请重新输入:\n");
	}

}
void print()		//打印棋盘
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

void player1_step()		//P1的回合
{
	int location;
	printf("请P1输入要放的位置:\n");
	while (1)
	{
		scanf("%d", &location);
		if ((char)(location+48)<'1' || (char)(location+48)>'9')								//防止输入1~9以外的数字
		{
			printf("输入错误，请重新输入:\n");
			continue;
		}
		if (a[location] != symbol1&&a[location] != symbol2)			//若此位置为空则可以放置棋子
		{
			a[location] = symbol1;
			print();												//打印放置后的棋盘
			break;
		}
		else printf("该位置被占了,请重新输入:\n");
	}
}
void player2_step()		//P2的回合
{
	int location;
	printf("请P2输入要放的位置:\n");
	while (1)
	{
		scanf("%d", &location);
		if ((char)(location + 48)<'1' || (char)(location + 48)>'9')								//防止输入1~9以外的数字
		{
			printf("输入错误，请重新输入:\n");
			continue;
		}
		if (a[location] != symbol1&&a[location] != symbol2)			//若此位置为空则可以放置棋子
		{
			a[location] = symbol2;
			print();												//打印放置后的棋盘
			break;
		}
		else printf("该位置被占了,请重新输入:\n");
	}
}
int row(int n, char symbol)					//通过判断每一行三个元素是否都是symbol来决定是否是winner
{
	int i, flag = 0;
	for (i = (1 + ROW*(n - 1)); i <= ROW*n; i++)
	{
		if (a[i] == symbol)
			flag++;							//累计循环次数用于下面判断

	}
	if (flag == ROW)							
		return 1;
	else
		return 0;
}
int line(int n, char symbol)					//通过判断每一列三个元素是否都是symbol来决定是否是winner
{
	int i, flag = 0;
	for (i = n; i <= (n + LINE*(ROW - 1)); i = i + ROW)
	{
		if (a[i] == symbol)
			flag++;						//累计循环次数用于下面判断
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
			flag++;						//累计循环次数用于下面判断
	}

	if (flag == LINE)
		return 1;
	flag = 0;
	for (i = ROW; i <= 1 + ROW*(LINE - 1); i = i + ROW - 1)
	{
		if (a[i] == symbol)
			flag++;						//累计循环次数用于下面判断
	}
	if (flag == LINE)
		return 1;
	return 0;
}
int judge(char symbol)								//判断游戏是否出现胜利者
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
int choose_continue()				    //选择是否继续，返回一则表示继续
{
	printf("是否要继续玩？(输入1：继续玩，2：退出)\n");
	int choice;
	while (1)
	{
		scanf("%d", &choice);
		if (choice == 1)					//继续
		{
			initialize();
			start_game();				
			return 1;							
		}
		else if (choice == 2)
			exit(0);						//退出游戏
		else
			printf("                                           没有该指令，重新输入:\n");
	}
	   return 0;
}
void choose()									//选择要下棋的玩家并打印判断信息
{
	int step = 0, t;
	while (step <= 9)
	{
		player1_step();						//从P1开始走
		step++;								//累计步数判断是否达到平局，下同
		if (t = judge(symbol1) > 0)				//判断P1是否赢了
		{
			printf("\n\n                                          恭喜P1获得胜利\n");
			if (choose_continue() == 1)
				choose;							//调用choose继续下一局,因不能调用自身后面的函数所以不能放此语句在choose中
		}
		player2_step();
		step++;
		if (judge(symbol2) > 0)
		{
			printf("\n\n                                           恭喜P2获得胜利\n");
			if (choose_continue() == 1)
				choose;
		}
	}
	if (step >= 9 && t != 1)						//平局条件
		printf("\n\n                                         两人打平，没有winner\n");
		if (choose_continue() == 1)
		choose;
}

int main()						//主函数
{
	initialize();				//初始化数组为空
	start_game();				//开始游戏
	choose();
}
