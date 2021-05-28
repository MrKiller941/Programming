#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Laptop
{
    string name;
    int price;
    int weight;
    double RAM;
    void Out();
};

struct DLList
{
    struct Node
    {
        Laptop data;     //информация об объекте
        Node* next;   //позиция следующего узла
        Node* prev;   //предыдущая позиция узла
    };

    Node* F = NULL;     //первый узел
    Node* L = NULL;     //последний узел
    Node* C = NULL;     //текущий узел
    int Count;        //кол-во узлов

    void Out();
    void Info();
    void Clear();

    bool MoveNext();
    bool MovePrev();
    bool MoveFirst();
    bool MoveLast();

    bool Init(Laptop);
    bool AddNext(Laptop);
    bool AddPrev(Laptop);
    bool AddFirst(Laptop);
    bool AddLast(Laptop);

    bool Del(Laptop&);
    bool DelNext(Laptop&);
    bool DelPrev(Laptop&);
    bool DelFirst(Laptop&);
    bool DelLast(Laptop&);
};

bool DLList::MoveNext()
{
    if (!F)       return false;
    if (!C) { C = F; return true; }
    if (!C->next) return false;
    C = C->next;
    return true;
}

bool DLList::MovePrev()
{
    if (!F)       return false;
    if (!C) { C = F; return true; }
    if (!C->prev) return false;
    C = C->prev;
    return true;
}
bool DLList::MoveFirst()
{
    if (!F) return false;
    C = F;
    return true;
}

bool DLList::MoveLast()
{
    if (!L) return false;
    C = L;
    return true;
}

bool DLList::Init(Laptop data)
{
    if (!F)
    {
        F = new Node;
        L = F;
        C = F;
        F->prev = NULL;
        F->next = NULL;
        F->data = data;
        Count = 1;
        return true;
    }
    else
        return false;
}

bool DLList::AddNext(Laptop data)
{
    if (!F) return Init(data);

    Node* temp = C->next;
    C->next = new Node;
    C->next->next = temp;
    C->next->prev = C;

    if (!temp)
        L = C->next;
    else
        temp->prev = C->next;

    C = C->next;
    C->data = data;
    Count++;
    return true;

}

bool DLList::AddPrev(Laptop data)
{
    if (!F) return Init(data);

    Node* temp = C->prev;
    C->prev = new Node;
    C->prev->next = C;
    C->prev->prev = temp;

    if (!temp)
        F = C->prev;
    else
        temp->next = C->prev;

    C = C->prev;
    C->data = data;
    Count++;
    return true;
}

bool DLList::AddFirst(Laptop data)
{
    if (MoveFirst())return AddPrev(data);
    else return false;
}

bool DLList::AddLast(Laptop data)
{
    if (MoveLast())return AddNext(data);
    else return false;
}

void DLList::Out()
{
    if (!F)
    {
        cout << "Список пуст" << endl;
        return;
    }

    Node* temp = F;
    cout << "List: " << endl << endl;
    do
    {
        temp->data.Out();
        temp = temp->next;
    } while (temp);
    cout << endl;
}

void DLList::Info()
{

    if (Count)
        cout << "Список узлов: "
        << Count << endl << endl;
    else
        cout << "Cписок пуст" << endl;
    if (C)
    {
        if (MoveFirst())
        {
            cout << "Текущие данные узла: ";
            C->data.Out();
        }
    }
}

bool DLList::DelFirst(Laptop& data)
{
    if (!F)      return false;
    if (C != F)    MoveFirst();

    Node* temp = C->next;
    data = C->data;

    if (temp) temp->prev = NULL;
    delete C;

    C = temp;
    F = temp;
    Count--;
    if (!temp) { L = NULL; return false; }
    return true;
}

bool DLList::DelLast(Laptop& data)
{
    if (!F)      return false;
    if (C != L)    MoveLast();

    Node* temp = C->prev;
    data = C->data;

    if (temp) temp->next = NULL;
    delete C;

    C = temp;
    L = temp;
    Count--;

    if (!temp) { F = NULL; return false; }
    return true;
}

bool DLList::Del(Laptop& data)
{
    if (!F) return false;
    if (!C) return false;

    if (C == F) return DelFirst(data);
    if (C == L) return DelLast(data);

    Node* temp = C->next;
    data = C->data;

    C->prev->next = C->next;
    C->next->prev = C->prev;

    delete C;
    C = temp;
    Count--;
    return true;
}

bool DLList::DelNext(Laptop& data)
{
    if (!F) return false;
    if (!C) return false;
    if (MoveNext()) return Del(data);
    return false;
}
bool DLList::DelPrev(Laptop& data)
{
    if (!F) return false;
    if (!C) return false;
    if (MovePrev()) return Del(data);
    return false;
}

void DLList::Clear()
{
    if (!MoveFirst())
    {
        cout << "Список пуст" << endl;
        return;
    }
    Laptop k;
    while (Del(k));
}

void Laptop::Out()
{
    cout << "Name: " << name << "\t\t" << "Price: " << price << "\t" << "Weight: " << weight << "\t" << "RAM: " << RAM
 << endl << endl;
}

