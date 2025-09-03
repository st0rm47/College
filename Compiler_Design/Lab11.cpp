#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int i = 1, j = 0, no = 0, tmpch = 90;
string str, lft, rgt;

struct exp
{
    int pos;
    char op;
} k[15];

void findopr();
void explore();
void fleft(int);
void fright(int);

// Function to find operators in the expression
void findopr()
{
    char operators[] = {':', '/', '*', '+', '-'};
    for (int opIndex = 0; opIndex < strlen(operators); opIndex++)
    {
        for (i = 0; i < str.size(); i++)
        {
            if (str[i] == operators[opIndex])
            {
                k[j].pos = i;
                k[j++].op = operators[opIndex];
            }
        }
    }
}

// Function to explore the expression
void explore()
{
    i = 1;
    while (k[i].op != '\0')
    {
        fleft(k[i].pos);
        fright(k[i].pos);
        str[k[i].pos] = char(tmpch--);
        cout << "\t" << str[k[i].pos] << " := " << lft << k[i].op << rgt << "\t\t";

        for (j = 0; j < str.size(); j++)
        {
            if (str[j] != '$')
                cout << str[j];
        }
        cout << endl;
        i++;
    }
    fright(-1);
    if (no == 0)
    {
        fleft(str.size());
        cout << "\t" << rgt << " := " << lft;
        return;
    }
    cout << "\t" << rgt << " := " << str[k[--i].pos];
}

// Function to find the left operand
void fleft(int x)
{
    lft = "";
    int w = 0, flag = 0;
    x--;
    while (x != -1 && strchr("+-*/:=", str[x]) == NULL)
    {
        if (str[x] != '$' && flag == 0)
        {
            lft += str[x];
            str[x] = '$';
            flag = 1;
        }
        x--;
    }
}

// Function to find the right operand
void fright(int x)
{
    rgt = "";
    int w = 0, flag = 0;
    x++;
    while (x != -1 && (x < str.size()) && strchr("+-*/:=", str[x]) == NULL)
    {
        if (str[x] != '$' && flag == 0)
        {
            rgt += str[x];
            str[x] = '$';
            flag = 1;
        }
        x++;
    }
}

int main()
{
    cout << "\t\t===============================" << endl;
    cout << "\t\t  Intermediate Code Generator  " << endl;
    cout << "\t\t===============================" << endl;

    cout << "Enter the expression: ";
    cin >> str;

    cout << "The intermediate code:\t\t Expression\n";
    findopr();
    explore();
    cout << "\n\nCompiled by : Subodh Ghimire\n";
}
