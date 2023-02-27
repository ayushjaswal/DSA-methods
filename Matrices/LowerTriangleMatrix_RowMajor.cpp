#include <iostream>
#include <stdlib.h>
using namespace std;

// structure for matrix
struct Matrix
{
    int *A;
    int n;
};
// row major method
void set(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->A[i * (i - 1) / 2 + j - 1] = x;
    }
}
int get(struct Matrix m, int i, int j)
{
    if (i >= j)
    {
        return m.A[i * (i - 1) / 2 + j - 1];
    }
    return 0;
}
void printMat(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {

            if (i >= j)
            {
                cout << m.A[i * (i - 1) / 2 + j - 1] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
int main()
{
    Matrix m;
    int i, j, x;
    cout << "Enter Dimensions: ";
    cin >> m.n;
    m.A = (int *)malloc(m.n * (m.n - 1) / 2 * sizeof(int));
    cout << "Enter all the elements" << endl;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {   
            cin >> x;
            set(&m, i, j, x);
        }
    }
    cout << endl;

    printMat(m);
    return 0;
}