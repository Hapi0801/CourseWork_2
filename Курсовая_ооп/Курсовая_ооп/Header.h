#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <ctime>
#include <conio.h>
#include <Windows.h>

using namespace std;

void passwordGen();

class freeCouriers {
private:
};

class freeOperators {
private:
};

class freeCar {

};

class typeOfOrder {

};

//класс человек(будет наследоватьс€)
class Person {
protected:
	char *name;
	char *surname;
	int age;
public:
	Person() {
		this->name = nullptr;
		this->surname = nullptr;
		this->age = NULL;
	}
	~Person() {
		delete name;
		delete surname;
	}
	
	virtual void setMainPrsnInfo()=0;
	virtual void getMainPrsnInfo()=0;
};

//класс  лиент
class Client:public Person {
private:
	Client *firstCl;
	Client *lastCl;
	Client *next;
protected:
	char *street;
	int houseNumber;
	int flat;

public:
	Client() {
		this->street = nullptr;
		this->houseNumber = NULL;
		this->flat = NULL;
	}
	~Client() {
		delete street;
	}
	void setMainPrsnInfo();
	void getMainPrsnInfo();
	void AddFirstClient();
	void AddLastClient();
	void ShowClientList();
	void ClientDelete();
	friend void DelClientMessage();
};

