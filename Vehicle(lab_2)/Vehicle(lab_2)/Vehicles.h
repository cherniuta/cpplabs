#pragma once

#include <stdio.h>
#include<conio.h>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<locale.h>
#include <string> 


class CVehicle
{
public:
	CVehicle(const int price, const double maxSpeed, const int yearOfRelease);

	void Ñoordinates(double x, double y);
	int set_speed(double speed);

	void move(int side);

	double get_x();
	double get_y();
	double get_speed();

	std::string get_price();
	std::string get_maxSpeed();
	std::string get_yearOfRelease();
	
	virtual void PrintInfo() = 0;

private:
	double x;
	double y;
	double speed;

	int price;
	double maxSpeed;
	int yearOfRelease;

	static int sideVehicle;

};

class CCar :public CVehicle
{
public:
	CCar( const int price, const double maxSpeed, const int yearOfRelease);
	
	void PrintInfo() override;

};

class CPlan :public CVehicle
{
public:
	CPlan(const double height,const int price,const double maxSpeed, const int yearOfRelease,const int countPerson);
	
	void PrintInfo() override;
	void setCountPerson(int countPerson)
	{
		this->countPerson = countPerson;
	}
private:
	double height;
	int countPerson;
};

class CShip :public CVehicle
{
public:
	CShip(const int price,const double maxSpeed, const int yearOfRelease, const int countPerson, std::string port);
	
	void PrintInfo() override;
private:
	std::string port;
	int countPerson;
};

