// 보드게임 카페 매니저 프로그램입니다.
//README.md꼭 읽을 것
#include "pch.h"
#include <iostream>
#include<string>
#include"customerManager.h"//고객관리 헤더파일

int main()
{
	CustomerManager customerManager;
	string name, ph;
	int year;
	int check = 1;
	customerManager.CustomerLoad("Save.txt");
	cout << "리스트 실행" << endl;
	customerManager.CustomerList();
	while (check)
	{
		cout << "이름 입력: "; std::cin >> name;
		cout << "전번 입력: "; std::cin >> ph;
		cout << "년도 입력: "; std::cin >> year;
		cout << "계속하시겠습니까?(1. 계속 0. 중지)"; std::cin >> check;
		customerManager.TeenCustomerRegister(name, ph, year);
	}
	customerManager.CustomerList();
	cout << "검색할 이름 입력: "; std::cin >> name;
	customerManager.CustomerSearch(name, "name");
	cout << customerManager.IsAdult(name, "name") << endl;
	cout << "삭제할 이름 입력: "; std::cin >> name;
	customerManager.CustomerDelete(name, "name");
	customerManager.CustomerList();
	
	customerManager.CustomerSave("Save.txt");
	customerManager.CustomerLoad("Save.txt");
}