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


		cout << "\t\t\t\tМеню"<<endl;
		cout << "1.Сгенерировать пароль" << endl;
		cout << "2.Проверка класса Person" << endl;
		cout << "3.Добавление клиента в начало списка" << endl;
		cout << "4.Вывод списка клиентов на экран" << endl;
		cout << "5.Добавление клиента в конец списка" << endl;
		cout << "6.Удаление клиента из списка" << endl;
		cout << "7.Поиск клиента по имени" << endl;
		cout << "8.Поиск клиента по адресу" << endl;
		cout << "9.Запись информации о клиентах в файл" << endl;
		cout << "10.Запись информации о клиентах из файла" << endl;
		cout << "11.Меню редактирования информации о клиентах" << endl;
		cout << "12.Поиск клиента по фамилии" << endl;
		cout << "0.Выход из программмы" << endl;
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
		case 7:
		{
			cl.FindClientByName();
			break;
		}
		case 8:
		{
			cl.FindClientByAdress();
			break;
		}
		case 9:
		{
			cl.SaveClientInf();
			break;
		}
		case 10:
		{
			cl.DownloadClientInf();
			break;
		}
		case 11:
		{
			cl.EditClientInfo();
			break;
		}
		case 12:
		{
			cl.FindClientBySurname();
			break;
		}
		case 0:
		{
			exit(0);
			break;
		}
		default:
			cout << "Выберите существующий пункт меню" << endl;
			break;
			}
		}

	system("pause");
	return 0;
}