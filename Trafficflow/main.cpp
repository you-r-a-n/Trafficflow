#include <windows.h>
#include <conio.h>
#include<iostream>
#include"entity.h"

using namespace std;

int main()
{
	int t = 1;
	Road road;
		////ÿһ��ʱ��Ϊt�Ĳ����ڷ�������
	while (road.n<8)
	{
		if (_kbhit())
		{
			road.getNewCar(20,10);
			cin.ignore();
		}
		Car* cursor = road.firstCar;		
		while (cursor != nullptr)         
		{
			cursor->accelerationUpdate();
			cursor->showMessage();
			cursor = cursor->after;
		}
		cursor = road.firstCar;
		while (cursor != nullptr)
		{
			cursor->driving(t);
			cursor->speedUpdate(t);
			cursor = cursor->after;
		}
		cout << "" << endl;
		Sleep(1000);
	}
}