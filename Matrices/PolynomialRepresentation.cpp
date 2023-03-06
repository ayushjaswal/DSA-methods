#include <iostream>
using namespace std;
#include <math.h>

class Poly
{
private:
    int n;
    struct Term
    {
        int coeff;
        int exp;
    };
    struct Term *t;

public:
    Poly(){

    }
    Poly(int n){
        this->n = n;
        t = new Term[this->n];
    }
    void storeData()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Coeff: ";
            cin >> t[i].coeff;
            // cout << endl;
            cout << "Enter exp: ";
            cin >> t[i].exp;
            // cout << endl;
        }
    }

    int evalPoly(int x)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += t[i].coeff * pow(x, t[i].exp);
        }
        return sum;
    }

    Poly sumPoly(Poly p2)
    {
        int sn = n + p2.n;
        Poly sumPol(sn);
        int i, j, k;
        i = j = k = 0;
        while (i < n && j < p2.n)
        {
            if (t[i].exp == p2.t[j].exp)
            {
                sumPol.t[k].coeff = t[i].coeff + p2.t[j++].coeff;
                sumPol.t[k++].exp = t[i++].exp;
            }
            else if (t[i].exp > p2.t[j].exp)
            {
                sumPol.t[k++] = t[i++];
            }
            else
            {
                sumPol.t[k++] = p2.t[j++];
            }
        }
        for (; k < sumPol.n; k++)
        {
            sumPol.t[k].coeff = 0;
            sumPol.t[k].exp = 0;
        }
        return sumPol;
    };
};

int main()
{   int n1, n2;
    cout << "Enter number of terms: ";
    cin >> n1;
    cout << "Enter number of terms: ";
    cin >> n2;
    Poly p1(n1), p2(n2), p3;
    

    p1.storeData();
    
    p2.storeData();

    cout << "For x = 2, value is: " << p1.evalPoly(2) << endl;
    cout << "For x = 2, value is: " << p2.evalPoly(2) << endl;

    p3 = p1.sumPoly(p2);
    cout << "For x = 2, value is: " << p3.evalPoly(2) << endl;

    return 0;
}