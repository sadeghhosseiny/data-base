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
        vector<string> CommandPlace;
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
                 CommandPlace.push_back(temp);

                temp = "";
            }
        }
        if (CommandPlace.size() == 3 && CommandPlace[0] == "basu" && CommandPlace[1] == "add" && CommandPlace[2] == "class")
        {
            cout << "class added" << endl;
            CommandPlace.clear();
        }
        else if (CommandPlace.size() == 3 && CommandPlace[0] == "basu" && CommandPlace[1] == "remove" && CommandPlace[2] == "class")
        {
            cout << "class removed" << endl;
            CommandPlace.clear();
        }
        else if (CommandPlace.size() == 3 && CommandPlace[0] == "basu" && CommandPlace[1] == "add" && CommandPlace[2] == "student")
        {

        }
        else if (CommandPlace.size() == 3 && CommandPlace[0] == "basu" && CommandPlace[1] == "remove" && CommandPlace[2] == "student")
        {

        }
        else if (CommandPlace.size() == 3 && CommandPlace[0] == "basu" && CommandPlace[1] == "select" && CommandPlace[2] == "class")
        {

        }
        else if (CommandPlace.size() == 3 && CommandPlace[0] == "basu" && CommandPlace[1] == "select" && CommandPlace[2] == "none")
        {

        }
        else if (CommandPlace.size() == 2 && CommandPlace[0] == "basu" && CommandPlace[1] == "search")
        {

        }
        else if (CommandPlace.size() == 2 && CommandPlace[0] == "basu" && CommandPlace[1] == "show")
        {

        }
        else if (CommandPlace.size() == 3 && CommandPlace[0] == "basu" && CommandPlace[1] == "sort" && CommandPlace[2] == "name")
        {

        }
        else if (CommandPlace.size() == 3 && CommandPlace[0] == "basu" && CommandPlace[1] == "sort" && CommandPlace[2] == "id")
        {

        }
        else if (CommandPlace.size() == 2 && CommandPlace[0] == "basu" && CommandPlace[1] == "save")
        {

        }
        else if (CommandPlace.size() == 1 && CommandPlace[0] == "exit")
        {
            break;
        }
    }
}
