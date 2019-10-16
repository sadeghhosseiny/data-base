#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

vector <Class> Database;


struct Date
{
    unsigned short int Year;
    unsigned short int Month;
    unsigned short int Day;
};

struct student
{
    string Firstname;
    string Lastname;
    unsigned long long int ID;
    Date Birthday;
    float Grade;
};

struct class
{
    string ClassName;
    float Average;
    unsigned short int Capacity;
    vector <student> Date;
};

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
        else if (CommandPlace.size() == 2 && CommandPlace[0] == "basu" &&CommandPlace[1] == "help")
        {
            cout << "here we have some command that i will tell you what they to do " << endl;
            cout << "about --basu add class-- : this command add a class to our classes" << endl;
            cout << "about --basu remove class-- : this command remove a class from our class" << endl;
            cout << "about --basu add student-- : this command add a student to one of our classes that we choose it" << endl;
            cout << "about --basu remove student-- : this command remove a studnet from on of our classes that we choose it" << endl;
            cout << "about --basu select class-- : this command select on of our classes in the select mode for other command" << endl;
            cout << "about --basu select none-- : this command take our acces of the classes" << endl;
            cout << "about --basu search-- : this command show a student by search ID or fullname from the selected class" << endl;
            cout << "about --basu show-- : this command show a selected class or show a special class" << endl;
            cout << "about --basu sort name-- : this command  sorts students of classes by names" << endl;
            cout << "about --basu sort ID-- : this command sorts students of classes by ID" << endl;
            cout << "about --basu save-- : this command save the data of classes in the seperate file" << endl;
            cout << "about --exit-- : this command quit you from the database of the students" << endl;
        }
        else if (CommandPlace.size() == 1 && CommandPlace[0] == "exit")
        {
            break;
        }
    }
}
