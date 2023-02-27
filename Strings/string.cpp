// complete string operations mannually done
// by me :)
#include <iostream>
using namespace std;
// length of the string
int lengthstr(char s[])
{
    int len = 0;
    for (len = 0; s[len] != '\0'; len++)
    {
    }
    return len;
}
// upper to lower case characters
void lowerstr(char s[])
{
    for (int i = 0; i < lengthstr(s); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
            s[i] = s[i] + 32;
    }
    cout << "Lowered string: " << s << endl;
}
// lower to upper case characters
void upperstr(char s[])
{
    for (int i = 0; i < lengthstr(s); i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
            s[i] = s[i] - 32;
    }
    cout << "Upper string: " << s << endl;
}
// vowel count and consonent count
void vccount(char s[])
{
    int vcount = 0, ccount = 0;
    for (int i = 0; i < lengthstr(s); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            vcount++;
        }
        else if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            ccount++;
        }
    }
    cout << "Vowels: " << vcount << endl;
    cout << "Consonents: " << ccount << endl;
}
// counting words
void words(char s[])
{
    int wrdcnt = 0;
    for (int i = 0; i < lengthstr(s); i++)
    {
        if (s[i] == ' ')
        {
            wrdcnt++;
        }
    }
    wrdcnt++;
    cout << "Words: " << wrdcnt << endl;
}
// validation of a string
bool validstr(char s[])
{
    for (int i = 0; i < lengthstr(s); i++)
    {
        if (!(s[i] >= 65 && s[i] <= 90) && !(s[i] >= 97 && s[i] <= 122) && !(s[i] >= 48 && s[i] <= 57))
        {
            return false;
        }
    }
    return true;
}
// reversing of a string
void strreverse(char s[])
{
    char b[lengthstr(s) + 1];
    int i, j;
    i = lengthstr(s) - 1;
    for (j = 0; i >= 0; i--, j++)
    {
        b[j] = s[i];
    }
    b[j] = '\0';
    cout << "Reversed string: " << b << endl;
}
// checking if the string is palindrome
bool checkplindrm(char s[])
{
    int i, j = lengthstr(s) - 1;
    for (i = 0; i <= j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}
// checking if the string is valid
bool strcomparison(char s[], char q[])
{
    int i = 0;
    while (i < lengthstr(s) || i < lengthstr(q))
    {
        if (s[i] != q[i])
        {
            return false;
            break;
        }
        i++;
    }
    return true;
}
// the main function
int main()
{
    char s[] = "racecar";
    char q[] = "racecar";
    cout << "Length: " << lengthstr(s) << endl;
    upperstr(s);
    lowerstr(s);
    vccount(s);
    words(s);
    if (validstr(s))
    {
        cout << "String Valid!" << endl;
    }
    else
    {
        cout << "String invalid!" << endl;
    }
    strreverse(s);
    if (strcomparison(s, q))
    {
        cout << "String same" << endl;
    }
    else
    {
        cout << "String not same" << endl;
    }
    if (checkplindrm(s))
    {
        cout << "String palindrome" << endl;
    }
    else
    {
        cout << "String not palindrome" << endl;
    }
    return 0;
}