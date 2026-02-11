#include <iostream>
#include <stdio.h>
class IMotor
{
public:
	virtual void SetOutPut() = 0;
	virtual void GetSpeed() = 0;
	virtual void Update() = 0;
	virtual ~IMotor() {
		printf("xigou\n");
	}
	int *power;
	int velocity=0;
};

class DJIMotor:public IMotor
{
public:
	DJIMotor(int power)
	{
		this->power = new int(power);
	}
	void SetOutPut()override
	{
		printf("[CAN BUS]ID:0000000\n");
	}
	void GetSpeed()override
	{
		velocity = 1000;
		printf("当前速度为：%d\n", velocity);

	}
	void Update()override
	{
		velocity = velocity + (*power - friction);
	}
	~DJIMotor()override
	{
		printf("DJ的析构函数\n");
		if (power != NULL)
		{
			delete power;
			power = NULL;
		}
	}
private:
	int friction = 10;
};

class SimMotor:public IMotor
{
public:
	SimMotor(int power)
	{
		this->power = new int(power);
	}
	void SetOutPut()override
	{
		printf("电机已启动\n");
	}

	void GetSpeed()override
	{
		velocity = 500;
		printf("当前速度为：%d\n", velocity);

	}

	void Update()override
	{
		velocity = velocity + (*power - friction);
	}

	~SimMotor()override
	{
		printf("模拟电机的析构函数\n");
		if (power!=NULL)
		{
			delete power;
			power = NULL;
		}
	}
private:
	int friction = 10;
};

void test(IMotor *motor)
{
	motor->SetOutPut();
	motor->GetSpeed();
	motor->Update();
	delete motor;
}
int main()
{
	IMotor* motor = new DJIMotor(100);
	test(motor); 
	printf("---------------\n");
	motor = new SimMotor(200);
	test(motor);
	return 0;
}