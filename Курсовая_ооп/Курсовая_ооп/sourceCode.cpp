#include "Header.h"

// ������� ��� ��������� ���������� ������
void passwordGen() {
	char setOfCharachters[] = "qwertyuiopsdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
	string password;
	int passwordLength, symbol;
	ofstream out_file;
	out_file.open("password.txt");
	cout << "������� ���������� �������� ������ ������:";
	cin >> passwordLength;
	srand(time(NULL));
	for (int i = 1; i <= passwordLength; i++) {
		symbol = rand() % 63 + 1;
		out_file << setOfCharachters[symbol];
		cout << setOfCharachters[symbol];
	}
	out_file.close();
	cout<< endl << "��� ������ ������� ������������ � ������� � ����" << endl;
}  

//����������� �������� ���� �������� ���������� ������ Person
void Client::setMainPrsnInfo() {
	name = new char[20];
	surname = new char[20];
	street = new char[20];
	cout << "������� ��� �������: ";
	cin >> this->name;
	cout << "������� ������� �������: ";
	cin >> this->surname;
	cout << "������� ������� �������: ";
	cin >> this->age;
	cout << "������� �������� �����: ";
	cin >> this->street;
	cout << "������� ����� ����: ";
	cin >> this->houseNumber;
	cout << "������� ����� ��������: ";
	cin >> this->flat;
}

//����������� ������� ��������� �������� ���������� ������ Person
void Client::getMainPrsnInfo() {
	system("cls");
	cout << "���: " << this->name << endl;
	cout << "�������: " << this->surname << endl;
	cout << "�������: " << this->age << endl;
	cout << "�����: ��." << this->street << ", �." << this->houseNumber << ", ��." << this->flat << endl;
}

//���������� ������� � ������ ������
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

//����� ������ �������� �� �����
void Client::ShowClientList(){
	Client *p = firstCl;
	int number = 1;
		cout << "\t\t\tC����� ��������" << endl;
	while (p != NULL) {
	    cout << "����� - " << number << endl;
		cout << "���: " << p->name << endl;
		cout << "�������: " << p->surname << endl;
		cout << "�������: " << p->age << endl;
		cout << "�����: ��." <<p->street << ", �." << p->houseNumber << ", ��." << p->flat << endl;
     	cout << "______________________" << endl;
		number++;
		p = p->next;
	}
}

//���������� ������� � ����� ������
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

//�������� ������� �� ������
void Client::ClientDelete() {
	Client *p = firstCl;
	int n;
	cout << "������� ����� �������, �������� ������ �������: ";
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
	//������, ���� ����� ���������� ������� - ��� 1
	else {
		Client *pr = firstCl;
		firstCl = firstCl->next;
		delete pr;
		DelClientMessage();
	}
}

//�������-����, ��������� ��������� � �������� �������� �������
void DelClientMessage() {
	system("cls");
	cout << "������ ������� ������" << endl;
}

