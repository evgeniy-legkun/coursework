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
		ifstream fin("allcars.txt");// �������� ��� ������
		ofstream fout("info_�f_�ars.txt", ios_base::out | ios_base::trunc);//�������� ��� ������
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
			// �������� �-� �������� ���������� ��
			break;
			}
	case 3: {
			break;
			}
		}
	
	
	



	
	_gettch();
	return 0;
}

