#include "Header.h"


int main() {
	setlocale(LC_ALL, "rus");
	passwordGen();
	system("pause");
	return 0;
}

void passwordGen() {
	char setOfCharachters[] = "qwertyuiopsdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
	string password;
	int passwordLength, symbol;
	ofstream out_file;
	out_file.open("password.txt");
	cout << "Введите количество симоволов вашего пароля" << endl;
	cin >> passwordLength;
	srand(time(NULL));
	for (int i = 0; i <= passwordLength; i++) {
		symbol = rand() % 63;
		out_file << setOfCharachters[symbol];
	}
	cout << "Ваш пароль успешно сгенерирован и записан в файл" << endl;
}