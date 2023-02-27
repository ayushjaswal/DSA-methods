#include <iostream>
using namespace std;
// code for diagonal matrix!
// structure for a basic matrix containing array and size
class Matrix
{
private:
    int A[10];
    int n;

public:
    Matrix(int n)
    {
        this->n = n;
    }
    // setting numebrs on diagonal matrix
    void set(int i, int j, int x)
    {
        if (i == j)
        {
            A[i - 1] = x;
        }
    }
    // geting any number for the matrix
    int get(int i, int j)
    {
        if (i == j)
        {
            return A[i - 1];
        }
        return 0;
    }
    // displaying the matrix
    void display()
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            cout << "| ";
            for (j = 0; j < n; j++)
            {
                if (i == j)
                {
                    cout << A[i] << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << "| " << endl;
        }
    }
};

// The main function
int main()
{
    Matrix m(4);

    m.set(1, 1, 56);
    m.set(2, 2, 12);
    m.set(3, 3, 23);
    m.set(4, 4, 34);

    m.display();

    cout << "Value at (1, 1): " << m.get(1, 1) << endl;
    cout << "Value at (2, 2): " << m.get(2, 2) << endl;
    cout << "Value at (3, 3): " << m.get(3, 3) << endl;
    cout << "Value at (4, 4): " << m.get(4, 4) << endl;

    return 0;
}