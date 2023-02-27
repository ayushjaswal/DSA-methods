#include <iostream>
#include <stdlib.h>
using namespace std;

// structure for matrix
class Matrix
{
private:
    int *A;
    int n;

public:
    // row major method
    Matrix(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    void set(int i, int j, int x)
    {
        if (i >= j)
        {
            A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
        }
    }
    int get(int i, int j)
    {
        if (i >= j)
        {
            return A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
        }
        return 0;
    }
    void printMat()
    {
        int i, j;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {

                if (i >= j)
                {
                    cout << A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    int i, j, x, n;
    cout << "Enter Dimensions: ";
    cin >> n;
    Matrix m(n);
    cout << "Enter all the elements" << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> x;
            m.set(i, j, x);
        }
    }
    cout << endl;

    m.printMat();
    return 0;
}