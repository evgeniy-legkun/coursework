// СourseWorkC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

class showAvto {
private:
	string number; //тех.номер машины
	string info;//буфер для считывания с файла
	vector<string> infoVector;
public:
	showAvto() {
		number = "";
		info = ""; 
	}
	void showAvtoByNumber() {
		bool searchСar = false; //фиксирует найден ли автомобиль
		ifstream fin("info_about_allcars.txt");// открытие для чтения
		ofstream fout("output_info_оf_сars.txt", ios_base::out | ios_base::trunc);//открытие для записи
		if (!fin.is_open() || !fout.is_open())
			cout << "Файл не может быть открыт!\n";
		else
		{
			do {
				getline(fin, info);
				infoVector.push_back(info);
			} while (info != ""); //добавляем инфу в вектор
			do {
				system("cls");
				cout << "Введите номер авто: ";
				cin >> number;
				system("cls");
				for (unsigned int i = 0; i < infoVector.size(); i++) // проход по всему вектору
				{
					if (infoVector[i] == number) //если строка с номером найдена
					{
						for (unsigned int i1 = i; i1 < infoVector.size(); i1++)
						{
							if (infoVector[i1+1] == "$")
								break;
							fout << infoVector[i1+1] << endl;
							cout << infoVector[i1+1] << endl;//делаем вывод на консоль для демонстрации
						}
						searchСar = true;
					}
				}
				if (searchСar == false)
				{
					cout << "Номер автомобиля не найден в базе !\n";
					cout << "Нажмите Enter и попробуйте ввести другой номер ";
					_gettch();
				}
			} while (!searchСar);
		}
		fin.close(); //закрываем файл allcars
		fout.close();// закрываем файл info_оf_сars
	}
};

