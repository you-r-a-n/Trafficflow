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

	void showMessage() {
		std::cout << "id:" << this->id << "  ���꣺" << this->x << " " << this->y << "  �ٶȣ�" << this->speed << "  ���ٶȣ�" << this->acceleration << std::endl;
	};

	//��ֱ����ʻ��Ϊ��ֻ�г���y����ı�
	void driving(int t) {
		this->y += this->speed*t + t*t*this->acceleration/2;
	}

	void accelerationUpdate()
	{
		//��һ�������ٶ����������120
		if (this->front == nullptr && this->speed >= 120)
		{
			this->acceleration = 120 - this->speed;
		}
		else if(this->front == nullptr)
		{
			this->acceleration = rand() % 10 + 1;//α������ٶȷ�Χ[1��10]
		}
		//������ǰ120�޳��������ʻ
		else if (this->front->y - this->y >= 120)
		{
			this->acceleration = this->front->speed - this->speed + 10;
		}
		//����
		else
		{
			// m = 0;l = 1;������Ϊ2
			this->acceleration = 2*(this->front->speed - this->speed) / (this->front->y - this->y);
		}
	}

	void speedUpdate(int t)
	{
			this->speed = this->speed + t*this->acceleration;
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