
#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
using std::cout; using std::cin;
using namespace std;

struct Film
{
	char movie[50];
	char producer[50];
	char genre[50];
	int year;
	float rating;
	float price;
};

void inscription(Film pat)
{
	cout << "\n��������\t: " << pat.movie;
	cout << "\n���������\t: " << pat.producer;
	cout << "\n����\t\t: " << pat.genre;
	cout << "\n���\t\t: " << pat.year;
	cout << "\n�������\t\t: " << pat.rating;
	cout << "\n����\t\t: " << pat.price << "\n";
	cout << "\n";
}

//����� �� �������� 
bool NameSearch(Film film[], char user[], int lenght)
{
	bool flag = 0;
	for (int i = 0; i < lenght; i++)
	{

		if (strstr(film[i].movie, user) != NULL)
		{
			cout << film[i].movie << " ";
			flag = true;
			break;
		}
		else { flag = false; }

	}
	return flag;
}

//����� �� ����� 
void GenreSearch(Film film, char user[])
{

	if (strstr(film.genre, user) != NULL)
	{
		cout << film.movie << " ";

	}

}

//����� �� ��������
void ProdSearch(Film film, char user[])
{

	if (strstr(film.producer, user) != NULL)
	{
		cout << film.movie << " ";

	}

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\t\t����������� �������������" << "\n";
	const int length = 10;
	int input = 0;

	Film videoStore[length]
	{
		{ "������� ����", "����� ��������", "�����", 1999, 9.1, 10.2 },
		{ "����� �� ��������", "����� ��������", "�����", 1994, 8.9, 10.0 },
		{ "������ ��������", "������ ��������", "�����", 1993, 8.9, 10.0 },
		{ "������� ����", "������ �������", "�����", 1994, 8.8, 9.8 },
		{ "������������ �����", "������� ���������", "��������", 1994, 8.7, 9.0 },
		{ "������������", "��������� �����", "����������", 2014, 8.7, 9.0 },
		{ "������", "��������� �����", "����������", 2010, 8.6, 8.5 },
		{ "���������", "����� �����", "�������", 2000, 8.6, 8.0 },
		{ "����������� �� �����", "����� ��", "�����", 1997, 8.6, 8.0 },
		{ "�������", "���� ��������", "����������", 1999, 8.5, 8.0 }
	};

	do
	{
		cout << "\t      ���� ��������" << "\n";
		cout << "\n����� �� �������� - [1]" << "\n";
		cout << "����� �� ����� - [2]" << "\n";
		cout << "����� �� ���������� - [3]" << "\n";
		cout << "�������� ���� ������ ������� - [4]" << "\n";
		cout << "����� - [5]" << "\n";
		cout << "�����: ";
		cin >> input;
		cout << "\n";

		switch (input)
		{
		case 1:
			char user1[50];
			cout << "�������� �������� ������: ";
			cin >> user1;

			if (NameSearch(videoStore, user1, length) == true)
			{
				cout << "(����� ������)\n" << "\n";
			}
			else cout << "(����� �� ������)\n" << "\n";

		case 2:
			char user2[50];
			cout << "������� ���� ������: ";
			cin >> user2;
			for (int i = 0; i < length; i++)
			{
				GenreSearch(videoStore[i], user2);
			}
			cout << "\n";

		case 3:
			char user3[50];
			cout << "������� ���������� ������: ";
			cin >> user3;
			for (int i = 0; i < length; i++)
			{
				ProdSearch(videoStore[i], user3);
			}
			cout << "\n";

		case 4:
			for (int i = 0; i < length; i++)
				inscription(videoStore[i]);

		case 5:
			break;
		default:
			break;
		}
	} while (input == 4);

	cout << endl; cout << "\n";

	return 0;
}