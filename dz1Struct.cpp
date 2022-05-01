
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
	cout << "\nНазвание\t: " << pat.movie;
	cout << "\nПродюссер\t: " << pat.producer;
	cout << "\nЖанр\t\t: " << pat.genre;
	cout << "\nГод\t\t: " << pat.year;
	cout << "\nРейтинг\t\t: " << pat.rating;
	cout << "\nЦена\t\t: " << pat.price << "\n";
	cout << "\n";
}

//Поиск по названию 
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

//Поиск по жанру 
void GenreSearch(Film film, char user[])
{

	if (strstr(film.genre, user) != NULL)
	{
		cout << film.movie << " ";

	}

}

//Поиск по режисеру
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

	cout << "\t\tАссортимент видеомагазина" << "\n";
	const int length = 10;
	int input = 0;

	Film videoStore[length]
	{
		{ "Зеленая миля", "Фрэнк Дарабонт", "Драма", 1999, 9.1, 10.2 },
		{ "Побег из Шоушенка", "Фрэнк Дарабонт", "Драма", 1994, 8.9, 10.0 },
		{ "Список Шиндлера", "Стивен Спилберг", "Драма", 1993, 8.9, 10.0 },
		{ "Форрест Гамп", "Роберт Земекис", "Драма", 1994, 8.8, 9.8 },
		{ "Криминальное чтиво", "Квентин Тарантино", "Криминал", 1994, 8.7, 9.0 },
		{ "Интерстеллар", "Кристофер Нолан", "Фантастика", 2014, 8.7, 9.0 },
		{ "Начало", "Кристофер Нолан", "Фантастика", 2010, 8.6, 8.5 },
		{ "Гладиатор", "Ридли Скотт", "История", 2000, 8.6, 8.0 },
		{ "Достучаться до небес", "Томас Ян", "Драма", 1997, 8.6, 8.0 },
		{ "Матрица", "Лана Вачовски", "Фантастика", 1999, 8.5, 8.0 }
	};

	do
	{
		cout << "\t      Меню магазина" << "\n";
		cout << "\nПоиск по названию - [1]" << "\n";
		cout << "Поиск по жанру - [2]" << "\n";
		cout << "Поиск по продюссеру - [3]" << "\n";
		cout << "Показать весь список фильмов - [4]" << "\n";
		cout << "Выход - [5]" << "\n";
		cout << "Выбор: ";
		cin >> input;
		cout << "\n";

		switch (input)
		{
		case 1:
			char user1[50];
			cout << "Выберите название фильма: ";
			cin >> user1;

			if (NameSearch(videoStore, user1, length) == true)
			{
				cout << "(Фильм найден)\n" << "\n";
			}
			else cout << "(Фильм не найден)\n" << "\n";

		case 2:
			char user2[50];
			cout << "Введите жанр фильма: ";
			cin >> user2;
			for (int i = 0; i < length; i++)
			{
				GenreSearch(videoStore[i], user2);
			}
			cout << "\n";

		case 3:
			char user3[50];
			cout << "Введите продюссера фильма: ";
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