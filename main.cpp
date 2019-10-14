#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

void start();

int main()
{
    start();
    return 0;
}

void start()
{
    string command;
    while(true)
    {
        cout << "database > ";
        getline(cin, command);
        if (command == "basu add class")
        {
            cout << "yes";
            break;
        }
    }
}
