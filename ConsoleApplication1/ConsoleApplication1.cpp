// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"

int min(int a, int b)
{
	if (a >= b)
		return b;
	else
		return a;
}

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

bool chess::move(int x1, int y1, plate* field)
{
	if (x1 <= -1 || x1 >= 9)
		return 0;
	if (y1 <= -1 || y1 >= 10)
		return 0;
	switch (cha)
	{
	case 1:
		return general(x1,y1,field);
	case 8:
		return general(x1, y1, field);
	case 2:
		return guardian(x1, y1, field);
	case 9:
		return guardian(x1, y1, field);
	case 3:
		return elephant(x1, y1,field);
	case 10:
		return elephant(x1, y1, field);
	case 4:
		return knight(x1, y1, field);
	case 11:
		return knight(x1, y1, field);
	case 5:
		return cannon(x1, y1, field);
	case 12:
		return cannon(x1, y1, field);
	case 6:
		return tank(x1, y1, field);
	case 13:
		return tank(x1, y1, field);
	case 7:
		return soilder(x1, y1, field);
	case 14:
		return soilder(x1, y1, field);

	}
}

bool chess::general(int x1, int y1, plate* field)
{
	if (x1 <= 2 || x1 >= 6)
		return 0;
	if (!(abs(x1 - x) <= 1 && abs(y1 - y) <= 1))
		return 0;
	if (cha <= 7)
	{
		if (y1 <= 6||y1>=10)
			return 0;
		if (field->getCha(x1, y1) <= 7&& field->getCha(x1, y1) !=0)
			return 0;
	}
	else
	{
		if (y1 <= -1 || y1 >= 3)
			return 0;
		if (field->getCha(x1, y1) > 7)
			return 0;
	}
	x = x1;
	y = y1;
	return 1;
}

bool chess::guardian(int x1, int y1, plate* field)
{
	if (!(abs(x1 - x) == 1 && abs(y1 - y) == 1))
		return 0;
	if (x1 <= 2 || x1 >= 6)
		return 0;
	if (cha <= 7)
	{
		if (y1 <= 6 || y1 >= 10)
			return 0;
		if (field->getCha(x1, y1) <= 7 && field->getCha(x1, y1) != 0)
			return 0;
	}
	else
	{
		if (y1 <= -1 || y1 >= 3)
			return 0;
		if (field->getCha(x1, y1) > 7)
			return 0;
	}
	x = x1;
	y = y1;
	return 1;
}

bool chess::elephant(int x1, int y1, plate* field)
{
	if (!(abs(x1 - x) == 2 && abs(y1 - y) == 2))
		return 0;
	if (field->getCha((x1 + x) / 2, (y1 + y) / 2) > 0)
		return 0;
	if (cha <= 7)
	{
		if (field->getCha(x1, y1) <= 7 && field->getCha(x1, y1) != 0)
			return 0;
	}
	else
		if (field->getCha(x1, y1) > 7)
			return 0;
	x = x1;
	y = y1;
	return 1;
}

bool chess::knight(int x1, int y1, plate* field)
{
	if (!((abs(x1 - x) == 2 && abs(y1 - y) == 1)|| (abs(x1 - x) == 1 && abs(y1 - y) == 2)))
		return 0;
	if (x1 - x == 2|| x1 - x == -2)
		if (field->getCha((x1 + x) / 2, y) > 0)
			return 0;
	if(y1 - y == 2 || y1 - y == -2)
		if (field->getCha(x, (y1+y)/2) > 0)
			return 0;
	if (cha <= 7)
	{
		if (field->getCha(x1, y1) <= 7 && field->getCha(x1, y1) != 0)
			return 0;
	}
	else
		if (field->getCha(x1, y1) > 7)
			return 0;
	x = x1;
	y = y1;
	return 1;
}

bool chess::cannon(int x1, int y1, plate* field)
{
	bool shoot = 0;
	if (!(x1 == x || y1 == y))
		return 0;
	if (x1 == x)
		for (int y2 = min(y, y1) + 1; y2 < max(y1, y); y2++)
			if (!shoot)
			{
				if (field->getCha(x, y2) > 0)
					shoot = 1;
			}
			else
				if (field->getCha(x, y2) > 0)
					return 0;
	if (y1 == y)
		for (int x2 = min(x, x1) + 1; x2<max(x1, x); x2++)
			if (!shoot)
			{
				if (field->getCha(x2, y) > 0)
					shoot = 1;
			}
			else
				if (field->getCha(x2, y) > 0)
					return 0;
	if (!shoot)
	{
		if (field->getCha(x1, y1) > 0)
			return 0;
	}
	else
	{
		if (field->getCha(x1, y1) == 0)
			return 0;
		if (cha <= 7)
		{
			if (field->getCha(x1, y1) <= 7)
				return 0;
		}
		else
			if (field->getCha(x1, y1) > 7)
				return 0;
	}
	x = x1;
	y = y1;
	return 1;
}

