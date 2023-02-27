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
    // Column major method
    Matrix(int n){
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int x)
    {
        if (i <= j)
        {
            A[(j * (j - 1) / 2) + (i - 1)] = x;
        }
    }
    int get(int i, int j)
    {
        if (i <= j)
        {
            return A[(j * (j - 1) / 2) + (i - 1)];
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

                if (i <= j)
                {
                    cout << A[(j * (j - 1) / 2) + (i - 1)] << " ";
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
    int i, j, n, x;
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