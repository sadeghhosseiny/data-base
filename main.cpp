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

Date SeperateBirthday(string date)
{
    Date d;
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
    d.Year = stoi(temp[0]);
    d.Month = stoi(temp[1]);
    d.Day = stoi(temp[2]);
    return d;
}

//bool ChangeNameOfClasses(string &Str);

//void ChangeLowToUp(string &Str);
string FileName(string);

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
    start();
    return 0;
}

void start()
{
    string command;
    while(true)
    {

        vector<string> CommandPlace;
        cout << "Database > ";
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

        if (FileName(CommandPlace[0]) == "basu" && FileName(CommandPlace[1]) == "add" && FileName(CommandPlace[2]) == "class")
        {
            AddClass(CommandPlace[3]);
            CommandPlace.clear();
        }
        else if (FileName(CommandPlace[0]) == "basu" && FileName(CommandPlace[1]) == "remove" && FileName(CommandPlace[2]) == "class")
        {
            RemoveClass(CommandPlace[3]);
            CommandPlace.clear();
        }
        else if (FileName(CommandPlace[0]) == "basu" && FileName(CommandPlace[1]) == "add" && FileName(CommandPlace[2]) == "student")
        {
            string fu;
            string dt;
            cout << "enter name" << endl;
            getline(cin, fu);
            cout << "enter date" << endl;
            cin >> dt;
            Date d = SeperateBirthday(dt);
            float gr;
            cout << "enter grade" << endl;
            cin >> gr;
            unsigned long long int iD;
            cout << "enter Id" << endl;

            cin >> iD;
            AddStudent(fu, d, iD, gr);
            CommandPlace.clear();
            cin.get();
        }
        else if  (FileName(CommandPlace[0]) == "basu" && FileName(CommandPlace[1]) == "remove" && FileName(CommandPlace[2]) == "student")
        {
            RemoveStudent(stoull(CommandPlace[3]));
            CommandPlace.clear();
        }
        else if (FileName(CommandPlace[0]) == "basu" && FileName(CommandPlace[1]) == "select" && FileName(CommandPlace[2]) == "class")
        {
            SelectClass(CommandPlace[3]);
            CommandPlace.clear();
        }
        else if (FileName(CommandPlace[0]) == "basu" && FileName(CommandPlace[1]) == "select" && FileName(CommandPlace[2]) == "none")
        {
            GlobS = "";
            cout << "The class was empty" << endl;
        }
        else if (CommandPlace.size() == 3 && FileName(CommandPlace[0]) == "basu" && FileName(CommandPlace[1]) == "search")
        {
            if (CommandPlace[2] != "")
            {
                Search(stoull(CommandPlace[2]));
            }
            else
            {
                continue;
            }

        }
        else if (CommandPlace.size() == 4 && FileName(CommandPlace[0]) == "basu" && FileName(CommandPlace[1]) == "search")
        {
             if (CommandPlace[2] != "" && CommandPlace[3] != "")
            {
                Search(CommandPlace[2], CommandPlace[3]);
            }
            else
            {
                continue;
            }
        }
        else if (FileName(CommandPlace[0]) == "basu" && FileName(CommandPlace[1]) == "show")
        {
            if (CommandPlace.size() == 3)
            {
                ShowClass(FileName(CommandPlace[2]));
                continue;
            }

            if (GlobS != "")
                ShowClass(GlobS);

            //ShowAll();

        }
        else if (FileName(CommandPlace[0]) == "basu" && FileName(CommandPlace[1]) == "sort" && FileName(CommandPlace[2]) == "name")
        {

        }
        else if (FileName(CommandPlace[0]) == "basu" && FileName(CommandPlace[1]) == "sort" && FileName(CommandPlace[2]) == "id")
        {

        }
        else if (FileName(CommandPlace[0]) == "basu" && FileName(CommandPlace[1]) == "save")
        {

        }
        else if (FileName(CommandPlace[0]) == "basu" && FileName(CommandPlace[1]) == "help")
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
        else if (CommandPlace[0] == "exit")
        {
            break;
        }
    }
}

