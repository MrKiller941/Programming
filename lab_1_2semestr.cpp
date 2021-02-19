#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#define max_rand 10;
using namespace std;







void arr_ins(float n) {
    fstream f_out("arr.txt");
    for (float i = 0; i < n; i++) {
        f_out << rand() % max_rand;
    }
    f_out.close();
}

void arr_read(float* arr, float n) {
    fstream f_in("arr.txt");
    if (f_in) {
        for (int i = 0; i < n; i++) {
            f_in >> arr[i];
        }
        f_in.close();
    }
}

void arr_prfloat(float* arr, float n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

}

void push_back_arr(float*& arr, float& n) {
    int k;
    cout << "Какое количество элементов  добавить в конец массива: ";
    cin >> k;
    float* newArray = new float[n + k];
    for (int i = 0; i < n; i++)
    {
        newArray[i] = arr[i];
    }
    cout << "Введите данные элементы, " << k << " катых: " << endl;
    for (int i = n; i < (n + k); i++)
    {
        cin >> newArray[i];
    }
    delete[]arr;
    arr = newArray;
    n += k;
}
void push_front_arr(float*& arr, float& n)
{
    int k;
    cout << "Сколько элементов массива добавить в начало массива: ";
    cin >> k;
    float* newArray = new float[n + k];
    for (int i = 0; i < n; i++)
    {
        newArray[i + k] = arr[i];
    }
    cout << "Введите добавляемые элементы, " << k << " катых: " << endl;
    for (int i = 0; i < k; i++)
    {
        cin >> newArray[i];
    }
    delete[]arr;
    arr = newArray;
    n += k;
}

void delete_back_arr(float*& arr, float& n)
{
    int k;
    cout << "Сколько элементов массива удалить в конце массива: ";
    cin >> k;
    float* newArray = new float[n - k];
    for (int i = 0; i < (n - k); i++)
    {
        newArray[i] = arr[i];
    }
    delete[]arr;
    arr = newArray;
    n -= k;

}


void delete_front_arr(float*& arr, float& n)
{
    int k;
    cout << "Количество элементов для удаления в начале массива: ";
    cin >> k;
    float* newArray = new float[n - k];
    for (int i = 0; i < (n - k); i++)
    {
        newArray[i] = arr[i + k];
    }
    delete[]arr;
    arr = newArray;
    n -= k;

}

void push_k_arr(float*& arr, float& n)
{
    int k;
    cout << "На какое место (всего мест " << n << ") массива добавить элемент: ";
    cin >> k;
    float* newArray = new float[n + 1];
    for (int i = 0; i < k; i++)
    {
        newArray[i] = arr[i];
    }
    cout << "Введите элемент для добавления: ";
    cin >> newArray[k - 1];
    for (int i = k; i < (n + 1); i++)
    {
        newArray[i] = arr[i - 1];
    }
    delete[]arr;
    arr = newArray;
    n++;
}

void delete_k_arr(float*& arr, float& n)
{
    float k;
    cout << "Какой элемент (всего элементов " << n << " кштук) массива удалить (введите номер от 1, до " << n << "): ";
    cin >> k;
    float* newArray = new float[n - 1];
    for (int i = 0; i < k; i++)
    {
        newArray[i] = arr[i];
    }
    for (int i = (k - 1); i < (n - 1); i++)
    {
        newArray[i] = arr[i + 1];
    }
    delete[]arr;
    arr = newArray;
    n--;
}

void push_value_arr(float*& arr, float& n)
{
    float k, result = 0;
    int buf;
    cout << "После какого какого встреченного в массиве значения добавить элемент: ";
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k) { result = 1; buf = i; break; }
    }
    if (result == 1) {
        float* newArray = new float[n + 1];
        for (int i = 0; i < (buf + 1); i++)
        {
            newArray[i] = arr[i];
        }
        cout << "Введите добавляемый элемент массива : ";
        cin >> newArray[buf + 1];
        for (int i = buf + 2; i < (n + 1); i++)
        {
            newArray[i] = arr[i - 1];
        }
        delete[]arr;
        arr = newArray;
        n++;
    }
    else
    {
        cout << "Появилась ошибка (Элемент с таким значением не найден, повторите...)" << endl;
    }

}

void delete_value_arr(float*& arr, float& n)
{
    float k, result = 0, buf = 0;
    int buf2 = 0;
    cout << "Элементы с каким значением понадобится удалить: ";
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k) { result = 1; buf++; }
    }
    if (result == 1)
    {
        float* newArray = new float[n - buf];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != k)
            {
                newArray[i - buf2] = arr[i];
            }
            else
            {
                buf2++;
                continue;
            }
        }
        delete[]arr;
        arr = newArray;
        n -= buf;
    }
    else
    {
        cout << "Появилась ошибка (Элемент с таким значением не найден, повторите...)" << endl;
    }
}

int main()
{
    //srand(time(NULL));
    float N;
    float size_arr;
    setlocale(0, "");
    cout << "Введите размер массива: ";
    cin >> size_arr;
    //if (size_arr - (float)size_arr!=0) { cout << "Введите целое число" << endl;}

    float* arr = new float[size_arr];
    arr_ins(size_arr);
    arr_read(arr, size_arr);
    arr_prfloat(arr, size_arr);
    cout << endl;

    do {
        cout << "\n\nВыберите номер задания, который вам требуется:\n1) добавить элемент в конец массива\n2) добавить элемент в начало массива\n3) добавить элемент на катую позицию в массиве";
        cout << "\n4) удалить последний элемент массива\n5) удалить первый элемент массива\n6) удалить катый элемент массива\n7) добавить элемент массива после первого встреченного элемента с заданным значением, который нам требутся.\n8) удалить все элементы массива с заданным значением\
            \nЗадание, которое вам требуется для удачного выполнения: "; cin >> N; cout << "\n";

        if (N == 1) push_back_arr(arr, size_arr);
        if (N == 2) push_front_arr(arr, size_arr);
        if (N == 3) push_k_arr(arr, size_arr);
        if (N == 4) delete_back_arr(arr, size_arr);
        if (N == 5) delete_front_arr(arr, size_arr);
        if (N == 6) delete_k_arr(arr, size_arr);
        if (N == 7) push_value_arr(arr, size_arr);
        if (N == 8) delete_value_arr(arr, size_arr);




        cout << "\n";
        arr_prfloat(arr, size_arr);
    } while (N != 0);




    arr_prfloat(arr, size_arr);
    delete[] arr;
    arr = NULL;
    return 0;

}


