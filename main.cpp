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

string SensitiveFileName(string);

float Avg(const Class &);

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
    vector<string> CommandPlace;
    while(true)
    {
        if (CommandPlace.size() == 0)
        {
            cout << "Database > ";
            if (GlobS != "")
            {
                cout << GlobS << " >";
            }
        }
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


        if (SensitiveFileName(CommandPlace[0]) == "basu" && SensitiveFileName(CommandPlace[1]) == "add" && SensitiveFileName(CommandPlace[2]) == "class")
        {
            AddClass(CommandPlace[3]);
            CommandPlace.clear();
        }
        else if (SensitiveFileName(CommandPlace[0]) == "basu" && SensitiveFileName(CommandPlace[1]) == "remove" && SensitiveFileName(CommandPlace[2]) == "class")
        {
            RemoveClass(CommandPlace[3]);
            CommandPlace.clear();
        }
        else if (SensitiveFileName(CommandPlace[0]) == "basu" && SensitiveFileName(CommandPlace[1]) == "add" && SensitiveFileName(CommandPlace[2]) == "student")
        {
            string fu;
            string dt;
            cout << "enter first name and last name" << endl;
            getline(cin, fu);
            cout << "enter date" << endl;
            cin >> dt;
            Date d;
            try
            {
                d = SeperateBirthday(dt);
            }
            catch (...)
            {
                cout << "Enter date correctly" << endl;
                continue;
            }
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
        else if  (SensitiveFileName(CommandPlace[0]) == "basu" && SensitiveFileName(CommandPlace[1]) == "remove" && SensitiveFileName(CommandPlace[2]) == "student")
        {
            if (CommandPlace.size() == 4)
            {
                RemoveStudent(stoull(CommandPlace[3]));
            }
            else
            {
                cout << "enter ID" << endl;
            }
            CommandPlace.clear();
        }
        else if (SensitiveFileName(CommandPlace[0]) == "basu" && SensitiveFileName(CommandPlace[1]) == "select" && SensitiveFileName(CommandPlace[2]) == "class")
        {
            SelectClass(CommandPlace[3]);
            CommandPlace.clear();
        }
        else if (SensitiveFileName(CommandPlace[0]) == "basu" && SensitiveFileName(CommandPlace[1]) == "select" && SensitiveFileName(CommandPlace[2]) == "none")
        {
            GlobS = "";
            cout << "The class was empty" << endl;
            CommandPlace.clear();
        }
        else if (CommandPlace.size() == 3 && SensitiveFileName(CommandPlace[0]) == "basu" && SensitiveFileName(CommandPlace[1]) == "search")
        {
            if (CommandPlace[2] != "")
            {
                Search(stoull(CommandPlace[2]));
            }
            else
            {
                continue;
            }
            CommandPlace.clear();
        }
        else if (CommandPlace.size() == 4 && SensitiveFileName(CommandPlace[0]) == "basu" && SensitiveFileName(CommandPlace[1]) == "search")
        {
            if (CommandPlace[2] != "" && CommandPlace[3] != "")
            {
                Search(CommandPlace[2], CommandPlace[3]);
            }
            else
            {
                continue;
            }
            CommandPlace.clear();
        }
        else if (SensitiveFileName(CommandPlace[0]) == "basu" && SensitiveFileName(CommandPlace[1]) == "show")
        {
            if (CommandPlace.size() == 3)
            {
                ShowClass(CommandPlace[2]);
                continue;
            }

            else if ( CommandPlace.size() == 2 && GlobS != "")
                ShowClass(GlobS);
            else if (CommandPlace.size() == 2 && GlobS == "")
            {
                ShowAll();
            }
            CommandPlace.clear();
        }
        else if (SensitiveFileName(CommandPlace[0]) == "basu" && SensitiveFileName(CommandPlace[1]) == "sort" && SensitiveFileName(CommandPlace[2]) == "name")
        {
            if (GlobS != "")
            {
                SortByName();
            }
            else if (GlobS == "")
            {
                SortByName();
            }
            CommandPlace.clear();
        }
        else if (SensitiveFileName(CommandPlace[0]) == "basu" && SensitiveFileName(CommandPlace[1]) == "sort" && SensitiveFileName(CommandPlace[2]) == "id")
        {
            if (GlobS != "")
            {
                SortByID();
            }
            else if (GlobS == "")
            {
                SortByID();
            }
            CommandPlace.clear();
        }
        else if (SensitiveFileName(CommandPlace[0]) == "basu" && SensitiveFileName(CommandPlace[1]) == "save")
        {
            Save();
            CommandPlace.clear();
        }
        else if (SensitiveFileName(CommandPlace[0]) == "basu" && SensitiveFileName(CommandPlace[1]) == "help")
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
            CommandPlace.clear();
        }
        else if (SensitiveFileName(CommandPlace[0]) == "exit")
        {
            break;
        }
        else
        {
            cout << "We don't have this command" << endl;
            CommandPlace.clear();
        }
    }
}

void AddClass(string fileName)
{
    Class cn;
    Student st;
    ifstream AC;
    AC.open(fileName.c_str());
    if (!AC)
    {
        cout << "Class name is wrong" << endl;
        return;
    }
    AC >> cn.ClassName;
    for (Class &cls : Database)
    {
        if (cls.ClassName == cn.ClassName)
        {
            cout << "this class was added befor" << endl;
            return;
        }
    }
    AC >> cn.Capacity;
    for (int i = 0; i < cn.Capacity; i ++)
    {
        string date;
        float GradeSum;
        AC >> st.Firstname;
        AC >> st.Lastname;
        AC >> date;
        st.Birthday = SeperateBirthday(date);
        AC >> st.Grade;
        GradeSum += st.Grade;
        cn.Average = GradeSum / cn.Capacity;
        AC >> st.ID;
        cn.Data.push_back(st);

    }

    Database.push_back(cn);

    cout << "file added" << endl;
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
    cout << "we don't have this class" << endl;
}

