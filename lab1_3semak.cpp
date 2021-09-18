#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <sstream>
using namespace std;
struct datetime
{
    int second, minute, hour, day, month, year;
    void next_date(datetime*); // следующая дата
    void previous_date(datetime*); // предыдущая дата
    void print_date(datetime); //текущая дата
    void print_information(datetime*, int);// информация о дате
    void print_information_no_next_month(datetime*, int); // информация по дате следующего месяца
};
void get_date(datetime*, int, int, int, int, int, int);
bool proverka_day(int, int,int); // проверка даты
bool proverka_month(int, int); // проверка месяца
bool proverka_year(int, int); // проверка года
int get_count_lines(string);
string** read_file(string, int);
int main()
{
    setlocale(LC_ALL, "Russian");
    string path_file = "data.txt";
    int count_lines = get_count_lines(path_file);
    string** lines = read_file(path_file, count_lines);
    datetime* dates = new datetime[count_lines];

    for (int i = 0; i < count_lines; i++)
    {
        get_date(&dates[i], stoi(lines[i][0]), stoi(lines[i][1]), stoi(lines[i][2]), stoi(lines[i][3]), stoi(lines[i][4]), stoi(lines[i][5]));
    } // генератор объектов

    for (int i = 0; i < count_lines; i++)
    {
        dates[i].print_information(&dates[i], i + 1);
        // dates[i].print_information(&dates[i], i+1);
    }
    cout << "Вариант №3" << endl;
    cout << "Даты, которые не попадут на следующий месяц" << endl;
    for (int i = 0; i < count_lines; i++)
    {
        if (proverka_day(dates[i].month, dates[i].day + 1, dates[i].year))
            dates[i].print_information_no_next_month(&dates[i], i + 1);
    }



    for (int i = 0; i < count_lines; i++)
    {
        delete[] lines[i];
    }
    delete[] lines;

    return 0;
}

void get_date(datetime* date, int second, int minute, int hour, int day, int month, int year)
{
    if (second < 0 or second > 60)
    {
        cout << "Неверный формат секунд, автоматически выставляется значение 0" << endl;
        date->second = 0;
    }
    else
        date->second = second;

    if (minute < 0 or minute > 60)
    {
        cout << "Неверный формат минут, автоматически выставляется значение 0" << endl;
        date->minute = 0;
    }
    else
        date->minute = minute;

    if (hour < 0 or hour > 24)
    {
        cout << "Неверный формат часов, автоматически выставляется значение 0" << endl;
        date->hour = 0;
    }
    else
        date->hour = hour;

    if (day < 1 or day > 31)
    {
        cout << "Неверный формат дней, автоматически выставляется значение 1" << endl;
        date->day = 1;
    }
    else
        date->day = day;

    if (month < 0 or month > 12)
    {
        cout << "Неверный формат месяцев, автоматически выставляется значение 1" << endl;
        date->month = 1;
    }
    else
        date->month = month;

    if (year < 0)
    {
        cout << "Неверный формат года, автоматически выставляется значение 2000" << endl;
        date->year = 2000;
    }
    else
        date->year = year;
}

void datetime::print_date(datetime date)
{
    cout << "-.-.-..-..-.-.-.-.-.-." << endl;
    cout << "Текущие время и дата:" << endl;
    cout << "Секунда: " << date.second << endl;
    cout << "Минута: " << date.minute << endl;
    cout << "Час: " << date.hour << endl;
    cout << "День: " << date.day << endl;
    cout << "Месяц: " << date.month << endl;
    cout << "Год: " << date.year << endl;
    cout << "----------------------" << endl << endl;
}

void datetime::print_information(datetime* date, int n)
{
    cout << "№ " << n << "; Дата: " << date->day << "." << date->month << "." << date->year << ";\t";
    date->next_date(date);
    cout << "Следущая дата: " << date->day << "." << date->month << "." << date->year << ";\t";
    date->previous_date(date);
    date->previous_date(date);
    cout << "Предыдущая дата: " << date->day << "." << date->month << "." << date->year << endl;
    date->next_date(date);
}

void datetime::print_information_no_next_month(datetime* date, int n)
{
    cout << "№ " << n << "; Дата: " << date->day << "." << date->month << "." << date->year << ";\t";
    date->next_date(date);
    cout << "Следующая дата: " << date->day << "." << date->month << "." << date->year << endl;
    date->previous_date(date);
}

bool proverka_day(int month, int day, int year)
{
    int month_31day[7] = { 1, 3, 5, 7, 8, 10, 12 }; // в данных месяцах 31 день в месяце

    if (day < 1) // если значение дня меньше единицы, то выводим, как неверное значение
        return false;

    if (month == 2)
    {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {
            if (day > 29)
            {
                return false;
            }
        }
        else
        {
            if (day > 28)
            {
                return false;
            }
        }
    }

    for (int i = 0; i < 7; i++)
    {
        if (month == month_31day[i])
        {
            if (day > 31) // если значение дней больше 31, то выводим, как неверное значение
                return false;
        }
        else
            if (day > 32)
                return false;
    }
    return true;
}

bool proverka_month(int month)
{
    if (month > 12 or month < 1) // если кол-во месяцев больше 12 или месяцев меньше, то выводится, как неверное значение и верное
        return false;
    return true;
}

void datetime::next_date(datetime* date)
{
    if (proverka_day(date->month, date->day + 1,date->year ))
        date->day++;
    else
    {
        date->day = 1;

        if (proverka_month(date->month + 1))
        {
            date->month++;
        }
        else
        {
            date->month = 1;
            date->year++
;
        }
    }
}

void datetime::previous_date(datetime* date)
{
    int month_31day[7] = { 1, 3, 5, 7, 8, 10, 12 };


    if (proverka_day(date->month, date->day - 1, date->year))
    {
        date->day--;
    }
         else
    {
        if (date->month - 1 == 2)
        {
            if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) // проверка на високосный год
            {
                date->day = 29;
            }
            else date->day = 28;
        }
        else

        for (int i = 0; i < 7; i++)
        {
            if (date->month == 1)
                date->day = 31;
            else if (date->month -1 == month_31day[i])
                date->day = 31;
            else
                date->day = 30;
        }
        if (proverka_month(date->month - 1))
            date->month--;
        else
        {
            date->month = 12;
            date->year--;
        }
    }
}


int get_count_lines(string path_file)
{
    ifstream f(path_file);
    string s;
    int count = 0;
    while (getline(f, s))
    {
        count++;
    }

    return count;
}

string** read_file(string path_file, int count_lines) // чтение файла
{
    ifstream f(path_file);
    string line;

    string** lines = new string * [count_lines];
    
    for (int i = 0; i < count_lines; i++)
    {
        lines[i] = new string[6];
    }
    
    int j = 0;
    while (getline(f, line))
    {
        string buf;
        stringstream x;
        x << line;

        for (int i = 0; i < 6; i++)
        {
            x >> buf;
            lines[j][i] = buf;
        }
        j++;
    }


    f.close();
    return lines;
}