//����� ������� �� �����
void Client::FindClientByName() {
	if (firstCl != NULL) {
		cout << "������� ��� �������: ";
		cin >> key;
		int check = 0;
		Client *p = firstCl;
		while (p != NULL) {
			if (strcmp(p->name, key) == 0) {
				cout << "������� ������: " << endl;
				cout << "���: " << p->name << endl;
				cout << "�������: " << p->surname << endl;
				cout << "�������: " << p->age << endl;
				cout << "�����: ��." << p->street << ", �." << p->houseNumber << ", ��." << p->flat << endl;
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
			cout << "�������� � ������ ������ �� ���� �������" << endl;
			return;
		}
	}
	else {
		cout << "������ �������� ����" << endl;
	}
}

//����� ������� �� �������
void Client::FindClientBySurname() {
	if (firstCl != NULL) {
		cout << "������� ������� �������: ";
		cin >> key;
		int check = 0;
		Client *p = firstCl;
		while (p != NULL) {
			if (strcmp(p->surname, key) == 0) {
				cout << "������� ������: " << endl;
				cout << "���: " << p->name << endl;
				cout << "�������: " << p->surname << endl;
				cout << "�������: " << p->age << endl;
				cout << "�����: ��." << p->street << ", �." << p->houseNumber << ", ��." << p->flat << endl;
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
			cout << "�������� � ������ �������� �� ���� �������" << endl;
			return;
		}
	}
	else {
		cout << "������ �������� ����" << endl;
	}
}

//����� ������� �� ������
void Client::FindClientByAdress() {
	if (firstCl != NULL) {
		cout << "������� �������� �����, �� ������� ��������� ������: ";
		cin >> key;
		cout << "������� ����� ���� �������: ";
		cin >> houseNumberFind;
		int check = 0;
		Client *p = firstCl;
		while (p != NULL) {
			if (strcmp(p->street, key) == 0&& houseNumber==houseNumberFind) {
				cout << "������� ������: " << endl;
				cout << "���: " << p->name << endl;
				cout << "�������: " << p->surname << endl;
				cout << "�������: " << p->age << endl;
				cout << "�����: ��." << p->street << ", �." << p->houseNumber << ", ��." << p->flat << endl;
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
			cout << "�������� �� ������� ������ �� ���� �������" << endl;
			return;
		}
	}
	else {
		cout << "������ �������� ����" << endl;
	}
}

//������ ������ � �������� � ����
void Client::SaveClientInf() {
	ofstream cl_out;
	cl_out.open("Data about client.txt"/*,ofstream::app*/);
	if (!cl_out.is_open()){
		cout << "������ �������� �����" << endl;
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

//�������� ������ � �������� �� �����
void Client::DownloadClientInf(){
	ifstream cl_in;
	cl_in.open("Data about client.txt");
	if (!cl_in.is_open()) {
		cout << "������ �������� �����" << endl;
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

//�������������� �������� ���������� � �������
void Client::EditClientInfo() {
	int clientNumber;
	Client *p = firstCl;
	int number = 1;
	cout << "\t\t\tc����� ��������" << endl;
	if (firstCl != NULL) {
		while (p != NULL) {
			cout << "����� - " << number << endl;
			cout << "���: " << p->name << endl;
			cout << "�������: " << p->surname << endl;
			cout << "�������: " << p->age << endl;
			cout << "�����: ��." << p->street << ", �." << p->houseNumber << ", ��." << p->flat << endl;
			cout << "______________________" << endl;
		    p = p->next;
			number++;
		}
	}
	else {
		cout << "��� ��������" << endl;
		return;
	}
	cout << "�������� �������,������ �������� ������ ���������������:";
	int checkNumber = 1;
	Client *pCl = firstCl;
	cin >> clientNumber;
	number = number - 1;
    if (clientNumber<= number && clientNumber!=0) {
		int selectEditCharact;
		cout << "��������, ��� ������ ���������������" << endl;
		cout << "1.������������� ���" << endl;
		cout << "2.������������� �������" << endl;
		cout << "3.������������� �������" << endl;
		cout << "4.������������� ����� �������" << endl;
		cin >> selectEditCharact;
		switch (selectEditCharact) {
		case 1:
		{
			while (checkNumber != clientNumber) {
				pCl = pCl->next;
				checkNumber++;
			}

			cout << "������ ��� �������: " << pCl->name << endl;
			cout << "������� ����� ��� �������: ";
			cin >> pCl->name;
			system("cls");
			cout << "������ ������� ���������������" << endl;
		}
		break;
		case 2:
		{
			while (checkNumber != clientNumber) {
				pCl = pCl->next;
				checkNumber++;
			}
			cout << "������ ������� �������: " << pCl->surname << endl;
			cout << "������� ����� ������� �������: ";
			cin >> pCl->surname;
			system("cls");
			cout << "������ ������� ���������������" << endl;
		}
		break;
		case 3:
		{
			while (checkNumber != clientNumber) {
				pCl = pCl->next;
				checkNumber++;
			}
			cout << "�������: " << pCl->age << endl;
			cout << "������� ����� ���������� � ��������: ";
			cin >> pCl->age;
			system("cls");
			cout << "������ ������� ���������������" << endl;
		}
		break;
		case 4: {
			while (checkNumber != clientNumber) {
				pCl = pCl->next;
				checkNumber++;
			}
			cout << "���������� ����� �������: " << "��." << pCl->street << "�." << pCl->houseNumber << "��." << pCl->flat << endl;
			cout << "������� ����������� �������� �����:";
			cin >> pCl->street;
			cout << "������� ����� ����: ";
			cin >> pCl->houseNumber;
			cout << "������� ����� ��������:";
			cin >> pCl->flat;
			system("cls");
			cout << "������ ������� ���������������" << endl;
		}
		break;
		default: cout << "�������� ���� �� ��������� ���������" << endl;
	   }
	}
	else {
		cout << "�������� ������ �� ��������� ��������" << endl;
	}
}

//���������� �������� �� �����
////////////////////////////////////////////



//���� �������� ���������� � ������
void Order::setOrderInf() {
	orderName = new char[20];
	cout << "������� ��� ������: ";
	cin >> this->orderName;
	cout << "������� ��� ������: ";
	cin >> this->orderCode;
	cout << "������� ��� �������: ";
	cin >> this->clientCode;
	cout << "������� ��������� ������: ";
	cin >> this->OrderCost;
	cout << "������� ��������� �������� ������: ";
	cin >> this->DeliveryCost;
}

//��������� �������� ���������� � ������
void Order::getOrderInf() {
	system("cls");
	cout << "��� ������: " << this->orderName << endl;
	cout << "��� ������: " << this->orderCode << endl;
	cout << "��� �������: " << this->clientCode << endl;
	cout << "��������� ������: " << this->OrderCost << endl;
	cout << "C�������� ��������: " << this->DeliveryCost << endl;
}