void AddStudent(string FullName, Date brth, unsigned long long int iD, float avg)
{
    Student st;
    st.Birthday = brth;
    st.Grade = avg;
    st.ID = iD;
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
            i.Capacity ++;
            i.Average = Avg(i);
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
                    i.Capacity --;
                    i.Average = Avg(i);
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
    for (Class &i : Database)
    {
        if (Cname == i.ClassName)
        {
            i.Average = Avg(i);
            cout << i.ClassName << endl;
            cout << i.Capacity << endl;
            cout << i.Average << endl;
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

void ShowAll()
{
    for (Class &i : Database)
    {
        i.Average = Avg(i);
        cout << i.ClassName << endl;
        cout << i.Capacity << endl;
        cout << i.Average << endl;
        for (int j = 0; j < i.Capacity; j++)
        {

            cout << left << setw(18) << i.Data.at(j).Firstname + " " + i.Data.at(j).Lastname << setw(15) << to_string(i.Data.at(j).Birthday.Year)
                 + "/" + to_string(i.Data.at(j).Birthday.Month) + "/" + to_string(i.Data.at(j).Birthday.Day) << setw(13)
                 << i.Data.at(j).Grade << setw(15) << i.Data.at(j).ID << endl;
        }

    }
    return;
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

void SortByName()
{
    for (Class &cl : Database)
    {
        if (GlobS == cl.ClassName)
        {
            for (int i = 0; i < (cl.Capacity) - 1; i++)
            {
                for (int j = i + 1; j < cl.Capacity; j++)
                {
                    if (cl.Data.at(i).Firstname > cl.Data.at(j).Firstname)
                    {
                        swap(cl.Data.at(i), cl.Data.at(j));
                    }
                }
            }
            cout << GlobS << " " << "sorted by name" << endl;
        }
        else if (GlobS == "")
        {
            for (int i = 0; i < (cl.Capacity) - 1; i++)
            {
                for (int j = i + 1; j < cl.Capacity; j++)
                {
                    if (cl.Data.at(i).Firstname > cl.Data.at(j).Firstname)
                    {
                        swap(cl.Data.at(i), cl.Data.at(j));
                    }
                }
            }
            cout << cl.ClassName << " " <<"sorted by name" << endl;
        }

    }

}

void SortByID()
{
    for (Class &cl : Database)
    {
        if (cl.ClassName == GlobS)
        {
            for (int i = 0; i < (cl.Capacity) - 1; i++)
            {
                for (int j = i + 1; j < cl.Capacity; j++)
                {
                    if (cl.Data.at(i).ID > cl.Data.at(j).ID)
                    {
                        swap(cl.Data.at(i), cl.Data.at(j));
                    }
                }
            }
            cout << GlobS << " " << "sorted by ID" << endl;
        }
        else if (GlobS == "")
        {
            for (int i = 0; i < cl.Capacity - 1; i++)
            {
                for (int j = i + 1; j < cl.Capacity; j++)
                {
                    if (cl.Data.at(i).ID > cl.Data.at(j).ID)
                    {
                        swap(cl.Data.at(i), cl.Data.at(j));
                    }
                }
            }
            cout << cl.ClassName << " " << "sorted by ID" << endl;
        }
    }
}

void Save()
{
    if (GlobS != "")
        for (Class &cls : Database)
        {
            if (cls.ClassName == GlobS)
            {
                ofstream file(cls.ClassName.c_str());
                file << cls.ClassName << endl;
                file << cls.Capacity << endl;
                file << cls.Average << endl;
                for (int i = 0; i < cls.Capacity; i++)
                {
                    file << cls.Data.at(i).Firstname << " " << cls.Data.at(i).Lastname << " " << cls.Data.at(i).Grade << " " << cls.Data.at(i).Birthday.Year
                         << "/" << cls.Data.at(i).Birthday.Month << "/" << cls.Data.at(i).Birthday.Day << " " << cls.Data.at(i).ID << endl;
                }
                cout << "Everything saved" << endl;
                file.close();
            }
        }
    if (GlobS == "")
    {
        for (Class &cls : Database)
        {
            ofstream file(cls.ClassName.c_str());
            file << cls.ClassName << endl;
            file << cls.Capacity << endl;
            file << cls.Average << endl;
            for (int i = 0; i < cls.Capacity; i++)
            {
                file << left << setw(18) << cls.Data.at(i).Firstname + " " + cls.Data.at(i).Lastname << setw(15) << to_string(cls.Data.at(i).Birthday.Year)
                 + "/" + to_string(cls.Data.at(i).Birthday.Month) + "/" + to_string(cls.Data.at(i).Birthday.Day) << setw(13)
                 << cls.Data.at(i).Grade << setw(15) << cls.Data.at(i).ID << endl;
            }
            file.close();

        }
        cout << "Everything saved" << endl;

    }
}

float Avg(const Class &i)
{
    float sum = 0;
    float Avg;
    for (const Student &j : i.Data)
    {
        sum += j.Grade;
    }
    return sum / i.Capacity;
}

string SensitiveFileName(string com)
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

