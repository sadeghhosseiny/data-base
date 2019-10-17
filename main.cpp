#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

string GlobS = "";

struct Date
{
    unsigned short int Year;
    unsigned short int Month;
    unsigned short int Day;
};

struct Student
{
    string Firstname;
    string Lastname;
    unsigned long long int ID;
    Date Birthday;
    float Grade;
};

struct Class
{
    string ClassName;
    float Average;
    unsigned short int Capacity;
    vector <Student> Data;
};

vector <Class> Database;


void SelectClass(string);

void AddClass(string);

void RemoveClass(string);

void AddStudent(string, Date, unsigned long long int, float);

void RemoveStudent(unsigned long long int);

void Search(unsigned long long int);

void Search(string, string);

void ShowClass(string);

void ShowAll();

void SortByName();

void SortByID();

void Save();

void start();

int main()
{
    /*string fileName = "L1.basu";
    ifstream input(fileName.c_str(), ios::beg);

    Class cls;
    input >> cls.ClassName;
    input >> cls.Capacity;

    Student stud;
    for (int i = 0; i < cls.Capacity; i++)
    {
        input >> stud.Firstname;
        input >> stud.Lastname;
        input >> stud.Birthday;
        input >> stud.grade;
        input >> stud.ID

        cls.Data.push_back(stud);
    }
    Database.push_back(cls);*/

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

        for (int i = 0; i < CommandPlace.size() - 1; i ++)
        {
            for (char &j : CommandPlace[i])
            {
                if (j >= 'A' && j <= 'Z')
                {
                    j += 32;
                }
            }
        }


        if (CommandPlace[0] == "basu" && CommandPlace[1] == "add" && CommandPlace[2] == "class")
        {
            AddClass(CommandPlace[3]);
            CommandPlace.clear();
        }
        else if (CommandPlace[0] == "basu" && CommandPlace[1] == "remove" && CommandPlace[2] == "class")
        {
            RemoveClass(CommandPlace[3]);
            CommandPlace.clear();
        }
        else if (CommandPlace.size() == 3 && CommandPlace[0] == "basu" && CommandPlace[1] == "add" && CommandPlace[2] == "student")
        {

        }
        else if (CommandPlace.size() == 3 && CommandPlace[0] == "basu" && CommandPlace[1] == "remove" && CommandPlace[2] == "student")
        {

        }
        else if (CommandPlace[0] == "basu" && CommandPlace[1] == "select" && CommandPlace[2] == "class")
        {
            SelectClass(CommandPlace[3]);
            CommandPlace.clear();
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

void AddClass(string fileName)
{
    Class cn;
    Student st;
    ifstream AC;
    AC.open(fileName.c_str());
    AC >> cn.ClassName;
    AC >> cn.Capacity;
    if (!AC)
    {
        cout << "file doesn't added" << endl;
    }
    else
    {
        cout << "yes!file added" << endl;
    }
    for (int i = 0; i < cn.Capacity; i ++)
    {
        string date;
        AC >> st.Firstname;
        AC >> st.Lastname;
        AC >> date;
        string temp[3];
        int counter = 0;
        for (auto j : date)
        {
            if (j != '/')
            {
                temp[counter] += j;
            }
            else
            {
                counter ++;
            }
        }
        st.Birthday.Year = stoi(temp[0]);
        st.Birthday.Month = stoi(temp[1]);
        st.Birthday.Day = stoi(temp[2]);
        AC >> st.Grade;
        AC >> st.ID;
        cn.Data.push_back(st);
    }
    Database.push_back(cn);
    AC.close();
}

void SelectClass(string ClsName)
{
    for (Class cls : Database)
    {
        if (cls.ClassName == ClsName)
        {
            GlobS = ClsName;
            cout << "class '" << ClsName << "' has been selected!" << endl;
            return;
        }
    }
    cout << "there is no class named : " << ClsName << endl;
}

void RemoveClass(string ClsName)
{
    Class cls;
    for (auto i = 0; i < Database.size(); i ++ )
    {
        if (Database[i].ClassName == ClsName)
        {
            Database.erase(Database.begin() + i);
            cout << "Class removed successfully" << endl;
            return;
        }

    }
        cout << "this class wasn't selected" << endl;
}