void AddClass(string fileName)
{
    Class cn;
    const char * fName = fileName.c_str();
    Student st;
    ifstream AC;
    AC.open(fName);
    if (!AC)
    {
        cout << "file doesn't added" << endl;
    }
    else
    {
        cout << "yes!file added" << endl;
        AC >> cn.ClassName;
        AC >> cn.Capacity;
        for (int i = 0; i < cn.Capacity; i ++)
        {
            string date;
            AC >> st.Firstname;
            AC >> st.Lastname;
            AC >> date;
            st.Birthday = SeperateBirthday(date);
            AC >> st.Grade;
            AC >> st.ID;
            cn.Data.push_back(st);
        }
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

void AddStudent(string FullName, Date brth, unsigned long long int iD, float avg)
{
    Student st;
    st.Birthday = brth;
    st.Grade = iD;
    st.ID = avg;
    for (int i = 0; i < FullName.length(); i ++)
    {
        if (FullName[i] != ' ')
        {
            st.Firstname += FullName[i];
        }
        else if (FullName[i] == ' ')
            for (i; i < FullName[i]; i ++)
            {

                {
                    st.Lastname += FullName[i];
                }
            }
    }
    for (Class &i : Database)
    {
        if (GlobS == i.ClassName)
        {
            i.Data.push_back(st);
        }
    }

}

void RemoveStudent(unsigned long long int iD)
{
    for (Class &i : Database)
    {
        if (i.ClassName == GlobS)
        {
            for (auto j = 0; j < i.Capacity; j ++)
            {
                if (i.Data[j].ID == iD)
                {
                    i.Data.erase(i.Data.begin() + j);
                    cout << "Student removed" << endl;
                    return;
                }
            }
        }
    }
    cout << "Student doesn't removed" << endl;
}

void ShowClass(string Cname)
{
    cout << "dwADAWDAD";
    for (Class &i : Database)
    {
        if (Cname == i.ClassName)
        {
            cout << i.ClassName << endl;
            cout << i.Capacity << endl;
            for (auto j = 0; j < i.Capacity; j ++)
            {
                cout << i.Data.at(j).Firstname << " " << i.Data.at(j).Lastname << " " << i.Data.at(j).Birthday.Year
                     << "/" << i.Data.at(j).Birthday.Month << "/" << i.Data.at(j).Birthday.Day << " "
                     << i.Data.at(j).Grade << " " << i.Data.at(j).ID << endl;
            }
            return;
        }
    }
    cout << "this class wasn't selected" << endl;
}

void Search(unsigned long long int iD)
{
    for (Class &i : Database)
    {
        if (i.ClassName == GlobS)
        {
            for (auto j = 0; j < i.Capacity; j++)
            {
                if (i.Data.at(j).ID == iD)
                {
                    cout << i.Data.at(j).Firstname << " " << i.Data.at(j).Lastname << " " << i.Data.at(j).Birthday.Year << "/"
                         << i.Data.at(j).Birthday.Month << "/" << i.Data.at(j).Birthday.Day << " " <<  i.Data.at(j).Grade << " "
                         << i.Data.at(j).ID << endl;
                    return;
                }
            }
        }
    }
    cout << "id is wrong " << endl;
}

void Search(string fn, string ln)
{
    for (Class &i : Database)
    {
        if (i.ClassName == GlobS)
        {
            for (int j = 0; j < i.Capacity; j++)
            {
                if (fn == i.Data.at(j).Firstname && i.Data.at(j).Lastname == ln)
                {
                    cout << i.Data.at(j).Firstname << " " << i.Data.at(j).Lastname << " " << i.Data.at(j).Birthday.Year << "/"
                         << i.Data.at(j).Birthday.Month << "/" << i.Data.at(j).Birthday.Day << " " <<  i.Data.at(j).Grade << " "
                         << i.Data.at(j).ID << endl;
                         return;
                }
            }
        }
    }
    cout << "First name and last name are wrong" << endl;
}

string FileName(string com)
{
    for (int i = 0; i < com.length(); i ++)
    {
        if (com[i] >= 'A' && com[i] <= 'Z')
        {
            com[i] += 32;
        }
    }
    return com;
}

