#include <iostream>
#include <fstream>
#include <queue> 
#include <iomanip>
#include <string>
using namespace std;
int** read_matrix(string, int&, int&); // чтение матрицы
void delete_matrix(int**&, int);
int* dijkstra(int**, int, int); // алгоритм дейкстра
void  dijkstra_paths(int**, int, int, int, int*, queue <int>&); // маршрут по точкам( от одной вершины до другой)
int main()
{
    setlocale (LC_ALL, "Ru");
    ofstream out;
    out.open("result.txt");
    int n, m; // строки и столбцы матрицы
    queue <int> paths;
    int** A = read_matrix("matrix.txt", n, m);
    if (A == NULL | n != m)
    {
        cout << "Произошла ошибка, попробуйте еще раз...";
        out << "Произошла ошибка, попробуйте еще раз...";
        return 0;
    }
    int s;
    cout << " Введите расстояние, начиная с единицы: "; 
    cin >> s;
    s--;
    int* distance = dijkstra(A, n, s);
    for (int i = 0; i < n; i++)
    {
        cout << "Расстояние от вершины " << s + 1 << " до вершины " << i + 1 << " = " << distance[i] << endl;
        out << "Расстояние от вершины " << s + 1 << " до вершины " << i + 1 << " = " << distance[i] << endl;
    }
    int e;
    cout << "Введите номер последней  вершины, для которой вы желаете  построить маршрут: "; 
    cin >> e;
    e--;
    dijkstra_paths(A, n, s, e, distance, paths);
    cout << "Вывод кратчайшего пути: " << e;
    out << "Вывод кратчайшего пути: " << e;
    while (!paths.empty()) 
    {
        cout << paths.front() << " <- "; // конечная вершина
        out << paths.front() << " <- ";
        paths.pop();
    }
    out.close();
    delete_matrix(A, n);
    delete[] distance;
    return 0;
}
int** read_matrix(string file_name, int& n, int& m)
{
    ifstream in(file_name);
    if (in.is_open())
    {
        int count = 0;
        int y;
        while (!in.eof())
        {
            in >> y;
            count++;
        }
        in.seekg(0, ios::beg);
        in.clear();
        int count_space = 0;
        char symbol;
        while (!in.eof())
        {
            in.get(symbol); // символ
            if (symbol == ' ') count_space++;
            if (symbol == '\n') break;
        }
        in.seekg(0, ios::beg);
        in.clear();
        n = count / (count_space + 1);
        m = count_space + 1;
        int** x;
        x = new int* [n];
        for (int i = 0; i < n; i++) x[i] = new int[m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                in >> x[i][j];
            }
        }
        in.close();
        return x;
    }
    in.close();
    return NULL;
}
void delete_matrix(int**& x, int n)
{
    for (int i = 0; i < n; i++) delete[] x[i];
    delete[] x;
}
int* dijkstra(int** A, int n, int s)
{
    const int infinum = INT_MAX;
    int* distance = new int[n]; // расстояние
    bool* visited = new bool[n]; // посещенные вершины
    int index, q;
    for (int i = 0; i < n; i++)
    {
        distance[i] = infinum; // расстояние
        visited[i] = false; //visited- посещенные вершины 
    }
    distance[s] = 0; // расстояние
    for (int count = 0; count < n - 1; count++)
    {
        int minimum = infinum;
        for (int i = 0; i < n; i++)
            if (!visited[i] && distance[i] <= minimum)
            {
                minimum = distance[i];
                index = i;
            }
        q = index;
        visited[q] = true;
        for (int i = 0; i < n; i++)
            if (!visited[i] && A[q][i] && distance[q] != infinum && distance[q] + A[q][i] < distance[i]) distance[i] = distance[q] + A[q][i];
    }
    delete[] visited;
    return distance;
}
void  dijkstra_paths(int** A, int n, int s, int e, int* distance, queue <int>& paths)
{
    paths.push(e + 1);
    int weight = distance[e]; // вес расстояния вершины
    while (e != s)
    {
        for (int i = 0; i < n; i++)
            if (A[i][e] != 0)
            {
                int y = weight - A[i][e];
                if (y == distance[i])
                {
                    weight = y;
                    e = i;
                    paths.push(i + 1);
                }
            }
    }
}