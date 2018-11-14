#include "Header.h"

// функция для генерации случайного пароля
void passwordGen() {
	char setOfCharachters[] = "qwertyuiopsdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
	string password;
	int passwordLength, symbol;
	ofstream out_file;
	out_file.open("password.txt");
	cout << "Введите количество символов вашего пароля:";
	cin >> passwordLength;
	srand(time(NULL));
	for (int i = 1; i <= passwordLength; i++) {
		symbol = rand() % 63 + 1;
		out_file << setOfCharachters[symbol];
		cout << setOfCharachters[symbol];
	}
	out_file.close();
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

//поиск клиента по имени
void Client::FindClientByName() {
	if (firstCl != NULL) {
		cout << "Введите имя клиента: ";
		cin >> key;
		int check = 0;
		Client *p = firstCl;
		while (p != NULL) {
			if (strcmp(p->name, key) == 0) {
				cout << "Искомый клиент: " << endl;
				cout << "Имя: " << p->name << endl;
				cout << "Фамилия: " << p->surname << endl;
				cout << "Возраст: " << p->age << endl;
				cout << "Адрес: ул." << p->street << ", д." << p->houseNumber << ", кв." << p->flat << endl;
				cout << "______________________" << endl;
				check++;
				p = p->next;
				continue;
			}
			else {
				p = p->next;
			}
		}
		if (check < 1) {
			cout << "Клиентов с данным именем не было найдено" << endl;
			return;
		}
	}
	else {
		cout << "Список клиентов пуст" << endl;
	}
}

//поиск клиента по фамилии
void Client::FindClientBySurname() {
	if (firstCl != NULL) {
		cout << "Введите фамилию клиента: ";
		cin >> key;
		int check = 0;
		Client *p = firstCl;
		while (p != NULL) {
			if (strcmp(p->surname, key) == 0) {
				cout << "Искомый клиент: " << endl;
				cout << "Имя: " << p->name << endl;
				cout << "Фамилия: " << p->surname << endl;
				cout << "Возраст: " << p->age << endl;
				cout << "Адрес: ул." << p->street << ", д." << p->houseNumber << ", кв." << p->flat << endl;
				cout << "______________________" << endl;
				check++;
				p = p->next;
				continue;
			}
			else {
				p = p->next;
			}
		}
		if (check < 1) {
			cout << "Клиентов с данной фамилией не было найдено" << endl;
			return;
		}
	}
	else {
		cout << "Список клиентов пуст" << endl;
	}
}

//поиск клиента по адресу
void Client::FindClientByAdress() {
	if (firstCl != NULL) {
		cout << "Введите название улицы, на которой проживает клиент: ";
		cin >> key;
		cout << "Введите номер дома клиента: ";
		cin >> houseNumberFind;
		int check = 0;
		Client *p = firstCl;
		while (p != NULL) {
			if (strcmp(p->street, key) == 0&& houseNumber==houseNumberFind) {
				cout << "Искомый клиент: " << endl;
				cout << "Имя: " << p->name << endl;
				cout << "Фамилия: " << p->surname << endl;
				cout << "Возраст: " << p->age << endl;
				cout << "Адрес: ул." << p->street << ", д." << p->houseNumber << ", кв." << p->flat << endl;
				cout << "______________________" << endl;
				check++;
				p = p->next;
				continue;
			}
			else {
				p = p->next;
			}
		}
		if (check < 1) {
			cout << "Клиентов по данному адресу не было найдено" << endl;
			return;
		}
	}
	else {
		cout << "Список клиентов пуст" << endl;
	}
}

//запись данных о клиентах в файл
void Client::SaveClientInf() {
	ofstream cl_out;
	cl_out.open("Data about client.txt"/*,ofstream::app*/);
	if (!cl_out.is_open()){
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		Client *p = firstCl;
		while (p!= NULL) {
			cl_out << p->name;
			cl_out << p->surname;
			cl_out << p->age;
			cl_out << p->street;
			cl_out << p->houseNumber;
			cl_out << p->flat;
			p = p->next;
		}
	}
	cl_out.close();
}

//загрузка данных о клиентах из файла
void Client::DownloadClientInf(){
	ifstream cl_in;
	cl_in.open("Data about client.txt");
	if (!cl_in.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		Client *p = firstCl;
		while (p != NULL) {
			cl_in >> name;
			cl_in >> p->surname;
			cl_in >> p->age;
			cl_in >> p->street;
			cl_in >> p->houseNumber;
			cl_in >> p->flat;
			p = p->next;
		}
	}
	cl_in.close();
}

//редактирование основной информации о клиенте
void Client::EditClientInfo() {
	int clientNumber;
	Client *p = firstCl;
	int number = 1;
	cout << "\t\t\tcписок клиентов" << endl;
	if (firstCl != NULL) {
		while (p != NULL) {
			cout << "Номер - " << number << endl;
			cout << "Имя: " << p->name << endl;
			cout << "Фамилия: " << p->surname << endl;
			cout << "Возраст: " << p->age << endl;
			cout << "Адрес: ул." << p->street << ", д." << p->houseNumber << ", кв." << p->flat << endl;
			cout << "______________________" << endl;
		    p = p->next;
			number++;
		}
	}
	else {
		cout << "Нет клиентов" << endl;
		return;
	}
	cout << "Выберите клиента,данные которого хотите отредактировать:";
	int checkNumber = 1;
	Client *pCl = firstCl;
	cin >> clientNumber;
	number = number - 1;
    if (clientNumber<= number && clientNumber!=0) {
		int selectEditCharact;
		cout << "Выберите, что хотите отредактировать" << endl;
		cout << "1.Редактировать имя" << endl;
		cout << "2.Редактировать фамилию" << endl;
		cout << "3.Редактировать возраст" << endl;
		cout << "4.Редактировать адрес клиента" << endl;
		cin >> selectEditCharact;
		switch (selectEditCharact) {
		case 1:
		{
			while (checkNumber != clientNumber) {
				pCl = pCl->next;
				checkNumber++;
			}

			cout << "Старое имя клиента: " << pCl->name << endl;
			cout << "Введите новое имя клиента: ";
			cin >> pCl->name;
			system("cls");
			cout << "Данные успешно отредактированы" << endl;
		}
		break;
		case 2:
		{
			while (checkNumber != clientNumber) {
				pCl = pCl->next;
				checkNumber++;
			}
			cout << "Старая фамилию клиента: " << pCl->surname << endl;
			cout << "Введите новую фамилию клиента: ";
			cin >> pCl->surname;
			system("cls");
			cout << "Данные успешно отредактированы" << endl;
		}
		break;
		case 3:
		{
			while (checkNumber != clientNumber) {
				pCl = pCl->next;
				checkNumber++;
			}
			cout << "Возраст: " << pCl->age << endl;
			cout << "Введите новую информацию о возрасте: ";
			cin >> pCl->age;
			system("cls");
			cout << "Данные успешно отредактированы" << endl;
		}
		break;
		case 4: {
			while (checkNumber != clientNumber) {
				pCl = pCl->next;
				checkNumber++;
			}
			cout << "Предыдущий адрес клиента: " << "ул." << pCl->street << "д." << pCl->houseNumber << "кв." << pCl->flat << endl;
			cout << "Введите действующее название улицы:";
			cin >> pCl->street;
			cout << "Введите номер дома: ";
			cin >> pCl->houseNumber;
			cout << "Введите номер квартиры:";
			cin >> pCl->flat;
			system("cls");
			cout << "Данные успешно отредактированы" << endl;
		}
		break;
		default: cout << "Выберите один их доступных вариантов" << endl;
	   }
	}
	else {
		cout << "Выберите одного из доступных клиентов" << endl;
	}
}

//сортировка клиентов по имени
////////////////////////////////////////////



//ввод основной информации о заказе
void Order::setOrderInf() {
	orderName = new char[20];
	cout << "Введите тип заказа: ";
	cin >> this->orderName;
	cout << "Введите код заказа: ";
	cin >> this->orderCode;
	cout << "Введите код клиента: ";
	cin >> this->clientCode;
	cout << "Введите стоимость заказа: ";
	cin >> this->OrderCost;
	cout << "Введите стоимость доставки заказа: ";
	cin >> this->DeliveryCost;
}

//получение основной информации о заказе
void Order::getOrderInf() {
	system("cls");
	cout << "Тип заказа: " << this->orderName << endl;
	cout << "Код заказа: " << this->orderCode << endl;
	cout << "Код клиента: " << this->clientCode << endl;
	cout << "Стоимость заказа: " << this->OrderCost << endl;
	cout << "Cтоимость доставки: " << this->DeliveryCost << endl;
}