﻿#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct laptop
{
    string name;
    int price;
    int weight;
    double RAM;
    void Out();
};

void laptop::Out() {
    cout << name << " ";
    cout << price << " ";
    cout << weight << " ";
    cout << RAM << " ";
    cout << endl;
}

struct Tree {
    laptop data;
    Tree* left;
    Tree* right;
};

int GetTreeSize(Tree* T);
void Add(Tree*& T, int data, bool flag);
void PrintLRR(Tree* T);
Tree* Search(Tree*& T, int data);
void Delete(Tree*& T);
void readFile();
void SortTree(Tree*& T, bool flag);
void elDbl(Tree* T);
void elStr(Tree* T);
void Menu();



int GetTreeSize(Tree* T) {
    if (!T) return 0;
    if (!T->left && !T->right) return 1;
    int left = 0, right = 0;
    if (T->left) left = GetTreeSize(T->left);
    if (T->right) right = GetTreeSize(T->right);
    return left + right + 1;
}

void Add(Tree*& T, laptop data, bool flag) {
    if (!T) {
        T = new Tree;
        T->data = data;
        T->left = NULL;
        T->right = NULL;
        return;
    }
    if (flag) {
        if (data.price < T->data.price) Add(T->left, data, 1);
        else Add(T->right, data, 1);
        return;
    }
    else {
        if (data.name < T->data.name) Add(T->left, data, 0);
        else Add(T->right, data, 0);
        return;
    }
}

void PrintLRR(Tree* T) {
    if (!T) return;
    PrintLRR(T->left);
    T->data.Out();
    PrintLRR(T->right);
}

Tree* SearchDbl(Tree*& T, double data) {
    if (!T) return NULL;
    if (data > T->data.price) {
        T->data.Out();
    }
    SearchDbl(T->left, data);
    SearchDbl(T->right, data);
    return T;
}

Tree* SearchStr(Tree*& T, string data) {
    if (!T) return NULL;
    if (data[0] == T->data.name[0]) {
        T->data.Out();
    }
    SearchStr(T->left, data);
    SearchStr(T->right, data);
    return T;
}

void Delete(Tree*& T) {
    if (T) {
        if (T->left) Delete(T->left);
        if (T->right) Delete(T->right);
        delete T;
        T = NULL;
    }
    else {
        cout << "Дерево пустое" << endl;
    }
}

void readFile(Tree*& T) {
    laptop w;
    system("cls");
    fstream f_in("laptop.txt", ios::in);
    if (!f_in) {
        cout << "Файл не найден" << endl;
        return;
    }
    while (f_in >> w.name >> w.weight >> w.price >> w.RAM) {
        Add(T, w, 1);
    }
    f_in.close();
}

void SortTree(Tree*& T, bool flag) {
    Delete(T);
    laptop w;
    system("cls");
    fstream f_in("laptop.txt", ios::in);
    if (!f_in) {
        cout << "Файл не найден" << endl;
        return;
    }
    while (f_in >> w.name >> w.weight >> w.price >> w.RAM) {
        if (flag) Add(T, w, 1);
        else Add(T, w, 0);
    }
    f_in.close();
    system("cls");
    PrintLRR(T);
    system("pause");
}

void elDbl(Tree* T) {
    int price;
    system("cls");
    cout << "Введите : ";
    cin >> price;
    SearchDbl(T,price);
    system("pause");
}

void elStr(Tree* T) {
    string name;
    system("cls");
    cout << "Введите название: ";
    cin >> name;
    SearchStr(T, name);
    system("pause");
}

void Menu() {
    Tree* T = NULL;
    readFile(T);
    laptop w;
    int key;
    do {
        system("cls");
        cout << ".............................................." << endl;
        cout << "- 1) Сортировка по названиям фирм ноутбуков               " << endl;
        cout << "- 2) Сортировка по цене  ноутбука                     " << endl;
        cout << "- 3) Выбрать элемент по имени                 " << endl;
        cout << "- 4) Выбрать элемент,который ниже указанной cтоимости ноутбука " << endl;
        cout << "- 0) Выход                                    -" << endl;
        cout << "................................................" << endl;
        cout << "" << endl;
        cout << "Количество элементов в дереве:  " << GetTreeSize(T) << endl;
        cout << "Введите:  ";

        cin >> key;

        switch (key) {
        case 1: SortTree(T, 0); break;
        case 2: SortTree(T, 1); break;
        case 3: elStr(T); break;
        case 4: elDbl(T); break;
        case 0: Delete(T); break;
        default:  system("cls");

            system("pause");
        }
    } while (key);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Menu();
}