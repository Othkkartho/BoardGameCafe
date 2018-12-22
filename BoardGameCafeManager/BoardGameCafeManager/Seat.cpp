// 20181521 ������ / �⸻ ���� / �¼� ���� ���α׷�

#include "pch.h"
#include "Seat.h"
#include <iostream>
#include <string>


//Setter Function
void Seat::setLine(std::string line) { this->line = line; };
void Seat::setName(std::string name) { this->name = name; };
void Seat::setNext(Seat* next) {
	this->next = next;
};

//Getter Function
std::string Seat::getLine() { return line; };
std::string Seat::getName() { return name; };
Seat* Seat::getNext() { return next; };

//��� �Լ�
void Seat::SeatAdd(std::string line, std::string name)
{
	Seat *seat = new Seat;

	if (head == NULL)     //head,last pointer setting
	{
		head = seat;
		last = seat;
	}
	else   //pointing next customer
	{
		last->setNext(seat);
		last = seat;
	}

	seat->setLine(line); seat->setName(name);
};
void Seat::SeatList()
{
	Seat *seat = NULL;
	while (true)
	{
		if (seat == NULL) // seat�ʱⰪ ����
			seat = head;
		std::cout << "�ڸ� : " << seat->getLine() << "\t�̸� : " << seat->getName() << std::endl;
		if (seat->getNext() == NULL)// ������ ��忡 �����ϸ� �Լ� ����
			return;
		seat = seat->getNext();
	}
};
void Seat::SeatSearch(std::string searchStr, std::string mod)
{
	std::string(Seat::*func)() = NULL;//����Լ������ͻ��
	if (mod == "line" || mod == "Line")
		func = &Seat::getLine;
	else if (mod == "name" || mod == "Name")
		func = &Seat::getName;
	Seat *seat = NULL;
	while (true)
	{
		if (seat == NULL) // seat�ʱⰪ ����
			seat = head;
		if (searchStr == (seat->*func)())
			std::cout << "�ڸ� : " << seat->getLine() << "\t�̸� : " << seat->getName() << std::endl;
		if (seat->getNext() == NULL)// ������ ��忡 �����ϸ� �Լ� ����
			return;
		seat = seat->getNext();
	}
};
void Seat::SeatDelete(std::string searchStr, std::string mod)
{
	std::string(Seat::*func)() = NULL; //����Լ������ͻ��
	if (mod == "line" || mod == "Line")
		func = &Seat::getLine;
	else if (mod == "name" || mod == "Name")
		func = &Seat::getName;
	Seat *firstIndex, *lastIndex;
	firstIndex = lastIndex = NULL;
	while (true)
	{
		if (firstIndex == NULL) // customer�ʱⰪ ����
		{
			firstIndex = head;
			lastIndex = head;
		}
		if (searchStr == (firstIndex->*func)())
		{
			lastIndex->setNext(firstIndex->getNext());
			delete firstIndex;
			this->head = NULL;
			return;
		}
		if (firstIndex->getNext() == NULL)// ������ ��忡 �����ϸ� �Լ� ����
			return;

		lastIndex = firstIndex;
		firstIndex = firstIndex->getNext();
	}
};