class carMaintenance {  //обслуживание автомобиля
private:
	string number; //тех.номер машины
	int mileage; // пробег
	string info;//буфер для считывания с файла
	vector<string> infoVector; //считываем файл у вектор
public:
	carMaintenance() {
		number = "";
		mileage = 0;
		info = "";
	}
	void maintenance() {
		bool n = false; //используем для выхода с цыкла если номер авто найден
		do {
			system("cls");
			cout << "Введите номер автомобиля: ";
			cin >> number; //ниже мы будем искать номер авто в файле info_about_allcars.txt
			ifstream fin("info_about_allcars.txt");// открытие для чтения
			if (!fin.is_open())
				cout << "Файл не может быть открыт!\n";
			else
			{
				do {
					getline(fin, info);
					infoVector.push_back(info);
				} while (info != ""); //скопировали файл в вектор
				for (unsigned int i = 0; i < infoVector.size(); i++) //ищим номер у векторе (в файле info_about_allcars.txt)
				{
					if (infoVector[i] == number)
					{
						n = true;
						i = infoVector.size() + 1;
					}
				}
				if (n == false)
				{
					system("cls");
					cout << "Номер автомобиля не найден в базе !\n";
					cout << "Нажмите Enter и попробуйте ввести другой номер";
					_gettch();
				}
			}
			fin.close();//закрыли файл
		} while (!n);
		system("cls");

		cout << "Какой пробег у автомобиля ?" << endl;
		while (true) // в этом цыкле проверка на ввод букв, 0, - dec
		{
			cout << "Ввод пробега: ";
			cin >> mileage;
			if (!cin || mileage <= 0 || mileage > 300000 /*это примерный мах пробег*/)
			{
				cout << "Такого пробега не может быть !!!" << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
			else
			{
				system("cls");
				break;
			}
		}
		ifstream fin("info_about_TOCar.txt");// открытие для чтения
		ofstream fout("output_info_aboutTOCar.txt", ios_base::out | ios_base::trunc);// открыли файл для записи онфо о ТО
		if (!fout.is_open() || !fin.is_open())
			cout << "Файл не может быть открыт!\n";
		else {
			do {
				getline(fin, info);
				infoVector.push_back(info);
			} while (info != ""); //информацию про ТО заполняем у вектор
			if (mileage < 10000)
			{
				system("cls");
				fout << "Невысокий пробег. ТО не нужно проводить.\n";
				cout << "Невысокий пробег. ТО не нужно проводить.\n";
			}
			else if (mileage >= 10000 && mileage <= 15000)
				for (unsigned int i = 0; i < infoVector.size(); i++)// проход по всему вектору
				{
					if (infoVector[i] == "$1") //$1 - это условное обозначение в файле info_about_TOCar.txt начала информации о нужных мерах ТО при пробеге 10000-15000 км.
					{
						for (unsigned int i1 = i; i1 < infoVector.size(); i1++)
						{
							if (infoVector[i1+1] == "$2")
								break;
							fout << infoVector[i1+1] << endl;
							cout << infoVector[i1+1] << endl;
						}
					}
				}
			else if (mileage > 15000 && mileage <= 25000)
				for (unsigned int i = 0; i < infoVector.size(); i++)// проход по всему вектору
				{
					if (infoVector[i] == "$2") 
					{
						for (unsigned int i1 = i; i1 < infoVector.size(); i1++)
						{
							if (infoVector[i1 + 1] == "$3")
								break;
							fout << infoVector[i1 + 1] << endl;
							cout << infoVector[i1 + 1] << endl;
						}
					}
				}
			else if (mileage > 25000 && mileage <= 45000)
				for (unsigned int i = 0; i < infoVector.size(); i++)// проход по всему вектору
				{
					if (infoVector[i] == "$3") 
					{
						for (unsigned int i1 = i; i1 < infoVector.size(); i1++)
						{
							if (infoVector[i1 + 1] == "$4")
								break;
							fout << infoVector[i1 + 1] << endl;
							cout << infoVector[i1 + 1] << endl;
						}
					}
				}
			else if (mileage > 45000 && mileage <= 60000)
				for (unsigned int i = 0; i < infoVector.size(); i++)// проход по всему вектору
				{
					if (infoVector[i] == "$4") 
					{
						for (unsigned int i1 = i; i1 < infoVector.size(); i1++)
						{
							if (infoVector[i1 + 1] == "$5")
								break;
							fout << infoVector[i1 + 1] << endl;
							cout << infoVector[i1 + 1] << endl;
						}
					}
				}
			else if (mileage > 60000)
			{
				srand(time(NULL));
				int x = rand() % 4 + 1;
				static_cast<time_t>(x);
				if (x == 1)
				{
					fout << "Поломка не обнаружена! Везунчик !" << endl;
					cout << "Поломка не обнаружена! Везунчик !" << endl;
				}
				else if (x == 2)
				{
					fout << "Обнаружена поломка кондиционера! " << endl;
					cout << "Обнаружена поломка кондиционера! " << endl;
				}
				else if (x == 3)
				{
					fout << "Обнаружена поломка в карбюраторе! " << endl;
					cout << "Обнаружена поломка в карбюраторе! " << endl;
				}
				else if (x == 4)
				{
					fout << "Ты попал !!! Нужна замена мотора ! " << endl;
					cout << "Ты попал !!! Нужна замена мотора ! " << endl;
				}
			}
		}
		fin.close();// два файла открыли - два закрываем
		fout.close();
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int selection = 0;
	cout << "Выберите действие: " << endl;
	cout << "1. Показать характеристики автомобиля по номеру. " << endl;
	cout << "2. Проверить было ли пройдено ТО. " << endl;
	cout << "3. Провести ТО. " << endl;
	cout << "Ваш выбор _:  ";
	cin >> selection;
	system("cls");
	switch (selection)
		{
	default: {
		while (true) {
		if (!cin || selection > 3 || selection <= 0)
			{
				cout << "Неправельный ввод ! Повторите !" << endl;
				cout << "Ваш выбор _:  ";
				cin >> selection;
				cin.clear();
				while (cin.get() != '\n');
			}
		else break;
		}
		system("cls");
	}
	case 1: {
		showAvto avto;
		avto.showAvtoByNumber();
		break;
			}
	case 2: {
		
		break;
			}
	case 3: {
		carMaintenance avto;
		avto.maintenance();
		break;
			}
		}
	_gettch();
	return 0;
}

