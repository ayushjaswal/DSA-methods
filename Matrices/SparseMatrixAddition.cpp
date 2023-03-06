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

public:
    element *e;
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
    void sumSparse(SparseMatrix s)
    {
        SparseMatrix *sum;
        sum = new SparseMatrix[num + s.num];
        sum->e = new element[num + s.num];
        int i = 0, j = 0, k = 0;
        while (i < num && j < s.num)
        {
            if (e[i].i < s.e[j].i)
            {
                sum->e[k++] = e[i++];
            }
            else if (e[i].i > s.e[j].i)
            {
                sum->e[k++] = s.e[j++];
            }
            else
            {
                if (e[i].j < s.e[j].j)
                {
                    sum->e[k] = e[i];
                }
                else if (e[i].j > s.e[j].j)
                {
                    sum->e[k] = s.e[j];
                }
                else
                {
                    sum->e[k] = s.e[i];
                    sum->e[k++].x += e[i++].x;
                }
            }
        }
        for (; i < num; i++)
        {
            sum->e[k++] = e[i];
        }
        for (; j < num; j++)
        {
            sum->e[k++] = s.e[j];
        }
        sum->m = m;
        sum->n = n;
        sum->num = k;
        sum->print();
    }
};

int main()
{
    SparseMatrix s1, s2;
    s1.create();
    s2.create();
    cout << endl;
    s1.print();
    cout << endl;
    s2.print();
    cout << endl;
    s1.sumSparse(s2);
    return 0;
}