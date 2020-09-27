// Эта программа переводит числа из одной системы счисления в другую
//

#include "pch.h"
#include <iostream>
using namespace std;

int AnyToTen(int userChoice) {
	char digit = '\0';
	int numberSum = 0;
	digit = cin.get();

	cout << "Введите число :" << endl;
	digit = cin.get();
	while(digit != 10) {
		if (digit - '0' < 10) {
			numberSum = numberSum * userChoice + (digit - '0');// + (digit - '0') преобразует код цифры в ASCII в обычную цифру
			digit = cin.get();
		}
		else {
			switch (digit)// переводит цифры систем счисления с основанием > 0 в десятичные числа
			{
			case 'A':
				if (userChoice > 10) {
					numberSum = numberSum * userChoice + 10;
					digit = cin.get();
				}
				else { digit = cin.get(); }
				break;
			case 'B':
				if (userChoice > 11) {
					numberSum = numberSum * userChoice + 11;
					digit = cin.get();
				}
				else { digit = cin.get(); }
				break;
			case 'C':
				if (userChoice > 12) {
					numberSum = numberSum * userChoice + 12;
					digit = cin.get();
				}
				else { digit = cin.get(); }
				break;
			case 'D':
				if (userChoice > 13) {
					numberSum = numberSum * userChoice + 13;
					digit = cin.get();
				}
				else { digit = cin.get(); }
				break;
			case 'E':
				if (userChoice > 14) {
					numberSum = numberSum * userChoice + 14;
					digit = cin.get();
				}
				else { digit = cin.get(); }
				break;
			case 'F':
				if (userChoice > 15) {
					numberSum = numberSum * userChoice + 15;
					digit = cin.get();
				}
				else { digit = cin.get(); }
				break;
			default:
				digit = cin.get();
				break;
			}
		}
		
	}
	return numberSum;
}
void tenToAny(int userChoice,int userNumber) {
	
	int checkNum = userChoice;

	
	

	cout << "Ваше число в "<< userChoice<<"-ой системе счисления равно  равно: ";
	while (checkNum > 0) {
		while (userNumber - checkNum * userChoice >= 0) {
			checkNum *= userChoice;
		}

		if (userNumber - checkNum >= 0) {
			switch (userNumber / checkNum)
			{
			case 15:
				cout << 'F';
				break;
			case 14:
				cout << 'E';
				break;
			case 13:
				cout << 'D';
				break;
			case 12:
				cout << 'C';
				break;
			case 11:
				cout << 'B';
				break;
			case 10:
				cout << 'A';
				break;
			default:
				cout << userNumber / checkNum;
				break;
			}
			while (userNumber - checkNum >= 0) { userNumber -= checkNum; }

		}
		else {
			cout << userNumber / checkNum;

		}
		checkNum /= userChoice;
	}

}

int main()
{
	setlocale(LC_ALL, "Russian");

	int userChoiceFrom = 0;
	int userChoiceTo = 0;
	

	cout << "Это программа переводит числа из одной системы счисления в другую, если"  << endl;
	cout << "основания обеих системы счисления от 2 до 16." << endl;
	cout << "Введите основание системы счисления из которой надо перевести." << endl;
	cin >> userChoiceFrom;
	cout << "Введите основание системы счисления в которую надо перевести." << endl;
	cin >> userChoiceTo;
	

	if (userChoiceTo == 10) {
		cout <<"Ваше число в 10-ой системе счисления равно :"<<  AnyToTen(userChoiceFrom);
	}
	else if (userChoiceFrom == 10) {
		cout << "Введите число :" << endl;
		int userNumber = 0;
		cin >> userNumber;
		tenToAny(userChoiceTo, userNumber);
	}
	else {
		tenToAny(userChoiceTo, AnyToTen(userChoiceFrom));
	}
	return 0;
}