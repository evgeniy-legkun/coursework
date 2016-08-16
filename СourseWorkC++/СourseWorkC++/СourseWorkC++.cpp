// �ourseWorkC++.cpp : Defines the entry point for the console application.
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
	string number; //���.����� ������
	string info;//����� ��� ���������� � �����
	vector<string> infoVector;
public:
	showAvto() {
		number = "";
		info = ""; 
	}
	void showAvtoByNumber() {
		bool search�ar = false; //��������� ������ �� ����������
		ifstream fin("info_about_allcars.txt");// �������� ��� ������
		ofstream fout("output_info_�f_�ars.txt", ios_base::out | ios_base::trunc);//�������� ��� ������
		if (!fin.is_open() || !fout.is_open())
			cout << "���� �� ����� ���� ������!\n";
		else
		{
			do {
				getline(fin, info);
				infoVector.push_back(info);
			} while (info != ""); //��������� ���� � ������
			do {
				system("cls");
				cout << "������� ����� ����: ";
				cin >> number;
				system("cls");
				for (unsigned int i = 0; i < infoVector.size(); i++) // ������ �� ����� �������
				{
					if (infoVector[i] == number) //���� ������ � ������� �������
					{
						for (unsigned int i1 = i; i1 < infoVector.size(); i1++)
						{
							if (infoVector[i1+1] == "$")
								break;
							fout << infoVector[i1+1] << endl;
							cout << infoVector[i1+1] << endl;//������ ����� �� ������� ��� ������������
						}
						search�ar = true;
					}
				}
				if (search�ar == false)
				{
					cout << "����� ���������� �� ������ � ���� !\n";
					cout << "������� Enter � ���������� ������ ������ ����� ";
					_gettch();
				}
			} while (!search�ar);
		}
		fin.close(); //��������� ���� allcars
		fout.close();// ��������� ���� info_�f_�ars
	}
};

class carMaintenance {  //������������ ����������
private:
	string number; //���.����� ������
	int mileage; // ������
	string info;//����� ��� ���������� � �����
	vector<string> infoVector; //��������� ���� � ������
public:
	carMaintenance() {
		number = "";
		mileage = 0;
		info = "";
	}
	void maintenance() {
		bool n = false; //���������� ��� ������ � ����� ���� ����� ���� ������
		do {
			system("cls");
			cout << "������� ����� ����������: ";
			cin >> number; //���� �� ����� ������ ����� ���� � ����� info_about_allcars.txt
			ifstream fin("info_about_allcars.txt");// �������� ��� ������
			if (!fin.is_open())
				cout << "���� �� ����� ���� ������!\n";
			else
			{
				do {
					getline(fin, info);
					infoVector.push_back(info);
				} while (info != ""); //����������� ���� � ������
				for (unsigned int i = 0; i < infoVector.size(); i++) //���� ����� � ������� (� ����� info_about_allcars.txt)
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
					cout << "����� ���������� �� ������ � ���� !\n";
					cout << "������� Enter � ���������� ������ ������ �����";
					_gettch();
				}
			}
			fin.close();//������� ����
		} while (!n);
		system("cls");

		cout << "����� ������ � ���������� ?" << endl;
		while (true) // � ���� ����� �������� �� ���� ����, 0, - dec
		{
			cout << "���� �������: ";
			cin >> mileage;
			if (!cin || mileage <= 0 || mileage > 300000 /*��� ��������� ��� ������*/)
			{
				cout << "������ ������� �� ����� ���� !!!" << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
			else
			{
				system("cls");
				break;
			}
		}
		ifstream fin("info_about_TOCar.txt");// �������� ��� ������
		ofstream fout("output_info_aboutTOCar.txt", ios_base::out | ios_base::trunc);// ������� ���� ��� ������ ���� � ��
		if (!fout.is_open() || !fin.is_open())
			cout << "���� �� ����� ���� ������!\n";
		else {
			do {
				getline(fin, info);
				infoVector.push_back(info);
			} while (info != ""); //���������� ��� �� ��������� � ������
			if (mileage < 10000)
			{
				system("cls");
				fout << "��������� ������. �� �� ����� ���������.\n";
				cout << "��������� ������. �� �� ����� ���������.\n";
			}
			else if (mileage >= 10000 && mileage <= 15000)
				for (unsigned int i = 0; i < infoVector.size(); i++)// ������ �� ����� �������
				{
					if (infoVector[i] == "$1") //$1 - ��� �������� ����������� � ����� info_about_TOCar.txt ������ ���������� � ������ ����� �� ��� ������� 10000-15000 ��.
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
				for (unsigned int i = 0; i < infoVector.size(); i++)// ������ �� ����� �������
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
				for (unsigned int i = 0; i < infoVector.size(); i++)// ������ �� ����� �������
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
				for (unsigned int i = 0; i < infoVector.size(); i++)// ������ �� ����� �������
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
					fout << "������� �� ����������! �������� !" << endl;
					cout << "������� �� ����������! �������� !" << endl;
				}
				else if (x == 2)
				{
					fout << "���������� ������� ������������! " << endl;
					cout << "���������� ������� ������������! " << endl;
				}
				else if (x == 3)
				{
					fout << "���������� ������� � �����������! " << endl;
					cout << "���������� ������� � �����������! " << endl;
				}
				else if (x == 4)
				{
					fout << "�� ����� !!! ����� ������ ������ ! " << endl;
					cout << "�� ����� !!! ����� ������ ������ ! " << endl;
				}
			}
		}
		fin.close();// ��� ����� ������� - ��� ���������
		fout.close();
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int selection = 0;
	cout << "�������� ��������: " << endl;
	cout << "1. �������� �������������� ���������� �� ������. " << endl;
	cout << "2. ��������� ���� �� �������� ��. " << endl;
	cout << "3. �������� ��. " << endl;
	cout << "��� ����� _:  ";
	cin >> selection;
	system("cls");
	switch (selection)
		{
	default: {
		while (true) {
		if (!cin || selection > 3 || selection <= 0)
			{
				cout << "������������ ���� ! ��������� !" << endl;
				cout << "��� ����� _:  ";
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

