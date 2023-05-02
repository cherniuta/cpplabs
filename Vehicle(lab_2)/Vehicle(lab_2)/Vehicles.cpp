#include "Vehicles.h"
#include <string>
#include <stdio.h>
#include<conio.h>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<locale.h>

int CVehicle::sideVehicle = 0;

CVehicle::CVehicle( const int price,const double maxSpeed, const int yearOfRelease)
{
	this->price = price;
	this->maxSpeed = maxSpeed;
	this->yearOfRelease = yearOfRelease;

	this->x = 0;
	this->y = 0;
	this->speed = 0;
}

void CVehicle::Ñoordinates(double x, double y)
{
	this->x = x;
	this->y = y;
	sideVehicle = 0;
}

int CVehicle::set_speed(double speed)
{
	if (speed > 0 && speed <= maxSpeed) {
		this->speed = speed;
		return 1;
	}
	else
		return 0;

}

double CVehicle::get_x() { return this->x; }

double CVehicle::get_y() { return this->y; }

double CVehicle::get_speed() { return speed; }

std::string CVehicle::get_price() { return std::to_string(price); }

std::string CVehicle::get_maxSpeed() { return std::to_string(maxSpeed); }

std::string CVehicle::get_yearOfRelease() { return std::to_string(yearOfRelease); }

void CVehicle::move(int side)
{
	sideVehicle = (sideVehicle + side) % 4;

	if (sideVehicle == 0)
	{
		this->x += this->speed;
	}
	else if (sideVehicle == 1 || sideVehicle == -3)
	{
		this->y += this->speed;
	} 
	else if (sideVehicle == -1 || sideVehicle == 3)
	{
		this->y -= this->speed;
	}
	else
	{
		this->x -= this->speed;
	}
}

CCar::CCar(const int price,const double maxSpeed, const int yearOfRelease) 
	:CVehicle(price, maxSpeed, yearOfRelease){}

void CCar::PrintInfo()
{
	const int size = 30;
	char dash = '-';
	char stick = '|';
	
	std::cout << std::string(size, dash) << std::endl;
	std::cout << std::setw(size - 14) << std::right << "CAR" << std::setw(size - 16) << std::right << stick << std::endl;
	std::cout << std::string(size, dash) << std::endl;

	std::cout<< std::setw(size - 7) << std::right << "*Specifications*" << std::setw(size - 23) << std::right << stick << std::endl;
	std::cout << std::setw(size) << std::right << stick << std::endl;
	std::cout << "Year of Release:" << this->get_yearOfRelease() << std::setw(size - this->get_yearOfRelease().length() - 16) << std::right << stick << std::endl;
	std::cout << "Max Speed:" << this->get_maxSpeed() <<" km/h"<< std::setw(size - this->get_maxSpeed().length() - 15) << std::right << stick << std::endl;
	std::cout << "Price:$" << this->get_price() << std::setw(size - this->get_price().length() - 7) << std::right << stick << std::endl;
	std::cout << std::string(size, dash) << std::endl;

	std::cout << "position x:" << this->get_x() << std::endl;
	std::cout << "position y:" << this->get_y() << std::endl;
	std::cout << "speed:" << this->get_speed() << " km/h" << std::endl;
	std::cout << std::string(size, dash) << std::endl;
}

CPlan::CPlan(const double height, const int price, const double maxSpeed, const int yearOfRelease, const int countPerson)
	:CVehicle(price, maxSpeed, yearOfRelease)
{
	this->height = height;
	this->countPerson = countPerson;
}

void CPlan::PrintInfo()
{
	const int size = 30;
	char dash = '-';
	char stick = '|';

	std::cout << std::string(size, dash) << std::endl;
	std::cout << std::setw(size - 13) << std::right << "PLAN" << std::setw(size - 17) << std::right << stick << std::endl;
	std::cout << std::string(size, dash) << std::endl;

	std::cout << std::setw(size - 7) << std::right << "*Specifications*" << std::setw(size - 23) << std::right << stick << std::endl;
	std::cout << std::setw(size) << std::right << stick << std::endl;
	std::cout << "Year of Release:" << this->get_yearOfRelease() << std::setw(size - this->get_yearOfRelease().length() - 16) << std::right << stick << std::endl;
	std::cout << "Number of people:" << this->countPerson << std::setw(size - std::to_string(this->countPerson).length() - 17) << std::right << stick << std::endl;
	std::cout << "Max Speed:" << this->get_maxSpeed() << " km/h" << std::setw(size - this->get_maxSpeed().length() - 15) << std::right << stick << std::endl;
	std::cout << "Price:$" << this->get_price() << std::setw(size - this->get_price().length() - 7) << std::right << stick << std::endl;
	std::cout << std::string(size, dash) << std::endl;

	std::cout << "position x:" << this->get_x() << std::endl;
	std::cout << "position y:" << this->get_y() << std::endl;
	std::cout << "height gained:" << this->height << std::endl;
	std::cout << "speed:" << this->get_speed() << " km/h" << std::endl;
	std::cout << std::string(size, dash) << std::endl;
}

CShip::CShip(const int price,const double maxSpeed, const int yearOfRelease, const int countPerson,std::string port) 
	:CVehicle( price, maxSpeed, yearOfRelease)
{
	this->countPerson = countPerson;
	this->port = port;
}

void CShip::PrintInfo()
{
	const int size = 30;
	char dash = '-';
	char stick = '|';

	std::cout << std::string(size, dash) << std::endl;
	std::cout << std::setw(size - 13) << std::right << "SHIP" << std::setw(size - 17) << std::right << stick << std::endl;
	std::cout << std::string(size, dash) << std::endl;

	std::cout << std::setw(size - 7) << std::right << "*Specifications*" << std::setw(size - 23) << std::right << stick << std::endl;
	std::cout << std::setw(size) << std::right << stick << std::endl;
	std::cout << "Port of residence:" << this->port << std::setw(size - this->port.length() - 18) << std::right << stick << std::endl;
	std::cout << "Year of Release:" << this->get_yearOfRelease() << std::setw(size - this->get_yearOfRelease().length() - 16) << std::right << stick << std::endl;
	std::cout << "Number of people:" << this->countPerson << std::setw(size - std::to_string(this->countPerson).length() - 17) << std::right << stick << std::endl;
	std::cout << "Max Speed:" << this->get_maxSpeed() << " km/h" << std::setw(size - this->get_maxSpeed().length() - 15) << std::right << stick << std::endl;
	std::cout << "Price:$" << this->get_price() << std::setw(size - this->get_price().length() - 7) << std::right << stick << std::endl;
	std::cout << std::string(size, dash) << std::endl;

	std::cout << "position x:" << this->get_x() << std::endl;
	std::cout << "position y:" << this->get_y() << std::endl;
	std::cout << "speed:" << this->get_speed() << " km/h" << std::endl;
	std::cout << std::string(size, dash) << std::endl;
}

