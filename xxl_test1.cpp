// xxl_test1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
using namespace std;
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#define random(x) (rand()%x)

int main()
{
	srand((int)10);
	double value[9];
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		value[i] = random(10);  //产生0-10的随机数
		sum = sum + value[i];
	}
	double sum_data = 0;
	for (int i = 0; i < 8; i++)
	{
		double d = value[i] / sum; //归一化
		value[i] = floor((d * pow(10, 3) + 0.5)) / pow(10, 3); //保留三位小数
		sum_data = sum_data + value[i];
	}
	value[8] = 1 - sum_data; //最后一个概率为1-前面生成概率之和，为了确保概率和为1
	//存进二维数组
	double array[3][3];
	int z = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			array[i][j] = value[z];
			z = z + 1;
		}
	}


	// 输出分布律
	cout << "随机生成分布律为：" << endl;
	cout << "     " << "x1      " << "x2       " << "x3" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "y" << i + 1 << " ";
		for (int j = 0; j < 3; j++) {
			cout << " " << array[i][j] << "  ";
		}
		cout << endl;
		cout << endl;
	}


	//计算熵
	//H（Y）
	double hy = 0;
	double y_list[3]; //存储y的分布律
	for (int i = 0; i < 3; i++)
	{
		double prob_y = 0;
		for (int j = 0; j < 3; j++)
		{
			prob_y = prob_y + array[i][j];
		}
		y_list[i] = prob_y;
		hy = hy - prob_y * log(prob_y) / log(2);
	}

	cout << "H(Y) = " << hy << endl;


	//H（X）
	double hx = 0;
	double x_list[3]; //存储x的分布律
	for (int i = 0; i < 3; i++)
	{
		double prob_x = 0;
		for (int j = 0; j < 3; j++)
		{
			prob_x = prob_x + array[j][i];
		}
		x_list[i] = prob_x;
		hx = hx - prob_x * log(prob_x) / log(2);
	}


	cout << "H(X) = " << hx << endl;

	//计算联合熵
	//H(X,Y)
	double hxy = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			hxy = hxy - array[i][j] * log(array[i][j]) / log(2);
		}
	}

	cout << "联合熵 H(X,Y) = " << hxy << endl;

	//条件熵
	//H(X/Y)=H(X,Y)-H(X)
	double hx_y = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			hx_y = hx_y - array[i][j] * log((array[i][j]) / y_list[i]) / log(2);
		}
	}
	cout << "条件熵 H(X|Y) = " << hx_y << endl;


	//平均互信息量
	//I(X;Y)
	double ixy = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ixy = ixy + array[i][j] * log((array[i][j]) / (y_list[i] * x_list[j])) / log(2);
		}
	}
	cout << "平均互信息量 I(X;Y) = " << ixy << endl;



}

