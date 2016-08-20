// СourseWorkC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

class ShowAvto {
private:
	string number; //тех.номер машины
	string info;//буфер для считывания с файла
	vector<string> infoVector;
public:
	ShowAvto() {
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
				cout << "Введите номер авто (от 101 до 105): ";
				cin >> number;
				system("cls");
				for (unsigned int i = 0; i < infoVector.size(); i++) // проход по всему вектору
				{
					if (infoVector[i] == number) //если строка с номером найдена
					{
						for (unsigned int i1 = i; i1 < infoVector.size(); i1++)
						{
							if (infoVector[i1 + 1] == "$")
								break;
							fout << infoVector[i1 + 1] << endl;
							cout << infoVector[i1 + 1] << endl;//делаем вывод на консоль для демонстрации
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

/*class carMaintenance {  //обслуживание автомобиля
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
			if (!cin || mileage <= 0 || mileage > 300000)
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
							if (infoVector[i1 + 1] == "$2")
								break;
							fout << infoVector[i1 + 1] << endl;
							cout << infoVector[i1 + 1] << endl;
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
*/

class RecService
{
private:
	int probeg, c;
	string info, s, sel;
	vector<string> vec;
	ifstream fin;
	ofstream fout;
public:
	RecService()
	{
		probeg = 0;
		c = 0;
		info = "";
		s = "";
		sel = "";
	}
	
	void whriteTO(string S)				// Функция записи прохождения сервисных работ
	{
		sel = S;
		fin.open(sel);					// в зависимости от выбора открываем нужный файл для записи
		while (!fin.eof())
		{
			getline(fin, info);			
			if (info != "")				// записываем информаций в вектор, если нет пустой строки
				vec.push_back(info);
		}
		fin.close();
		if (vec.size() == 0)			// если размер вектора = "0" (пустой файл),
			s = "0";					// то переменной s пирсваиваем "0",
		else
			s = vec[vec.size() - 1];	// для того, чтобы при пустом файле не выйти из области вектора, иначе записываем строку в "s"
		stringstream stream(s);			// Выделяем из строки число
		stream >> c;					// записываем в "с"
				
		fout.open(sel, ios::app);
			do {
				while (true) // в этом цыкле проверка на ввод букв, 0, - dec
				{
					cout << "Введите пробег автомобиля (км): ";
					cin >> probeg;
					if (!cin || probeg <= 0 || probeg > 300000 /*это примерный мах пробег*/)
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
				if (probeg > c)			// Сравниваем введенный пробег из последним значением в базе данных
				{
					if (probeg > 0 && probeg < 10000)
					{
						cout << "Еще рано проводить ТО" << endl;
						fout << probeg << "Еще рано проводить ТО" << endl;
					}
					else if (probeg >= 10000 && probeg < 20000 && c < 10000)	// в зависимости от пробега, выбираем нужное действие
					{
						cout << "Необходимо провести ТО 10000" << endl;
						cout << "Посещение СТО: Сервис 10000км - Замена моторного масла и фильтра." << endl;
						fout << probeg << "\tПосещение СТО: Сервис 10000км - Замена моторного масла и фильтра.\n";
					}
					else if (probeg >= 20000 && probeg < 30000 && c < 20000)
					{
						cout << "Необходимо провести ТО 20000" << endl;
						cout << "Посещение СТО: Сервис 20000км - Замена воздушного фильтра и свеч зажигания." << endl;
						fout << probeg << "\tПосещение СТО: Сервис 20000км - Замена воздушного фильтра и свеч зажигания.\n";
					}
					else if (probeg >= 30000 && probeg < 40000 && c < 30000)
					{
						cout << "Необходимо провести ТО 30000" << endl;
						cout << "Посещение СТО: Сервис 30000км - Замена масла трансмиссии, топливного фильтра и тормозной жидкости." << endl;
						fout << probeg << "\tПосещение СТО: Сервис 30000км - Замена масла трансмиссии, топливного фильтра и тормозной жидкости.\n";
					}
					else if (probeg >= 40000 && probeg < 50000 && c < 40000)
					{
						cout << "Необходимо провести ТО 40000" << endl;
						cout << "Посещение СТО: Сервис 40000км - Замена охлаждающей жидкости, проводного ремня: генератор системы охлаждения, кондиционер." << endl;
						fout << probeg << "\tПосещение СТО: Сервис 40000км - Замена охлаждающей жидкости, проводного ремня: генератор системы охлаждения, кондиционер.\n";
					}
					else if (probeg >= 50000 && probeg < 60000 && c < 50000)
					{
						cout << "Необходимо провести ТО 50000" << endl;
						cout << "Посещение СТО: Сервис 50000км - Замена зубчатого ремня газораспределения." << endl;
						fout << probeg << "\tПосещение СТО: Сервис 50000км - Замена зубчатого ремня газораспределения.\n";
					}
					else if (probeg >= 60000)
					{
						srand(time(NULL));
						int x = rand() % 4 + 1;
						if (x == 1)
						{
							cout << "\tПосещение СТО: Поломка не обнаружена! Везунчик !" << endl;
							fout << probeg << "\tПосещение СТО: Поломка не обнаружена! Везунчик !" << endl;
						}
						else if (x == 2)
						{
							cout << "\tПосещение СТО: Обнаружена поломка кондиционера! " << endl;
							fout << probeg << "\tПосещение СТО: Обнаружена поломка кондиционера! " << endl;
						}
						else if (x == 3)
						{
							cout << "\tПосещение СТО: Обнаружена поломка в карбюраторе! " << endl;
							fout << probeg << "\tПосещение СТО: Обнаружена поломка в карбюраторе! " << endl;
						}
						else if (x == 4)
						{
							cout << "\tПосещение СТО: Ты попал !!! Нужна замена мотора ! " << endl;
							fout << probeg << "\tПосещение СТО: Ты попал !!! Нужна замена мотора ! " << endl;
						}
					}
					else
					{
						cout << "Проведение ТО не требуется." << endl;
						fout << probeg << "\tПосещение СТО. Сервисные работы не проводились\n";
					}
				}
				else
					cout << "Введенный пробег меньше предыдущего. Введите актуальный: " << endl;
			} while (probeg <= c);
			fout.close();
			_gettch();
		}

	void showService(string S)		// Функция вывода информации по сервису
	{
		system("cls");
		fin.open(S);				// В зависимости от выбора автомобиля, открываем нужный файл
		while (!fin.eof())			// Пока нет конца файла - выводим информацию
		{
			getline(fin, info);
			cout << info << endl;
		} 
		fin.close();
		_gettch();
	}

	void clear()				// Функция очистки базы данных
	{
		fout.open("101.txt");
		fout << "";
		fout.close();
		fout.open("102.txt");
		fout << "";				// записываем в каждый файл пустую строку
		fout.close();
		fout.open("103.txt");
		fout << "";
		fout.close();
		fout.open("104.txt");
		fout << "";
		fout.close();
		fout.open("105.txt");
		fout << "";
		fout.close();
	}	

};

int main()
{
	setlocale(LC_ALL, "Russian");
	int selection = 0, pass = 0;
	string S = "";
	RecService A, B, C, D, E;
	int sel = 0;
	
	while (true)			// бесконечный цыкл, пока не будет команда выхода из программы
	{	
		system("cls");
		cout << "\n\t\t\t-=HYUNDAI=-\n" << endl;
		cout << "\t\tВыберите действие: " << endl;
		cout << "\t1. Показать характеристики автомобиля по номеру. " << endl;
		cout << "\t2. Заехать на сервис. Пускай посмотрят что там " << endl;
		cout << "\t3. Вывести информацию по проведенным работам" << endl;
		cout << "\t4. Очистить базу данных" << endl;
		cout << "\t5. Выход\n" << endl;
		cout << "\t\tВаш выбор _:  ";
		cin >> selection;
		system("cls");
		switch (selection)
		{
		default:
		{
			while (true)
			{
				if (!cin || selection > 5 || selection <= 0)
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
		case 1:			// Просмотр тех. характеристик автомобилей
		{
			ShowAvto avto;
			avto.showAvtoByNumber();
			_gettch();
			break;
		}
		case 2:			// Запись информации по сервисным работам
		{
			cout << "\tВведите номер автомомбиля (от 101 до 105) - ";
			cin >> sel;
			switch (sel)
			{
			default:
			{
				while (true) {
					if (!cin || sel > 105 || sel < 101)
					{
						cout << "Неправильный ввод ! Повторите !" << endl;
						cout << "Ваш выбор _:  ";
						cin >> sel;
						cin.clear();
						while (cin.get() != '\n');
					}
					else break;
				}
				system("cls");
			}
			case 101:
			{
				S = "101.txt";
				A.whriteTO(S);
				break;
			}
			case 102:
			{
				S = "102.txt";
				B.whriteTO(S);
				break;
			}
			case 103:
			{
				S = "103.txt";
				C.whriteTO(S);
				break;
			}
			case 104:
			{
				S = "104.txt";
				D.whriteTO(S);
				break;
			}
			case 105:
			{
				S = "105.txt";
				E.whriteTO(S);
				break;
			}
			}
			break;
		}
		case 3:			// Выбор просмотра информациии по автомобилям
		{
				system("cls");
				cout << "\n\tВыбирите авто для просмотра информации: \n" << endl;
				cout << "\t1 - Hyundai Elantra\t - № 101" << endl;
				cout << "\t2 - Hyundai Genesis\t - № 102" << endl;
				cout << "\t3 - Hyundai Grandeur\t - № 103" << endl;
				cout << "\t4 - Hyundai i40\t\t - № 104" << endl;
				cout << "\t5 - Hyundai Sonata\t - № 105" << endl << endl;
				cout << "\tВаш выбор - \t";
				cin >> sel;
				switch (sel)
				{
				default:
				{
					while (true) {
						if (!cin || sel > 5 || sel < 1)
						{
							cout << "Неправильный ввод ! Повторите !" << endl;
							cout << "Ваш выбор _:  ";
							cin >> sel;
							cin.clear();
							while (cin.get() != '\n');
						}
						else break;
					}
					system("cls");
				}
				case 1:
				{
					S = "101.txt";
					A.showService(S);
					break;
				}
				case 2:
				{
					S = "102.txt";
					B.showService(S);
					break;
				}
				case 3:
				{
					S = "103.txt";
					C.showService(S);
					break;
				}
				case 4:
				{
					S = "104.txt";
					D.showService(S);
					break;
				}
				case 5:
				{
					S = "105.txt";
					E.showService(S);
					break;
				}
				}
			break;
		}
		case 4:			// Выбор очистки базы данных
		{
			cout << "\n\n\t\tPLEASE ENTER PASSWORD ...   ";
			cin >> pass;
			if (pass == 1111)
				A.clear();
			break;
		}
		case 5:			// Выход из программы
		{
			exit(0);
			break;
		}
		}
	}
	
	return 0;
}