bool chess::tank(int x1, int y1, plate* field)
{
	if (!(x1==x || y1==y))
		return 0;
	if (x1 == x)
		for (int y2 = min(y,y1)+1; y2 < max(y1,y); y2++)
			if (field->getCha(x, y2) > 0)
				return 0;
	if(y1==y)
		for(int x2=min(x,x1)+1;x2<max(x1,x);x2++)
			if (field->getCha(x2, y) > 0)
				return 0;
	if (cha <= 7)
	{
		if (field->getCha(x1, y1) <= 7 && field->getCha(x1, y1) != 0)
			return 0;
	}
	else
		if (field->getCha(x1, y1) > 7)
			return 0;
	x = x1;
	y = y1;
	return 1;
}

bool chess::soilder(int x1, int y1, plate* field)
{
	if (cha <= 7)
	{
		if (y >= 5)
		{
			if (x1 != x || y1 - y != -1)
				return 0;
		}
		else
			if (abs(x1-x)>1 ||!( y1 - y == -1||y1-y==0))
				return 0;
		if (field->getCha(x1, y1) <= 7 && field->getCha(x1, y1) != 0)
			return 0;
	}
	else
	{
		if (y <= 4)
		{
			if (x1 != x || y1 - y != 1)
				return 0;
		}
		else
			if (abs(x1 - x) > 1 || !(y1 - y == -1 || y1 - y == 0) )
				return 0;
		if (field->getCha(x1, y1) > 7)
			return 0;
	}
	x = x1;
	y = y1;
	return 1;
}

int chess::getCha()
{
	return cha;
}

chess::chess(int x2, int y2, int cha2)
{
	x = x2;
	y = y2;
	cha = cha2;
}







chess* plate::getChess(int x,int y)
{
	if (thePlate[y][x] != 0)
		return thePlate[y][x];
	else
		return 0;
}

int plate::getCha(int x, int y)
{
	if (thePlate[y][x] != 0)
		return thePlate[y][x]->getCha();
	else
		return 0;
}

bool plate::replace(int x2, int y2, int x1, int y1)
{
	if (getChess(x2, y2) != 0)
	{
		if (getChess(x2, y2)->getCha() == 1 || getChess(x2, y2)->getCha() == 8)
			return 1;
		delete []thePlate[y2][x2];
	}
	thePlate[y2][x2] = thePlate[y1][x1];
	thePlate[y1][x1] = 0;
	return 0;
}

void plate::printPlate()
{
	cout << "  0  1  2  3  4  5  6  7  8 "<<endl;
	char* tmp;
	for (int j = 0; j < 10; j++)
	{
		cout << j<<" ";
		for (int i = 0; i < 9; i++)
		{
			if (thePlate[j][i] != 0)
			{
				const int len = lis[thePlate[j][i]->getCha()].length();
				tmp= new char[len + 1];
				strcpy(tmp, lis[thePlate[j][i]->getCha()].c_str());
				printf(tmp);
				printf(" ");
			}
			else
				cout << "00 ";
		}
		cout << endl;
	}
}

plate::plate()
{
	memset(thePlate, 0, sizeof(thePlate));
	for (int i = 0; i<9; i++)
		for (int j = 0; j < 10; j++)
		{
			if (opening[j][i]>0)
			{
				thePlate[j][i] = new chess(i, j, opening[j][i]);
			}
		}
}

const string plate::lis[15] = { "00","帅","仕","相","马","砲","车","兵","将","士","象","馬","炮","車","卒" };
const int plate::opening[10][9] = {
	{ 13,11,10,9,8,9,10,11,13 },
{ 0,0,0,0,0,0,0,0,0 },
{ 0,12,0,0,0,0,0,12,0 },
{ 14,0,14,0,14,0,14,0,14 },
{ 0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0 },
{ 7,0,7,0,7,0,7,0,7 },
{ 0,5,0,0,0,0,0,5,0 },
{ 0,0,0,0,0,0,0,0,0 },
{ 6,4,3,2,1,2,3,4,6 } };

int main()
{
	plate field;
	int x1, y1,x2,y2;
	const string rob[2] = {"红","黑"};
	char* tmp;
	bool ending;
	while (true)
	{

		for (int i = 0; i < 2; i++)
		{
			field.printPlate();
			const int len = rob[i].length();
			tmp = new char[len + 1];
			strcpy(tmp, rob[i].c_str());
			cout << endl;
			printf(tmp);
			cout << "方行动" << endl << "从" << endl;
			while (true)
			{
				cout << "x:";
				cin >> x1;
				cout << "y:";
				cin >> y1;
				if (i == 0)
				{
					if (field.getCha(x1, y1) <= 7 && field.getCha(x1, y1) != 0)
						break;
					else
						cout << "不存在棋子" << endl;
				}
				else
				{
					if (field.getCha(x1, y1) >7)
						break;
					else
						cout << "不存在棋子" << endl;
				}
			}
			cout << endl << "到" << endl;
			while (true)
			{
				cout << "x:";
				cin >> x2;
				cout << "y:";
				cin >> y2;
				if (field.getChess(x1, y1)->move(x2, y2, &field))
					break;
				else
					cout << "不可以移动到此" << endl;
			}
			ending=field.replace(x2, y2, x1, y1);
			if (ending)
			{
				printf(tmp);
				cout << "方取胜"<<endl;
				getchar();
				return 0;
			}
		}
	}
	getchar();
	return 0;
}

