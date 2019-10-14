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
    vector<string> wow;
    while(true)
    {
        cout << "database > ";
        getline(cin, command);
        wow.push_back(command);
        for (int i = 0; command[i]!= '\0'; i ++)
        {
            if (command[i] >= 'A' && command[i] <= 'Z')
            {
                command[i] = command[i] + 32;
            }
        }
        if (command == "basu add class")
        {
            break;
        }

    }
}
