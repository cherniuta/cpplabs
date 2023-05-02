#include <string>
#include <stdio.h>
#include<conio.h>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<locale.h>
#include "list.h"

int main()
{
	std::string start = "finish";
	list<usingСlass> list;
	while (start != "start")
	{
		std::cout << "To get started, enter - start \n" << endl;
		std::cout << "-->";
		std::cin >> start;
	}

	while (start == "start")
	{
		int option = 0;
		int forward = 0;

		int index;

		int Int;
		std::string String;

		std::cout << "\nAdd to top-1" << std::endl;
		std::cout << "Add to the end-2" << std::endl;
		std::cout << "Add by index-3" << std::endl;
		std::cout << "Delete an item-4" << std::endl;
		std::cout << "View Item-5" << std::endl;
		std::cout << "Edit an element-6" << std::endl;
		std::cout << "Number of elements-7" << std::endl;
		std::cout << "Print a list-8" << std::endl;
		std::cout << "Delete a list-9" << std::endl;
		std::cout << "Finish-10\n" << std::endl;

		std::cout << "-->";
		std::cin >> option;

		switch (option)
		{
		case 1:
			std::cout << "int:";
			std::cin >> Int;

			std::cout << "string:";
			std::cin >> String;

			list.AddFirst(usingСlass(Int,String));
			
			break;
		case 2:
			std::cout << "int:";
			std::cin >> Int;

			std::cout << "string:";
			std::cin >> String;

			list.AddLast(usingСlass(Int, String));
			break;
		case 3:
			std::cout << "int:";
			std::cin >> Int;

			std::cout << "string:";
			std::cin >> String;

			std::cout << "index:";
			std::cin >> index;

			list.AddNext(usingСlass(Int, String),index);
			break;
		case 4:
			std::cout << "index:";
			std::cin >> index;

			list.Delete(index);
			break;
		case 5:
			std::cout << "index:";
			std::cin >> index;

			std::cout<<list.getElement(index);
			break;
		case 6:
			std::cout << "int:";
			std::cin >> Int;

			std::cout << "string:";
			std::cin >> String;

			std::cout << "index:";
			std::cin >> index;

			list.setElement(usingСlass(Int, String), index);
			break;
		case 7:
			std::cout << "Count:";
			std::cout << list.Count();
			break;
		case 8:
			std::cout << "Choose direction\n";
			std::cout << "forward-1\n";
			std::cout << "backward-0\n";

			std::cout << "-->";
			std::cin >> forward;

			if (forward == 1)
				list.printList(forward);
			if (forward == 0)
				list.printList(forward);

			break;
		case 9:
			list.Clear();
			break;
		case 10:
			start = "finish";
			break;
		default:
			break;
		}
	}
}


