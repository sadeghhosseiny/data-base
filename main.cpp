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
        vector<string> placeCommand;
        cout << "database > ";
        string temp = "";
        getline(cin, command);
             for (int i = 0; command[i] != '\0'; i ++)
        {
            if (command[i] >= 'A' && command[i] <= 'Z')
            {
                command[i] = command[i] + 32;
            }
        }
        command += ' ';
        for (char c : command)
        {
            if (c != ' ')
            {
                temp += c;
            }
            else
            {
                placeCommand.push_back(temp);

                temp = "";
            }
        }
        if (placeCommand.size() == 3 && placeCommand[0] == "basu" && placeCommand[1] == "add" && placeCommand[2] == "class")
        {
            cout << "it's right" << endl;
            placeCommand.clear();
            break;
        }
    }
}
