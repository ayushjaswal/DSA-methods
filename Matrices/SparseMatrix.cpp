#include <iostream>
using namespace std;

class SparseMatrix
{
private:
    struct element
    {
        int i;
        int j;
        int x;
    };
    int m;
    int n;
    int num;
    element *e;

public:
    void create()
    {
        int p;
        cout << "Enter Dimensions: ";
        cin >> m;
        cin >> n;
        cout << endl;
        cout << "Enter number of non-zero elements: ";
        cin >> num;
        e = new element[num];
        cout << "Enter all the element: " << endl;
        for (p = 0; p < num; p++)
        {
            cin >> e[p].i;
            cin >> e[p].j;
            cin >> e[p].x;
        }
    }

    void print()
    {
        int i, j, k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == e[k].i && j == e[k].j)
                {
                    cout << e[k++].x << " ";
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
    SparseMatrix s;
    s.create();
    s.print();
    return 0;
}