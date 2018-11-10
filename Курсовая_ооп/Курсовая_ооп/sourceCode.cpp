#include "Header.h"

// функция для генерации случайного пароля
void passwordGen() {
	char setOfCharachters[] = "qwertyuiopsdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
	string password;
	int passwordLength, symbol;
	ofstream out_file;
	out_file.open("password.txt");
	cout << "Введите количество симоволов вашего пароля:";
	cin >> passwordLength;
	srand(time(NULL));
	for (int i = 1; i <= passwordLength; i++) {
		symbol = rand() % 63 + 1;
		out_file << setOfCharachters[symbol];
		cout << setOfCharachters[symbol];
	}
	cout<< endl << "Ваш пароль успешно сгенерирован и записан в файл" << endl;
}  

//виртаульная фиункция ввод основных параметров класса Person
void Client::setMainPrsnInfo() {
	name = new char[20];
	surname = new char[20];
	street = new char[20];
	cout << "Введите имя клиента: ";
	cin >> this->name;
	cout << "Введите фамилию клиента: ";
	cin >> this->surname;
	cout << "Введите возраст клиента: ";
	cin >> this->age;
	cout << "Введите название улицы: ";
	cin >> this->street;
	cout << "Введите номер дома: ";
	cin >> this->houseNumber;
	cout << "Введите номер квартиры: ";
	cin >> this->flat;
}

//виртуальная функция получение основных параметров класса Person
void Client::getMainPrsnInfo() {
	system("cls");
	cout << "Имя: " << this->name << endl;
	cout << "Фамилия: " << this->surname << endl;
	cout << "Возраст: " << this->age << endl;
	cout << "Адрес: ул." << this->street << ", д." << this->houseNumber << ", кв." << this->flat << endl;
}

//добавление клиента в начало списка
void Client::AddFirstClient() {
	Client *p = new Client;
	p->next = firstCl;
	p->name=this->name;
	p->surname = this->surname;
	p->age = this->age;
	p->street = this->street;
	p->houseNumber = this->houseNumber;
	p->flat = this->flat;
	firstCl = p;
	if (lastCl == NULL) {
		lastCl = firstCl;
	}
}

//вывод списка клиентов на экран
void Client::ShowClientList(){
	Client *p = firstCl;
	int number = 1;
		cout << "\t\t\tCписок клиентов" << endl;
	while (p != NULL) {
	    cout << "Номер - " << number << endl;
		cout << "Имя: " << p->name << endl;
		cout << "Фамилия: " << p->surname << endl;
		cout << "Возраст: " << p->age << endl;
		cout << "Адрес: ул." <<p->street << ", д." << p->houseNumber << ", кв." << p->flat << endl;
     	cout << "______________________" << endl;
		number++;
		p = p->next;
	}
}

//добавление клиента в конец списка
void Client::AddLastClient() {
	Client *p = new Client;
	if (lastCl == NULL) {
		p->name = this->name;
		p->surname = this->surname;
		p->age = this->age;
		p->street = this->street;
		p->houseNumber = this->houseNumber;
		p->flat = this->flat;
		lastCl = p;
	}
	else {
		lastCl->next = p;
		p->name = this->name;
		p->surname = this->surname;
		p->age = this->age;
		p->street = this->street;
		p->houseNumber = this->houseNumber;
		p->flat = this->flat;
		p->next = NULL;
		lastCl = p;
	}
}

//удаление клиента из списка
void Client::ClientDelete() {
	Client *p = firstCl;
	int n;
	cout << "Введите номер клиента, которого хотите удалить: ";
	cin >> n;
	if (n != 1) {
		for (int i = 1; i < (n - 1); i++) {
			p = p->next;
		}
		Client *pr = p->next;
		p->next = p->next->next;
		delete pr;
		DelClientMessage();
	}
	//случай, если номер удаляемого клиента - это 1
	else {
		Client *pr = firstCl;
		firstCl = firstCl->next;
		delete pr;
		DelClientMessage();
	}
}

//функция-друг, выводящая сообщение о успешном удалении клиента
void DelClientMessage() {
	system("cls");
	cout << "Клиент успешно удален" << endl;
}