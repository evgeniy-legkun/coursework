// �ourseWorkC++.cpp : Defines the entry point for the console application.
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
	string number; //���.����� ������
	string info;//����� ��� ���������� � �����
	vector<string> infoVector;
public:
	ShowAvto() {
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
				cout << "������� ����� ���� (�� 101 �� 105): ";
				cin >> number;
				system("cls");
				for (unsigned int i = 0; i < infoVector.size(); i++) // ������ �� ����� �������
				{
					if (infoVector[i] == number) //���� ������ � ������� �������
					{
						for (unsigned int i1 = i; i1 < infoVector.size(); i1++)
						{
							if (infoVector[i1 + 1] == "$")
								break;
							fout << infoVector[i1 + 1] << endl;
							cout << infoVector[i1 + 1] << endl;//������ ����� �� ������� ��� ������������
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

/*class carMaintenance {  //������������ ����������
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
			if (!cin || mileage <= 0 || mileage > 300000)
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
							if (infoVector[i1 + 1] == "$2")
								break;
							fout << infoVector[i1 + 1] << endl;
							cout << infoVector[i1 + 1] << endl;
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
	
	void whriteTO(string S)				// ������� ������ ����������� ��������� �����
	{
		sel = S;
		fin.open(sel);					// � ����������� �� ������ ��������� ������ ���� ��� ������
		while (!fin.eof())
		{
			getline(fin, info);			
			if (info != "")				// ���������� ���������� � ������, ���� ��� ������ ������
				vec.push_back(info);
		}
		fin.close();
		if (vec.size() == 0)			// ���� ������ ������� = "0" (������ ����),
			s = "0";					// �� ���������� s ����������� "0",
		else
			s = vec[vec.size() - 1];	// ��� ����, ����� ��� ������ ����� �� ����� �� ������� �������, ����� ���������� ������ � "s"
		stringstream stream(s);			// �������� �� ������ �����
		stream >> c;					// ���������� � "�"
				
		fout.open(sel, ios::app);
			do {
				while (true) // � ���� ����� �������� �� ���� ����, 0, - dec
				{
					cout << "������� ������ ���������� (��): ";
					cin >> probeg;
					if (!cin || probeg <= 0 || probeg > 300000 /*��� ��������� ��� ������*/)
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
				if (probeg > c)			// ���������� ��������� ������ �� ��������� ��������� � ���� ������
				{
					if (probeg > 0 && probeg < 10000)
					{
						cout << "��� ���� ��������� ��" << endl;
						fout << probeg << "��� ���� ��������� ��" << endl;
					}
					else if (probeg >= 10000 && probeg < 20000 && c < 10000)	// � ����������� �� �������, �������� ������ ��������
					{
						cout << "���������� �������� �� 10000" << endl;
						cout << "��������� ���: ������ 10000�� - ������ ��������� ����� � �������." << endl;
						fout << probeg << "\t��������� ���: ������ 10000�� - ������ ��������� ����� � �������.\n";
					}
					else if (probeg >= 20000 && probeg < 30000 && c < 20000)
					{
						cout << "���������� �������� �� 20000" << endl;
						cout << "��������� ���: ������ 20000�� - ������ ���������� ������� � ���� ���������." << endl;
						fout << probeg << "\t��������� ���: ������ 20000�� - ������ ���������� ������� � ���� ���������.\n";
					}
					else if (probeg >= 30000 && probeg < 40000 && c < 30000)
					{
						cout << "���������� �������� �� 30000" << endl;
						cout << "��������� ���: ������ 30000�� - ������ ����� �����������, ���������� ������� � ��������� ��������." << endl;
						fout << probeg << "\t��������� ���: ������ 30000�� - ������ ����� �����������, ���������� ������� � ��������� ��������.\n";
					}
					else if (probeg >= 40000 && probeg < 50000 && c < 40000)
					{
						cout << "���������� �������� �� 40000" << endl;
						cout << "��������� ���: ������ 40000�� - ������ ����������� ��������, ���������� �����: ��������� ������� ����������, �����������." << endl;
						fout << probeg << "\t��������� ���: ������ 40000�� - ������ ����������� ��������, ���������� �����: ��������� ������� ����������, �����������.\n";
					}
					else if (probeg >= 50000 && probeg < 60000 && c < 50000)
					{
						cout << "���������� �������� �� 50000" << endl;
						cout << "��������� ���: ������ 50000�� - ������ ��������� ����� �����������������." << endl;
						fout << probeg << "\t��������� ���: ������ 50000�� - ������ ��������� ����� �����������������.\n";
					}
					else if (probeg >= 60000)
					{
						srand(time(NULL));
						int x = rand() % 4 + 1;
						if (x == 1)
						{
							cout << "\t��������� ���: ������� �� ����������! �������� !" << endl;
							fout << probeg << "\t��������� ���: ������� �� ����������! �������� !" << endl;
						}
						else if (x == 2)
						{
							cout << "\t��������� ���: ���������� ������� ������������! " << endl;
							fout << probeg << "\t��������� ���: ���������� ������� ������������! " << endl;
						}
						else if (x == 3)
						{
							cout << "\t��������� ���: ���������� ������� � �����������! " << endl;
							fout << probeg << "\t��������� ���: ���������� ������� � �����������! " << endl;
						}
						else if (x == 4)
						{
							cout << "\t��������� ���: �� ����� !!! ����� ������ ������ ! " << endl;
							fout << probeg << "\t��������� ���: �� ����� !!! ����� ������ ������ ! " << endl;
						}
					}
					else
					{
						cout << "���������� �� �� ���������." << endl;
						fout << probeg << "\t��������� ���. ��������� ������ �� �����������\n";
					}
				}
				else
					cout << "��������� ������ ������ �����������. ������� ����������: " << endl;
			} while (probeg <= c);
			fout.close();
			_gettch();
		}

	void showService(string S)		// ������� ������ ���������� �� �������
	{
		system("cls");
		fin.open(S);				// � ����������� �� ������ ����������, ��������� ������ ����
		while (!fin.eof())			// ���� ��� ����� ����� - ������� ����������
		{
			getline(fin, info);
			cout << info << endl;
		} 
		fin.close();
		_gettch();
	}

	void clear()				// ������� ������� ���� ������
	{
		fout.open("101.txt");
		fout << "";
		fout.close();
		fout.open("102.txt");
		fout << "";				// ���������� � ������ ���� ������ ������
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
	
	while (true)			// ����������� ����, ���� �� ����� ������� ������ �� ���������
	{	
		system("cls");
		cout << "\n\t\t\t-=HYUNDAI=-\n" << endl;
		cout << "\t\t�������� ��������: " << endl;
		cout << "\t1. �������� �������������� ���������� �� ������. " << endl;
		cout << "\t2. ������� �� ������. ������ ��������� ��� ��� " << endl;
		cout << "\t3. ������� ���������� �� ����������� �������" << endl;
		cout << "\t4. �������� ���� ������" << endl;
		cout << "\t5. �����\n" << endl;
		cout << "\t\t��� ����� _:  ";
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
		case 1:			// �������� ���. ������������� �����������
		{
			ShowAvto avto;
			avto.showAvtoByNumber();
			_gettch();
			break;
		}
		case 2:			// ������ ���������� �� ��������� �������
		{
			cout << "\t������� ����� ����������� (�� 101 �� 105) - ";
			cin >> sel;
			switch (sel)
			{
			default:
			{
				while (true) {
					if (!cin || sel > 105 || sel < 101)
					{
						cout << "������������ ���� ! ��������� !" << endl;
						cout << "��� ����� _:  ";
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
		case 3:			// ����� ��������� ����������� �� �����������
		{
				system("cls");
				cout << "\n\t�������� ���� ��� ��������� ����������: \n" << endl;
				cout << "\t1 - Hyundai Elantra\t - � 101" << endl;
				cout << "\t2 - Hyundai Genesis\t - � 102" << endl;
				cout << "\t3 - Hyundai Grandeur\t - � 103" << endl;
				cout << "\t4 - Hyundai i40\t\t - � 104" << endl;
				cout << "\t5 - Hyundai Sonata\t - � 105" << endl << endl;
				cout << "\t��� ����� - \t";
				cin >> sel;
				switch (sel)
				{
				default:
				{
					while (true) {
						if (!cin || sel > 5 || sel < 1)
						{
							cout << "������������ ���� ! ��������� !" << endl;
							cout << "��� ����� _:  ";
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
		case 4:			// ����� ������� ���� ������
		{
			cout << "\n\n\t\tPLEASE ENTER PASSWORD ...   ";
			cin >> pass;
			if (pass == 1111)
				A.clear();
			break;
		}
		case 5:			// ����� �� ���������
		{
			exit(0);
			break;
		}
		}
	}
	
	return 0;
}