bool GetFile(DLList&, Laptop&);
bool WriteFile(DLList&, Laptop&);
void GetLaptop(Laptop&);

int main()
{
    setlocale(LC_ALL, "Russian");
    Laptop Info;
    DLList DLList;
    GetFile(DLList, Info);
    DLList.Out();
    int num, key = 0, key1 = 0, key2 = 0;
    Laptop z;
    do
    {
        cout << "1) Добавить элемент" << endl
            << "2) Удалить элемент" << endl
            << "3) Очистить список" << endl
            << "4) Выгрузить из списка в файл" << endl
            << "5) Сортировка" << endl
            << "0) Выход" << endl;
        cout << endl << "Выберите действие: ";
        cin >> key;
        cout << endl;
        switch (key)
        {
        case 1:
            cout << "1) Добавить в начало" << endl
                << "2) Добавить в конец" << endl
                << "3) Добавить на катую позицию" << endl
                << "0) Назад" << endl;
            cout << endl << "Выберите действие: ";
            cin >> key1;
            cout << endl;
            switch (key1)
            {
            case 1:
                GetLaptop(Info);
                DLList.AddFirst(Info);
                DLList.Out();
                break;
            case 2:
                GetLaptop(Info);
                DLList.AddLast(Info);
                DLList.Out();
                break;
            case 3:
                cout << "Введите  позицию: ";
                cin >> num;
                GetLaptop(Info);
                if (num == 1)
                {
                    DLList.AddFirst(Info);
                    DLList.Out();
                    break;
                }
                else if (num == DLList.Count + 1)
                {
                    DLList.AddLast(Info);
                    DLList.Out();
                    break;
                }
                DLList.MoveFirst();
                for (int i = 1; i < num - 1; i++)
                {
                    DLList.MoveNext();
                }
                DLList.AddNext(Info);
                DLList.Out();
                break;
            default:
                if (key1 != 0)
                {
                    cout << "Нет такого действия !" << endl << endl;
                }
                break;
            }
            break;
        case 2:
            cout << "1) Удалить первый элемент" << endl
                << "2) Удалить последний элемент" << endl
                << "3) Удалить с катой позиции" << endl
                << "0) Назад" << endl;
            cout << endl << "Выберите действие: ";
            cin >> key2;
            cout << endl;
            switch (key2)
            {
            case 1:
                DLList.DelFirst(Info);
                DLList.Out();
                break;
            case 2:
                DLList.DelLast(Info);
                DLList.Out();
                break;
            case 3:
                cout << "Введите позицию: ";
                cin >> num;
                if (num == 1)
                {
                    DLList.DelFirst(Info);
                    DLList.Out();
                    break;
                }
                else if (num == DLList.Count)
                {
                    DLList.DelLast(Info);
                    DLList.Out();
                    break;
                }
                DLList.MoveFirst();
                for (int i = 1; i < num; i++)
                {
                    DLList.MoveNext();
                }
                DLList.Del(Info);
                DLList.Out();
                break;
            default:
                if (key2 != 0)
                {
                    cout << "Нет такого действия !" << endl << endl;
                }
                break;
            }
            break;
        case 3:
            DLList.Clear();
            DLList.Out();
            break;
        case 4:
            WriteFile(DLList, Info);
            break;
        case 5:
            for (int i = 0; i < DLList.Count - 1; i++)
            {
                DLList.MoveLast();
                for (int j = (DLList.Count - 1); j > 1; j--)
                {
                    if ((DLList.C->prev->data.weight) > (DLList.C->data.weight))
                    {
                    z = DLList.C->data;
                    DLList.C->data = DLList.C->prev->data;
                    DLList.C->prev->data = z;
                    }
                    DLList.MovePrev();
                }


            }
            DLList.Info();
            DLList.Out();
                break;
        default:
            if (key != 0)
            {
                cout << "Нет такого действия !" << endl << endl;
            }
            DLList.Clear();
            DLList.Out();
            break;
        }
    } while (key != 0);
}

bool GetFile(DLList& DLList, Laptop& Info)
{
    ifstream F("laptop.txt");
    if (!F)
    {
        cout << "Файл не найден" << endl;
        return false;
    }
    while (F >> Info.name >> Info.price >> Info.weight >> Info.RAM)
    {
        DLList.AddNext(Info);
    }
    F.close();
    return true;
}

bool WriteFile(DLList& DLList, Laptop& Info)
{
    ofstream F("laptop.txt");
    if (!F)
    {
        cout << "Файл не найден" << endl;
        return false;
    }
    DLList.MoveFirst();
    do
    {
        F << DLList.C->data.name << " " << DLList.C->data.price << " " << DLList.C->data.weight << " " << DLList.C->data.RAM << endl;
    } while (DLList.MoveNext());
    DLList.MoveFirst();
    F.close();
    return true;
}

void GetLaptop(Laptop& Info)
{
    cout << "Введите название ноутбука: ";
    cin >> Info.name;
    cout << endl;
    cout << "Введите стоимость ноутбука ";
    cin >> Info.price;
    cout << endl;
    cout << "Введите вес ноутбука: ";
    cin >> Info.weight;
    cout << endl;
    cout << "Введите количество оперативной памяти: ";
    cin >> Info.RAM;
    cout << endl;
}