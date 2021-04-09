#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct magazine
{
    string Name;
    int Weight;
    int Year;
    int Pages;
};
struct MyQueue
{
    struct Node
    {
        magazine data;
        Node* prev;
    };
    Node* Top = NULL;
    int Count = 0;
    bool Push(magazine);
    bool Pop(magazine&);
    void Info();
};
bool MyQueue::Push(magazine dt)
{
    if (!Top)
    {
        Top = new Node;
        Top->prev = NULL;
        Count = 1;
    }
    else
    {
        Node* temp;
        temp = new Node;
        temp->prev = Top;
        Top = temp;
        Count++;
    }
    Top->data = dt;
    return true;
}
bool MyQueue::Pop(magazine& dt)
{
    if (!Top) return false;
    Node* temp = Top->prev;
    dt = Top->data;
    delete Top;
    Top = temp;
    Count--;
    return true;
}
void MyQueue::Info()
{
    if (!Top) cout << "Stack is empty" << endl;
    else
    {
        cout << endl << "Stack info: " << endl;
        cout << "\tStack size = " << Count << endl;
        cout << "\tTop Name = " << Top->data.Name << endl;
        cout << "\tTop Weight = " << Top->data.Weight << endl;
        cout << "\tTop Year = " << Top->data.Year << endl;
        cout << "\tTop Pages = " << Top->data.Pages << endl << endl;
    }
}
void print(MyQueue& S, MyQueue& V)
{
    magazine dt;
    while (S.Count)
    {
        S.Pop(dt);
        cout << "\Name = " << dt.Name << endl;
        cout << "\Weight = " << dt.Weight << endl;
        cout << "\tYear = " << dt.Year << endl;
        cout << "\tPages = " << dt.Pages << endl << endl;
        V.Push(dt);
    }
    while (V.Count)
    {
        V.Pop(dt);
        S.Push(dt);
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    MyQueue S;
    MyQueue V;
    magazine dt;
    ifstream file("magazine.txt");
    string line;
    while (getline(file, line))
    {
        istringstream line_F(line);
        line_F >> dt.Name >> dt.Weight >> dt.Year >> dt.Pages;
        S.Push(dt);
    }
    file.close();
    int m = 1;
    while (m)
    {
        S.Info();
        cout << "1) Добавить товар в корзину" << endl;
        cout << "2) Вытащить товар из корзины" << endl;
        cout << "3) Очистить корзину" << endl;
        cout << "4) Показать содержимое корзины(продукты)" << endl;
        cout << "0) Выход" << endl;
        cin >> m;
        switch (m)
        {
        case 1:
        {
            system("cls");
            cout << "Характеристика журналов:" << endl;
            cout << "Name = "; cin >> dt.Name;
            cout << "Weight = "; cin >> dt.Weight;
            cout << "Year = "; cin >> dt.Year;
            cout << "Pages = "; cin >> dt.Pages;
            S.Push(dt);
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            magazine dt_x;
            bool metka = false;
            cout << "Характеристика журналов:" << endl;
            cout << "Name = "; cin >> dt_x.Name;
            cout << "Weight = "; cin >> dt_x.Weight;
            cout << "Year = "; cin >> dt_x.Year;
            cout << "Pages = "; cin >> dt_x.Pages;
            while (S.Count)
            {
                S.Pop(dt);
                if (dt.Name != dt_x.Name || dt.Weight != dt_x.Weight || dt.Year != dt_x.Year || dt.Pages != dt_x.Pages)
                {
                    V.Push(dt);
                }
                else
                {
                    metka = true;
                    break;
                }
            }
            if (!metka) cout << "Продукт не найден" << endl;
            while (V.Count)
            {
                V.Pop(dt);
                S.Push(dt);
            }
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            while (S.Count)
            {
                S.Pop(dt);
            }
            break;
        }
        case 4:
        {
            system("cls");
            print(S, V);
            system("pause");
            system("cls");
            break;
        }
        }
    }
}