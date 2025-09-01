#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

char ip_sym[50], stackArr[50];
int ip_ptr = 0, st_ptr = 0, len;
char temp[2], temp2[2];
char act[25];

void check();

int main()
{
    cout << "\t\t=======================" << endl;
    cout << "\t\t  Shift Reduce Parser  " << endl;
    cout << "\t\t=======================" << endl;

    cout << "Grammar:" << endl;
    cout << "E -> E + E" << endl;
    cout << "E -> E * E" << endl;
    cout << "E -> E / E" << endl;
    cout << "E -> a | b" << endl;

    cout << endl << "Enter the input symbol:\t";
    cin >> ip_sym;

    len = strlen(ip_sym);

    // Print table header
    cout << "+--------------------+-------------------------+-------------+" << endl;
    cout << "|      STACK         |      INPUT SYMBOL       |    ACTION   |" << endl;
    cout << "+--------------------+-------------------------+-------------+" << endl;

    // Initial state
    cout << "| " << left << setw(19) << "$"
         << "| " << setw(24) << (string(ip_sym) + "$")
         << "| " << setw(12) << "--" << "|" << endl;
    cout << "+--------------------+-------------------------+-------------+" << endl;

    strcpy(act, "Shift ");
    temp[0] = ip_sym[ip_ptr];
    temp[1] = '\0';
    strcat(act, temp);

    for (int i = 0; i < len; i++)
    {
        // Shift symbol into stack
        stackArr[st_ptr] = ip_sym[ip_ptr];
        stackArr[st_ptr + 1] = '\0';
        ip_sym[ip_ptr] = ' ';
        ip_ptr++;

        cout << "| " << left << setw(19) << ("$" + string(stackArr))
             << "| " << setw(24) << (string(ip_sym) + "$")
             << "| " << setw(12) << act << "|" << endl;
        cout << "+--------------------+-------------------------+-------------+" << endl;

        strcpy(act, "Shift ");
        temp[0] = ip_sym[ip_ptr];
        temp[1] = '\0';
        strcat(act, temp);

        check();
        st_ptr++;
    }

    cout << "+--------------------+-------------------------+-------------+" << endl;
    return 0;
}

void check()
{
    int flag = 0;
    temp2[0] = stackArr[st_ptr];
    temp2[1] = '\0';

    // Rule: a or b → E
    if (!strcmp(temp2, "a") || !strcmp(temp2, "b"))
    {
        stackArr[st_ptr] = 'E';
        stackArr[st_ptr + 1] = '\0';
        cout << "| " << left << setw(19) << ("$" + string(stackArr))
             << "| " << setw(24) << (string(ip_sym) + "$")
             << "| " << setw(12) << ("E -> " + string(temp2)) << "|" << endl;
        cout << "+--------------------+-------------------------+-------------+" << endl;
        flag = 1;
    }

    if (!strcmp(temp2, "+") || !strcmp(temp2, "*") || !strcmp(temp2, "/"))
        flag = 1;

    if (strstr(stackArr, "E+E") || strstr(stackArr, "E*E") || strstr(stackArr, "E/E"))
    {
        string rule;
        if (strstr(stackArr, "E+E"))
            rule = "E -> E+E";
        else if (strstr(stackArr, "E*E"))
            rule = "E -> E*E";
        else
            rule = "E -> E/E";

        strcpy(stackArr, "E");
        st_ptr = 0;

        cout << "| " << left << setw(19) << "$E"
             << "| " << setw(24) << (string(ip_sym) + "$")
             << "| " << setw(12) << rule << "|" << endl;
        cout << "+--------------------+-------------------------+-------------+" << endl;

        flag = 1;
    }

    if (!strcmp(stackArr, "E") && ip_ptr == len)
    {
        cout << "| " << left << setw(19) << "$E"
             << "| " << setw(24) << (string(ip_sym) + "$")
             << "| " << setw(12) << "ACCEPT" << "|" << endl;
        cout << "+--------------------+-------------------------+-------------+" << endl;
        exit(0);
    }

    if (flag == 0)
    {
        cout << "| " << left << setw(19) << ("$" + string(stackArr))
             << "| " << setw(24) << ip_sym
             << "| " << setw(12) << "REJECT" << "|" << endl;
        cout << "+--------------------+-------------------------+-------------+" << endl;
        exit(0);
    }
}
