// СourseWorkC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class showAvto {
private:
	string number; //тех.номер машины
	string info;//буфер для считывания с файла
	vector<string> infoVector;
	bool searchСar; //фиксирует найден ли автомобиль
public:
	showAvto() {
		number = "";
		info = ""; 
		searchСar = false;
	}
	void showAvtoByNumber() {
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
			cout << "Введите номер авто: ";
			cin >> number;
			system("cls");
			fin.close(); //закрываем файл allcars
			for (int i = 0; i < infoVector.size(); i++) // проход по всему вектору
			{
				if (infoVector[i] == number) //если строка с номером найдена
				{
					for (int i1 = i; i1 < infoVector.size(); i1++)
					{
						if (infoVector[i1] == "$")
							break;
						fout << infoVector[i1] << endl;
						cout << infoVector[i1] << endl;//делаем вывод на консоль для демонстрации
					}
					searchСar = true;
				}
			}
			if (searchСar == false)
			{
				fout << "Такого номера нет в базе !!!";
				cout << "Такого номера нет в базе !!!";
			}
		}
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
			for (int i = 0; i < infoVector.size(); i++) //ищим номер у векторе (в файле info_about_allcars.txt)
			{
				if (infoVector[i] == number)
					cout << "Есть такой номер" << endl;  //это для проверки
				// тут нужно реализовать условие выхода если найден номер машины в файле
				//
			}
		}
				
		/**/ // выше реализуем поиск номера автообиля
		/**/ // ниже у нас будет вывод в файл необходимых мер по ТО
		cout << "Какой пробег у автомобиля ?" << endl;
		cout << "Ввод пробега: ";
		cin >> mileage;
		if (mileage <= 0 || mileage > 500000) // сначала сделаем правельный ввод
		{									  // но проверки на ввод строки я не делал
			while (mileage <= 0 || mileage > 500000) {
				cout << "Такого пробега не может быть !!!" << endl;
				cout << "Повторите ввод_ : ";
				cin >> mileage;
			}
			system("cls");
		}
		
		//ofstream fout("output_info_aboutTOCar.txt", ios_base::out | ios_base::trunc);//открытие для записи
		//if (!fout.is_open())
		//	cout << "Файл не может быть открыт!\n";
		//else {
		//		
		//	}
		//}

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
		while (selection > 3 || selection <= 0) {
			cout << "Неправельный ввод ! Повторите !" << endl;
			cout << "Ваш выбор _:  ";
			cin >> selection;
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

