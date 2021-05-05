#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Pie
{
    string name;
    double weight;
    double kkal;
    int price;
};

struct Queue {
    struct Node { int n; char* data; Node* next; };
    Node* First = NULL;
    int count = 0;
    bool Push(char*, int);
    bool Pop(char*&, int&);
    void Info();
};

bool Queue::Push(char* data, int n) {
    if (!First) {
        First = new Node;
        First->next = NULL;
        First->n = n;
        First->data = new char[n];
        for (int i = 0; i < n; i++) {
            First->data[i] = data[i];
        }
        count = 1;
    }
    else {
        Node* temp;
        temp = First;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new Node;
        temp->next->data = new char[n];
        temp->next->next = NULL;
        temp->next->n = n;
        for (int i = 0; i < n; i++) {
            temp->next->data[i] = data[i];
        }
        count++;
    }
    return true;
}

bool Queue::Pop(char*& data, int& n) {
    if (!First) return false;
    Node* temp = First->next;
    n = First->n;
    data = new char[n];
    for (int i = 0; i < n; i++) {
        data[i] = First->data[i];
    }
    delete First->data;
    delete First;
    First = temp;
    count--;
    return true;
}

void Queue::Info() {
    if (!First) cout << "---> Очередь с товарами пуста" << endl;
    else {
        cout << "Количество товаров в очереди = " << count << endl;
    }
}

void Menu();
void ClearBinaryFile();
void WriteBinaryFile(char*, int);
bool ReadBinaryFile(Queue&);
void InputBinaryFile();
void AddProduct(Queue&);
void PullOut(Queue&);
void Clear(Queue&);
void ClearExit(Queue&);
void GetSeria(char*&, int&, Pie);
void GetDeSeria(char*, int, Pie&);
void ShowProduct(Pie);

void GetSeria(char*& data, int& n, Pie a) {
    size_t s1 = a.name.size();
    int n0 = sizeof(size_t);
    int n1 = s1;
    int n2 = sizeof(double);
    int n3 = n2;
    int n4 = sizeof(int);
    n = n0 + n1 + n2 + n3 + n4;
    data = new char[n];

    char* d0 = reinterpret_cast<char*>(&s1);
    char* d1 = const_cast<char*>(a.name.c_str());
    char* d2 = reinterpret_cast<char*>(&a.weight);
    char* d3 = reinterpret_cast<char*>(&a.kkal);
    char* d4 = reinterpret_cast<char*>(&a.price);

    for (int i = 0; i < n0; i++) data[i] = d0[i];
    for (int i = 0; i < n1; i++) data[i + n0] = d1[i];
    for (int i = 0; i < n2; i++) data[i + n0 + n1] = d2[i];
    for (int i = 0; i < n3; i++) data[i + n0 + n1 + n2] = d3[i];
    for (int i = 0; i < n4; i++) data[i + n0 + n1 + n2 + n3] = d4[i];
}

void GetDeSeria(char* data, int n, Pie& a) {
    int n0, n1, n2, n3, n4;
    n0 = sizeof(size_t);
    n2 = sizeof(double);
    n3 = n2;
    n4 = sizeof(int);
    size_t p = *reinterpret_cast<size_t*>(data);
    n1 = p;
    string ss1(data + n0, p);

    a.name = ss1;
    a.weight = *reinterpret_cast<double*>(data + n0 + n1);
    a.kkal = *reinterpret_cast<double*>(data + n0 + n1 + n2);
    a.price = *reinterpret_cast<int*>(data + n0 + n1 + n2 + n3);
}

void Menu() {
    Queue q;
    int m;
    ReadBinaryFile(q);
    do {
        system("cls");
        cout << "------------" << endl;
        cout << "1. Добавление элемента в очередь" << endl;
        cout << "2. Вытащить элемент" << endl;
        cout << "3. Очистить очередь" << endl;
        cout << "0. Выход" << endl;
        cout << "------------" << endl;
        q.Info();
        cout << "Enter: ";
        cin >> m;

        switch (m)
        {
        case 1: AddProduct(q); break;
        case 2: PullOut(q); break;
        case 3: Clear(q); break;
        case 0: ClearExit(q); break;
        default:  system("cls");
            cout << "Ошибка..." << endl;
            system("pause");
        }
    } while (m);
}

void ClearBinaryFile() {
    fstream f_out;
    f_out.open("out.dat", ios::out | ios::binary);
    f_out.close();
}

