#include "Header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	int x;
	Client obj;
	Client cl;
	//system("cls");
	while (1) {


		cout << "\t\t\t\t����"<<endl;
		cout << "1.������������� ������" << endl;
		cout << "2.�������� ������ Person" << endl;
		cout << "3.���������� ������� � ������ ������" << endl;
		cout << "4.����� ������ �������� �� �����" << endl;
		cout << "5.���������� ������� � ����� ������" << endl;
		cout << "6.�������� ������� �� ������" << endl;
		cout << "0.����� �� ����������" << endl;
		cin >> x;
		switch (x) {
		case 1:
		{
			 passwordGen();
			 break;
		}
		case 2:
		{
			
			obj.setMainPrsnInfo();
			obj.getMainPrsnInfo();
			break;
		}
		case 3:
		{
			cl.setMainPrsnInfo();
			cl.getMainPrsnInfo();
			cl.AddFirstClient();
			break;
		}
		case 4:
		{
			cl.ShowClientList();
			break;
		}
		case 5:
		{
			cl.setMainPrsnInfo();
			cl.getMainPrsnInfo();
			cl.AddLastClient();
			break;
		}
		case 6:
		{
			cl.ShowClientList();
			cl.ClientDelete();
			break;
		}
		case 0:
		{
			exit(0);
			break;
		}
		default:
			cout << "�������� ������������ ����� ����" << endl;
			break;
			}
		}

	system("pause");
	return 0;
}