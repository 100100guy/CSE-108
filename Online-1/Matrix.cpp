#include <iostream>
using namespace std;
class Matrix
{
    int row, col;

    int **arr = NULL;

public:
    Matrix(int r, int c);
    void set(int r, int c, int val);
    int get(int r, int c);
    void add(int n);
    int add();
    void print();
    ~Matrix();
};

Matrix::Matrix(int r, int c)
{
    row = r;
    col = c;
    arr = (int **)malloc(row * sizeof(int));
    for (int i = 0; i < row; i++)
    {
        arr[i] = (int *)malloc(col * sizeof(int));
    }
}
Matrix::~Matrix()
{
    for (int i = 0; i < row; i++)
        free(arr[i]);

    free(arr);
}
void Matrix::set(int r, int c, int val)
{
    arr[r][c] = val;
}
int Matrix::get(int r, int c)
{
    return arr[r][c];
}
void Matrix::add(int n)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] += n;
        }
    }
}
int Matrix::add()
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}
void Matrix::print()
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Hello World" << '\n';
    Matrix m(3, 3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m.set(i, j, i + j);

    m.print();
    cout << m.get(0, 0) << '\n';
    m.set(0, 0, 100);
    cout << m.get(0, 0) << '\n';
    m.add(100);
    m.print();
    cout << m.add() << '\n';

    return 0;
}
