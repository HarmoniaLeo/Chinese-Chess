// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include "string"
#include "math.h"

using namespace std;

// TODO: 在此处引用程序需要的其他头文件

class plate;

class chess
{
public:
	bool move(int x1, int y1, plate* field);
	chess(int x2, int y2, int cha2);
	int getCha();
private:
	int x, y, cha;
	bool general(int x1, int y1, plate* field), guardian(int x1, int y1, plate* field),
		elephant(int x1, int y1, plate* field), knight(int x1, int y1, plate* field),
		cannon(int x1, int y1, plate* field), tank(int x1, int y1, plate* field),
		soilder(int x1, int y1, plate* field);
};

class plate
{
public:
	plate();
	void printPlate();
	int getCha(int x, int y);
	chess* getChess(int x, int y);
	bool replace(int x2, int y2, int x1, int y1);
private:
	static const string lis[15];
	chess* thePlate[10][9];
	static const int opening[10][9];
};