#include <iostream>
#include <string>
#include <stdio.h>
#include<conio.h>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<locale.h>
#include "Vehicles.h"
#include<vector>
using namespace std;
int InputYear()
{
    int year = 0;
    for (;;)
    {
        std::cout << "Year of Release:";
        std::cin >> year;
        if (year >= 1990 && year <= 2022)
            break;
        else
            std::cout << "The speed is not defined\n" << std::endl;

    }
    return year;
}

double InputSpeed()
{
    double speed = 0;
    for (;;)
    {
        std::cout << "Max speed:";
        std::cin >> speed;
        if (speed > 0)
            break;
        else
            std::cout << "The speed is not defined\n" << std::endl;

    }
    return speed;
}

int InputPrice()
{
    int price = 0;
    for (;;)
    {
        std::cout << "Price:";
        std::cin >> price;
        if (price > 0)
            break;
        else
            std::cout << "The price is not defined" << std::endl;
    }
    return price;
}

int InputCountPerson()
{
    int countPerson = 0;
    for (;;)
    {
        std::cout << "Number of people:";
        std::cin >> countPerson;
        if (countPerson > 0 && countPerson <= 250)
            break;
        else
            std::cout << "The price is not defined" << std::endl;
    }
    return countPerson;
}

int main()
{
    vector <CVehicle*> vehicles;
    const int size = 30;
    char dash = '-';
    char stick = '|';

    string start = "finish";
    
    while (start != "start")
    {
        std::cout << "To start the game, enter - start->";
        std::cin >> start;
    }

    if (start == "start")
    {
        std::cout << std::string(size, dash) << std::endl;
        std::cout << std::setw(size - 10) << std::right << "***START***" << std::setw(size - 20) << std::right << stick << std::endl;

    }

    while (start == "start")
    {
        int option = 0;
        int typeVehicle = 0;
        int side = 0;

        int price = 0;
        double speed = 0;
        int year = 0;
        int countPerson = 0;
        string port = "";

        double x = 0;
        double y = 0;
        double height = 0;

        std::cout << std::string(size, dash) << std::endl;
        std::cout << "*Start moving-1" << std::setw(size - 15) << std::right << stick << std::endl;
        std::cout << "*Buy transport-2" << std::setw(size - 16) << std::right << stick << std::endl;
        std::cout << "*Sell transport-3" << std::setw(size - 17) << std::right << stick << std::endl;
        std::cout<<"*Finish the game-4"<< std::setw(size - 18) << std::right << stick << std::endl;
        std::cout << std::setw(size) << std::right << stick << std::endl;
        std::cout << std::string(size, dash) << std::endl;

        std::cout << "-->";
        std::cin >> option;

        switch (option)
        {
        case 1:
            if (!vehicles.empty())
            {
                std::cout << std::string(size, dash) << std::endl;
                std::cout << "Enter the index" << std::endl;
                
                std::cout << "-->";
                std::cin >> typeVehicle;
                std::cout << std::string(size, dash) << std::endl;

                if (typeVehicle > 0 && typeVehicle <= vehicles.size())
                {
                    std::cout << "Enter the initial coordinates and speed\n";

                    std::cout << "x:";
                    std::cin >> x;
                    std::cout << "y:";
                    std::cin >> y;
                    vehicles[typeVehicle - 1]->Сoordinates(x, y);

                    while (vehicles[typeVehicle - 1]->set_speed(speed) == 0)
                    {
                        std::cout << "speed:";
                        std::cin >> speed;
                    }
                    
                    vehicles[typeVehicle - 1]->PrintInfo();

                    while (side != -2)
                    {
                        std::cout << "\nforward- 0" << std::endl;
                        std::cout << "right- 1" << std::endl;
                        std::cout << "left- -1" << std::endl;
                        std::cout << "will stop- -2\n" << std::endl;

                        std::cout << "-->";
                        std::cin >> side;

                        if (side != -2) {
                            vehicles[typeVehicle - 1]->move(side);
                       }
                    }
                    
                    vehicles[typeVehicle - 1]->PrintInfo();
                }
                else
                    std::cout << "Index not found" << std::endl;
            }
            else
                std::cout << "You don't have vehicles" << std::endl;
            break;
        case 2:
            std::cout << std::string(size, dash) << std::endl;
            std::cout << "+Car-1" << std::setw(size - 6) << std::right << stick << std::endl;
            std::cout<<"+Plan-2"<< std::setw(size - 7) << std::right << stick << std::endl;
            std::cout << "+Ship-3" << std::setw(size - 7) << std::right << stick << std::endl;
            std::cout << std::string(size, dash) << std::endl;

            std::cout << "-->";
            std::cin >> typeVehicle;
            std::cout << std::string(size, dash) << std::endl;
            
            if (typeVehicle == 1)
            {
                year = InputYear();
                speed = InputSpeed();
                price = InputPrice();

                vehicles.push_back(new CCar(price, speed, year));
            }
            if (typeVehicle == 2)
            {
                year = InputYear();
                speed = InputSpeed();
                price = InputPrice();
                countPerson = InputCountPerson();

                for (;;) 
                {
                    std::cout << "Height:";
                    std::cin >> height;
                    if (height > 0)
                    {
                        break;
                    }
                    else
                        std::cout << "The height is not defined\n";
                }
                
                vehicles.push_back(new CPlan(height, price, speed, year, countPerson));
            }
            if (typeVehicle == 3)
            {
                std::cout << "Port of residence :";
                std::cin >> port;

                year = InputYear();
                speed = InputSpeed();
                price = InputPrice();
                countPerson = InputCountPerson();

                vehicles.push_back(new CShip(price, speed, year, countPerson, port));
            }
            break;
        case 3:
            if (!vehicles.empty())
            {
                std::cout << std::string(size, dash) << std::endl;
                std::cout << "Enter the index" << std::endl;

                std::cout << "-->";
                std::cin >> typeVehicle;
                std::cout << std::string(size, dash) << std::endl;

                if (typeVehicle > 0 && typeVehicle <= vehicles.size())
                {
                    auto iter = vehicles.begin()+typeVehicle-1;
                    delete *iter;//удаляем обЪект
                    vehicles.erase(iter);//удаляем указатель на обЪект
                }
                else
                    std::cout << "Index not found" << std::endl;
            }
            else
                std::cout << "You don't have vehicles" << std::endl;
            break;
        case 4:
            vehicles.clear();
            start = "finish";
            break;
        default:
            std::cout << "option not defined!" << std::endl;
            break;
        }

    }
    
}