void WriteBinaryFile(char* data, int n) {
    fstream f_out;
    f_out.open("out.dat", ios::app | ios::binary);
    f_out.write((char*)&n, sizeof(int));
    f_out.write(data, n);
    f_out.close();
}

bool ReadBinaryFile(Queue& q) {
    system("cls");
    fstream f_in("out.dat", ios::in | ios::binary);
    if (!f_in) {
        cout << "---> Отсутствует бинарный файл" << endl;
        return false;
    }
    int n;
    Pie p;
    while (!f_in.eof()) {
        if (f_in.read((char*)&n, sizeof(int))) {
            char* data = new char[n];
            f_in.read(data, n);
            q.Push(data, n);
            GetDeSeria(data, n, p);
            ShowProduct(p);
            delete[] data;
            data = NULL;
        }
    }
    f_in.close();
    system("pause");
    return true;
}

void InputBinaryFile() {
    Pie p[] = {
        {"Ponchik", 10, 15, 50},
        {"Papperoni", 15, 20, 100}
    };
    char* data;
    int ssize, m = 2;
    ClearBinaryFile();
    for (int i = 0; i < m; i++) {
        GetSeria(data, ssize, p[i]);
        WriteBinaryFile(data, ssize);
    }
    delete[] data;
    data = NULL;
}

void AddProduct(Queue& q) {
    Pie p;
    char* data;
    int ssize;
    system("cls");
    cout << "Введите характеристику продуктов" << endl;
    cin >> p.name >> p.weight >> p.kkal >> p.price;
    while (p.weight <= 0 || p.kkal < 0 || p.price < 0) {
        cout << "---> Данные с ошибкой, которых не имеется в очереди... <--- " << endl;
        cout << "Weight: ";
        cin >> p.weight;
        cout << "Kkal: ";
        cin >> p.kkal;
        cout << "Price: ";
        cin >> p.price;
    }
    GetSeria(data, ssize, p);
    q.Push(data, ssize);
    delete[] data;
    data = NULL;
}

void PullOut(Queue& q) {
    Pie p;
    string name;
    double weight, kkal;
    int ssize, price, count = q.count;
    system("cls");
    if (q.count == 0) {
        cout << "В очереди не имеется товаров" << endl;
        system("pause");
        return;
    }
    cout << "Введите характеристику продуктов: ";
    cin >> name >> weight >> kkal >> price;
    while (weight <= 0 || kkal < 0 || price < 0) {
        cout << "---> Ошибка с данными веса, ккал, цены <--- " << endl;
        cout << "Weight: ";
        cin >> weight;
        cout << "Kkal: ";
        cin >> kkal;
        cout << "Price: ";
        cin >> price;
    }

    for (int i = 0; i < count; i++) {
        char* data;
        q.Pop(data, ssize);
        GetDeSeria(data, ssize, p);
        if ((name == p.name) && (weight == p.weight) && (kkal == p.kkal) && (price == p.price)) {
            cout << "Товар был успешно найден" << endl;
            delete[] data;
            data = NULL;
            system("pause");
            return;
        }
        else {
            q.Push(data, ssize);
            delete[] data;
            data = NULL;
        }
    }
    cout << "Нет продукта в очерди.." << endl;
    system("pause");
}

void Clear(Queue& q) {
    if (q.count == 0) {
        return;
    }
    Pie p;
    int ssize, i = 1;
    system("cls");
    while (q.count) {
        char* data = new char[q.First->n];
        ssize = q.First->n;
        q.Pop(data, ssize);
        GetDeSeria(data, ssize, p);
        cout << i << ". ";
        ShowProduct(p);
        i++;
        delete[] data;
        data = NULL;
    }
    system("pause");
}

void ClearExit(Queue& q) {
    Pie p;
    if (q.count == 0) {
        return;
    }
    int ssize;
    while (q.count) {
        char* data = new char[q.First->n];
        ssize = q.First->n;
        q.Pop(data, ssize);
        delete[] data;
        data = NULL;
    }
}

void ShowProduct(Pie p) {
    cout << "\tНазвание продукта: " << p.name
        << "\tВес продукта: " << p.weight
        << "\tКоличество ккал в продукте: " << p.kkal
        << "\tЦена продукта: " << p.price << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    InputBinaryFile();
    Menu();
    return 0;
}
