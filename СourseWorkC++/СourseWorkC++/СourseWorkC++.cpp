// �ourseWorkC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class showAvto {
private:
	string number; //���.����� ������
	string info;//����� ��� ���������� � �����
	vector<string> infoVector;
	bool search�ar; //��������� ������ �� ����������
public:
	showAvto() {
		number = "";
		info = ""; 
		search�ar = false;
	}
	void showAvtoByNumber() {
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
			cout << "������� ����� ����: ";
			cin >> number;
			system("cls");
			fin.close(); //��������� ���� allcars
			for (int i = 0; i < infoVector.size(); i++) // ������ �� ����� �������
			{
				if (infoVector[i] == number) //���� ������ � ������� �������
				{
					for (int i1 = i; i1 < infoVector.size(); i1++)
					{
						if (infoVector[i1] == "$")
							break;
						fout << infoVector[i1] << endl;
						cout << infoVector[i1] << endl;//������ ����� �� ������� ��� ������������
					}
					search�ar = true;
				}
			}
			if (search�ar == false)
			{
				fout << "������ ������ ��� � ���� !!!";
				cout << "������ ������ ��� � ���� !!!";
			}
		}
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
			for (int i = 0; i < infoVector.size(); i++) //���� ����� � ������� (� ����� info_about_allcars.txt)
			{
				if (infoVector[i] == number)
					cout << "���� ����� �����" << endl;  //��� ��� ��������
				// ��� ����� ����������� ������� ������ ���� ������ ����� ������ � �����
				//
			}
		}
				
		/**/ // ���� ��������� ����� ������ ���������
		/**/ // ���� � ��� ����� ����� � ���� ����������� ��� �� ��
		cout << "����� ������ � ���������� ?" << endl;
		cout << "���� �������: ";
		cin >> mileage;
		if (mileage <= 0 || mileage > 500000) // ������� ������� ���������� ����
		{									  // �� �������� �� ���� ������ � �� �����
			while (mileage <= 0 || mileage > 500000) {
				cout << "������ ������� �� ����� ���� !!!" << endl;
				cout << "��������� ����_ : ";
				cin >> mileage;
			}
			system("cls");
		}
		
		//ofstream fout("output_info_aboutTOCar.txt", ios_base::out | ios_base::trunc);//�������� ��� ������
		//if (!fout.is_open())
		//	cout << "���� �� ����� ���� ������!\n";
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
		while (selection > 3 || selection <= 0) {
			cout << "������������ ���� ! ��������� !" << endl;
			cout << "��� ����� _:  ";
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

