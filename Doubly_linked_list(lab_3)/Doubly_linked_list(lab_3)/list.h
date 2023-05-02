#pragma once
#include <string>
#include <stdio.h>
#include<conio.h>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<locale.h>
using namespace std;
class using—lass
{
public:
	using—lass() = default;
	using—lass(int Int, std::string String);
	
	int getInt() const;
	std::string getString() const;

private:
	int Int;
	std::string String;
};
ostream& operator<<(ostream& os, const using—lass& op);
template <class T>
struct Node
{
	T info;
	Node<T>* prev;
	Node<T>* next;
};

template <class T> class list
{
public:
	list();
	~list();

	void AddFirst(const T& info);
	void AddLast(const T& info);
	void AddNext(const T& info, int indexInsert);

	void Delete(int index);

	T& getElement(int index);
	void setElement(const T& info,int index);

	void printList(int forward);
	int Count();

	void Clear();
	
private:
	Node<T>* root;
	Node<T>* end;
	int count;

	Node<T>* New(const T& info);
	bool correctIndex(int index);
	Node<T>* Move(int index);
	
};

template <class T>
list<T>::list()
{
	this->root = NULL;
	this->end = NULL;
	count = 0;
}

template <class T>
list<T>::~list()
{
	Clear();
}

template <class T>
Node<T>* list<T>::New(const T& info)
{
	Node<T>* block = new Node<T>;

	block->info = info;
	block->prev = NULL;
	block->next = NULL;

	return block;
}

template <class T>
bool list<T>::correctIndex(int index)
{
	return (index >= 0) && (index < count);
}

template <class T>
Node<T>* list<T>::Move(int indexMove)
{
	Node<T>* block = root;
	for (int index = 0; index < indexMove; index++)
		block = block->next;

	return block;
}

template <class T>
void list<T>::AddFirst(const T& info)
{
	Node<T>* block = New(info);

	if (count == 0)
	{
		root = end = block;
	}
	else 
	{
		block->next = root;
		root->prev = block;
		root = block;
	}

	count++;
}

template <class T>
void list<T>::AddLast(const T& info)
{
	Node<T>* newBlock = New(info);
	if (end != NULL)
	{
		end->next = newBlock;
		newBlock->prev = end;
	}
	
	count++;

	if (count == 0)
		root = end = newBlock;
	else
		end = newBlock;
}

template <class T>
void list<T>::AddNext(const T& info, int index)
{
	if (!correctIndex(index))
		return;

	if (index == 0)
	{
		AddFirst(info);
		return;
	}

	if (index == count)
	{
		AddLast(info);
		return;
	}

	Node<T>* block = Move(index - 1);
	
	Node<T>* newBlock = New(info);
	newBlock->next = block->next;
	block->next->prev = newBlock;
	newBlock->prev = block;
	block->next = newBlock;
	
	count++;
}

template <class T>
void list<T>::Delete(int index)
{
	if (count == 0)
	{
		return;
	}

	if (!correctIndex(index))
	{
		return;
	}

	Node<T>* block = Move(index);
	Node<T>* blockPrev = block->prev;
	Node<T>* blockNext = block->next;

	if ((count > 1) && (blockPrev != NULL))
		blockPrev->next = blockNext;

	if ((count > 1) && (blockNext != NULL))
		blockNext->prev = blockPrev;

	if (index == 0)
		root = blockNext;

	if (index == count - 1)
		end = blockPrev;

	delete block;
	count--;
}

template <class T>
void list<T>::printList(int forward)
{
	Node<T>* block;
	if (forward == 1)
	{
		block = root;
		while (block != NULL)
		{
			std::cout << block->info << endl;
			block = block->next;

		}
	}
	if (forward == 0)
	{
		block = end;
		while (block != NULL)
		{
			std::cout << block->info << endl;
			block = block->prev;
		}

	}
}

template <class T>
int list<T>::Count()
{
	return this->count;
}

template <class T>
T& list<T>::getElement(int index)
{
	if(!correctIndex(index))
		throw out_of_range("Incorrect index.");

	Node<T>* block = Move(index);

	return block->info;
}

template <class T>
void list<T>::setElement(const T& info,int index)
{
	if (!correctIndex(index))
		return;

	Node<T>* block = Move(index);
	block->info = info;
}

template <class T>
void list<T>::Clear()
{
	int countDelete = count;
	for (int index = 0; index < countDelete; index++)
		Delete(0);
}