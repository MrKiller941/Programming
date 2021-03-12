#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
int GetN();
void NewMatr(double**& M, int n, int m);
void DelMatr(double**& M, int n, int m);
void PrintMatr(double** M, int n, int m, const char* namematr);
void PrintVect(double* x, int n, const char* namematr);
bool Metodtecminora(double**& M, int n, int m, double& Det);
void Reshuffle(double**& M, int n, int m, int k, double& Det);
bool Solve(double**& M, double* x, int n, int m, double& Det);
double det(double** M, int n, int m);
void Test(double**& M, int n, int m);
void Clone(double**& M, int n, int m, double** M1);
double check(double** M1, int n, int m, double* x);
bool Reverb(double** A, int n, int m, double& Det, double**& rev);
void Proverka(double** M1, double** M2, int n1, int m1, int n2, int m2);
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    double Det = 1;
    cout << "Введите размер матрицы: "; n = GetN();
    int m = n + 1;
    double** A;
    double** A1;
    double** rev;
    double* x = new double[n];

    NewMatr(A, n, m);
    Test(A, n, m);
    NewMatr(A1, n, m);
    Clone(A, n, m, A1);
    NewMatr(rev, n, n);
    PrintMatr(A, n, m, "A");
    if (Solve(A, x, n, m, Det))
    {
        PrintVect(x, n, "x");
        cout << "Епсилон(е) = " << check(A1, n, m, x) << endl << endl;
    }
    else cout << "Нет решений" << endl;

    cout << "определитель = " << Det * det(A, n, m) << endl;
    if (Reverb(A1, n, m, Det, rev))
    {
        PrintMatr(rev, n, n, "rev");
        Proverka(A1, rev, n, m - 1, n, n);
    }
    else cout << "Нет единственного решения" << endl;
    DelMatr(A, n, m);
    DelMatr(A1, n, m);
    DelMatr(rev, n, n);
    delete[] x;
    x = NULL;
    return 0;
}
int GetN()
{
    float n;
    do
    {
        cin >> n;
        if (n <= 0 || (n - (int)n))
            cout << "Ошибка, попробуйте еще раз" << endl;
    } while (n <= 0 || (n - (int)n));
    return n;
}
void NewMatr(double**& M, int n, int m)
{
    M = new double* [n];
    for (int i = 0; i < n; i++)
        M[i] = new double[m];
}
void DelMatr(double**& M, int n, int m)
{
    for (int i = 0; i < n; i++)
        delete[] M[i];
    delete[] M;
}
void PrintMatr(double** M, int n, int m, const char* namematr)
{
    cout << endl << " " << namematr << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << setw(15) << M[i][j];
        cout << endl;
    }
    cout << endl;
}
void PrintVect(double* x, int n, const char* namematr)
{
    cout << endl << " " << namematr << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << x[i];
        cout << endl;
    }
    cout << endl;
}
void Reshuffle(double**& M, int n, int m, int k, double& Det)
{
    for (int i = k + 1; i < n; i++)
    {
        if (M[i][k] != 0)
        {
            double temp;
            for (int i1 = 0; i1 < m; i1++)
            {
                temp = M[k][i1];
                M[k][i1] = M[i][i1];
                M[i][i1] = temp;
            }
            Det *= -1;
            break;
        }
    }
}
bool Metodtecminora(double**& M, int n, int m, double& Det)
{
    for (int i = 0; i < n; i++)
    {
        if (M[i][i] == 0) Reshuffle(M, n, m, i, Det);
        if (M[i][i] == 0) 
            return false;
        for (int i1 = i + 1; i1 < n; i1++)
            for (int i2 = i + 1; i2 < m; i2++)
                M[i1][i2] = M[i][i] * M[i1][i2] - M[i][i2] * M[i1][i];
        for (int j = i + 1; j < n; j++)
        {
            M[j][i] = 0;
        }
    }
    return true;
}
bool Solve(double**& M, double* x, int n, int m, double& Det)
{
    double res = 0;
    if (!Metodtecminora(M, n, m, Det)) return false;
    for (int i = n - 1; i >= 0; i--)
    {
        res = 0;
        for (int j = i + 1; j <= n - 1; j++)
            res = res - x[j] * M[i][j];
        res += M[i][n];
        x[i] = res / M[i][i];
    }
    return true;
}
double det(double** M, int n, int m)
{
    double det = 1;
    for (int i = 0; i < n; i++)
    {
        if (M[i][i] == 0) return 0;
        det *= M[i][i] / pow(M[i][i], n - 1 - i);
    }
    return det;
}
void Test(double**& M, int n, int m)
{
    int k;
    cout << "1) Матрица, которая берется из файла \n2) Матрица, заданная случайным образом\n3) Единичная матрица\n4) Нулевая или вырожденная матрица\n5) Матрица Гильберта\nВведите номер задания: "; cin >> k;
    switch (k)
    {
    case 1:
    {
        fstream A("lab2.txt", ios::in);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                A >> M[i][j];
        A.close();
        break;
    }
    case 2:
    {
        double a, b;
        srand(time(0));
        a = -10;
        b = 10;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                M[i][j] = a + ((double)rand() / RAND_MAX) * (b - a);
            }
        break;
    }
    case 3:
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (i == j) M[i][j] = 1;
                else M[i][j] = 0;
        for (int i = 0; i < n; i++)
            break;
    }
    case 4:
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                M[i][j] = 0;
        break;
    }
    case 5:
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                M[i][j] = 1. / (i + j + 1);
        break;
    }
    }
}
void Clone(double**& M, int n, int m, double** M1)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            M1[i][j] = M[i][j];
}
double check(double** M1, int n, int m, double* x)
{
    double epsilon = 0;
    double s;
    for (int i = 0; i < n; i++)
    {
        s = 0;
        for (int k = 0; k < m - 1; k++)
            s += M1[i][k] * x[k];
        if (fabs(M1[i][m - 1] - s) > epsilon) epsilon = fabs(M1[i][m - 1] - s);
    }
    return epsilon;
}
bool Reverb(double** M, int n, int m, double& Det, double**& rev)
{
    double* x = new double[n];
    bool metka = true;
    for (int i = 0; i < n; i++)
    {
        double** buff;
        NewMatr(buff, n, m);
        Clone(M, n, m, buff);
        for (int j = 0; j < n; j++)
        {
            if (i == j) buff[j][m - 1] = 1;
            else buff[j][m - 1] = 0;
        }
        if (!Solve(buff, x, n, m, Det)) metka = false;
        for (int j = 0; j < n; j++)
            rev[j][i] = x[j];
        DelMatr(buff, n, m);
    }
    delete[] x;
    x = NULL;
    return metka;
}

void Proverka(double** M1, double** M2, int n1, int m1, int n2, int m2)
{
    double** buff;
    NewMatr(buff, n1, m2);
    double S;
    if (m1 != n2)
    {
        cout << "Ошибка..." << endl;
        DelMatr(buff, n1, m2);
    }
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++)
        {
            S = 0;
            for (int k = 0; k < m1; k++)
                S += M1[i][k] * M2[k][j];
            buff[i][j] = S;
        }
    PrintMatr(buff, n1, m2, "proverka");
    DelMatr(buff, n1, m2);
}
