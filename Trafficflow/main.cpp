#include <windows.h>
#include <conio.h>
#include<iostream>
#include"entity.h"

using namespace std;

int main()
{
	Road road;
	
	while (road.n<8)
	{
		if (_kbhit())
		{
			road.getNewCar(rand()%20+1,rand()%10+1); //伪随机速度范围[1，20],伪随机加速度范围[1,10]
			cin.ignore();
		}
		Car* cursor = road.firstCar;
		while (cursor != nullptr)
		{
			cursor->accelerationUpdate();
			cursor->speedUpdate();
			cursor->driving();
			cursor->showMessage();
			cursor = cursor->after;
		}
		cout << "" << endl;
		Sleep(1000);
	}
}