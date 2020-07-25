#pragma once
#include<iostream>
class Car
{
private:
	static int g_id;
	int id;			//����������id
	int x, y;
	int width = 2;
	

public:
	int acceleration = 0;
	int speed;
	//ͬ����ǰ����ָ��
	Car* front = nullptr;
	Car* after = nullptr;

	Car(int x, int y, int speed, int acceleration) {
		this->x = x;
		this->y = y;
		this->speed = speed;
		this->acceleration = acceleration;
		this->id = g_id++;
	}

	~Car()
	{
		g_id--;
	}

	//��ֱ����ʻ��Ϊ��ֻ�г���y����ı�
	void driving() {
		this->y += this->speed;
	}

	void showMessage() {
		std::cout <<"id:"<<this->id<<"  ���꣺"<<this->x<<" "<<this->y<<"  �ٶȣ�"<<this->speed<<"  ���ٶȣ�"<<this->acceleration<<std::endl;
	};

	void accelerationUpdate()
	{
		if (this->front == nullptr)
		{
			this->acceleration = rand() % 10 + 1;//α������ٶȷ�Χ[1��10]
		}
		else
		{
			//���ø���ģ��
			// m = 0;l = 1;������Ϊ1
			this->acceleration = (this->front->speed - this->speed) / (this->front->y - this->y);
		}
	}

	void speedUpdate()
	{
		this->speed += this->acceleration;
	}
};

int Car::g_id = 0;

class Road
{
public:
	int capacity = 8;
	Car* firstCar = nullptr;
	int n = 0;							    //��·��ǰ������
	int x_startPoint = 0, y_startPoint = 0; //�����������

	void getNewCar(int speed, int acceleration) {
		if (this->n == this->capacity)
		{
			std::cout << "this road is full" << std::endl;
			return;
		}
		Car* car = new Car(this->x_startPoint,this->y_startPoint,speed,acceleration);
		if (n == 0)
		{
			firstCar = car;
		}
		else
		{
			Car* cursor = firstCar;
			while (cursor->after != nullptr)
			{
				cursor = cursor->after;
			}
			cursor->after = car;
			car->front = cursor;
		}
		++n;
	};
};