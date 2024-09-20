// #include<iostream>
// #include<fstream>
#include <string.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void choice1();
void choice2();
void choice3(int);
void choice4(int);
void choice5(int);
void choice6();
void choice7();
void choice8();
class school
{
protected:
    int code, pin;
    long long int phno;
    char name[25], add[50], dob[10], doj[10];

public:
    int getcode()
    {
        return code;
    }

    void input()
    {
        cin >> code >> pin >> phno;
        cin.ignore();
        cin.getline(name, 25);
        cin.getline(add, 50);
        cin.getline(dob, 10);
        cin.getline(doj, 10);
    }

    void output()
    {
        cout << " " << code << " " << pin << " " << phno << " " << name << " " << add << " " << dob << " " << doj << " ";
    }
};

class teacher : public school
{
private:
    int basic, hra, vda;

public:
    void getss();
    void disp();
};

class student : public school
{
private:
    int hin, eng, sci;

public:
    void getss();
    void disp();
    void input1()
    {
        cin>>hin>>eng>>sci;
    }
};
//************************************************************************************
void teacher::getss()
{
    cout << "enter data in following order:code_pin_phno_name_address_dob_doj_basic_hra_vda\n";
    input();
    cin >> basic >> hra >> vda;
}

void teacher::disp()
{
    output();
    cout << basic << " " << hra << " " << vda << " "
         << " " << basic + hra + vda;
    cout << endl;
}

void student::getss()
{
    cout << "enter data in following order:code_pin_phno_name_address_dob_doj_hin_eng_sci\n";
    input();
    cin >> hin >> eng >> sci;
}

void student::disp()
{
    output();
    cout << hin << " " << eng << " " << sci << " " << hin + eng + sci;
    cout << endl;
}

void tcreate(int n)
{
     ofstream fout("abc.dat", ios::binary | ios::app);
    if (!fout)
    {
        cout << "file is empty";
    }
    teacher t;
    int i;
    for (i = 0; i < n; i++)
    {
        t.getss();
        fout.write((char *)&t, sizeof(teacher));
    }
    fout.close();
}

void screate(int n)
{
    ofstream fout("xyz.dat", ios::binary | ios::out);
    if (!fout)
    {
        cout << "file is empty";
    }
    student t;
    int i;
    for (i = 0; i < n; i++)
    {
        t.getss();
        fout.write((char *)&t, sizeof(student));
    }
    fout.close();
}

void tdisp()
{
    ifstream fin("abc.dat", ios::binary | ios::in);
    if (!fin)
    {
        cout << "file is empty";
    }
    teacher t;
    while (fin.read((char *)&t, sizeof(teacher)))
    {
        t.disp();
    }
    fin.close();
}

void sdisp()
{
    ifstream fin("xyz.dat", ios::binary | ios::in);
    if (!fin)
    {
        cout << "file is empty";
    }
    student t;
    while (fin.read((char *)&t, sizeof(student)))
    {
        t.disp();
    }
    fin.close();
}

void tfind(int c)
{
    ifstream fin("abc.dat", ios::binary | ios::app);
    if (!fin)
    {
        cout << "file is empty";
    }
    teacher t;

    int x = 0;
    while (fin.read((char *)&t, sizeof(teacher)))
    {
        int code1 = t.getcode();
        if (code1 == c)
        {
            cout << "record found";
            cout << "\n";
            t.disp();
            x = 1;
            break;
        }
    }
    if (x != 1)
    {
        cout << "record not found";
    }

    fin.close();
}

void sfind(int c1)
{
    ifstream fin("xyz.dat", ios::binary | ios::app);
    if (!fin)
    {
        cout << "file is empty";
    }
    student t;
    int x = 0;
    while (fin.read((char *)&t, sizeof(student)))
    {
        int code1 = t.getcode();
        if (code1 == c1)
        {
            cout << "record found";
            cout << "\n";
            t.disp();
            x = 1;
            break;
        }
    }
    if (x != 1)
    {
        cout << "record not found";
    }

    fin.close();
}

void tedit(int e1)
{
    fstream fin("abc.dat", ios::in | ios::out);
    if (!fin)
    {
        cout << "file is empty";
    }
    teacher t;
    while (fin.read((char *)&t, sizeof(teacher)))
    {
        int code1 = t.getcode();
        if (code1 == e1)
        {
            t.getss();
            fin.seekp(-(sizeof(teacher)), ios::cur);
            fin.write((char *)&t, sizeof(teacher));
        }
    }
    fin.close();
}

void sedit(int e1)
{
    fstream fin("xyz.dat", ios::in | ios::out);
    if (!fin)
    {
        cout << "file is empty";
    }
    student t;
    while (fin.read((char *)&t, sizeof(student)))
    {
        int code1 = t.getcode();
        if (code1 == e1)
        {
            t.getss();
            fin.seekp(-(sizeof(student)), ios::cur);
            fin.write((char *)&t, sizeof(student));
        }
    }
    fin.close();
}

void sdelete(int e2)
{
    ifstream fin("xyz.dat", ios::in);
    ofstream fout("pqr.dat", ios::out);
    if (!fin)
    {
        cout << "file is empty";
    }
    student t;
    int code1;
    while (fin.read((char *)&t, sizeof(student)))
    {
        code1 = t.getcode();
        if (code1 != e2)
        {
            fout.write((char *)&t, sizeof(student));
        }
    }
    fin.close();
    fout.close();
    remove("xyz.dat");
    rename("pqr.dat", "xyz.dat");

    // sdisp();
}

void tdelete(int e2)
{
    ifstream fin("abc.dat", ios::in);
    ofstream fout("pqr.dat", ios::out);
    if (!fin)
    {
        cout << "file is empty";
    }
    teacher t;
    int code1;
    while (fin.read((char *)&t, sizeof(student)))
    {
        code1 = t.getcode();
        if (code1 != e2)
        {
            fout.write((char *)&t, sizeof(student));
        }
    }
    fin.close();
    fout.close();
    remove("abc.dat");
    rename("pqr.dat", "abc.dat");

    // tdisp();
}

void editmarks(int f)
{
    fstream fin("xyz.dat", ios::in | ios::out);
    if (!fin)
    {
        cout << "file is empty";
    }
    student t;
    cout<<"change marks hin_eng_sci:"<<endl;
    while (fin.read((char *)&t, sizeof(student)))
    {
        int code1 = t.getcode();
        if (code1 == f)
        {
            t.input1();
            fin.seekp(-(sizeof(student)), ios::cur);
            fin.write((char *)&t, sizeof(student));
        }
    }
    fin.close();
}
void choice1()
{
    cout << "############################################################################################################################" << endl;
    cout << "###############################################____SCHOOL__MANAGEMENT__project__############################################" << endl;
    cout << "############################################################################################################################" << endl;
    cout << "_______________________________________________________welcome______________________________________________________________" << endl;
    cout << "enter 1 for login as admin " << endl
         << "enter 2 for login as teacher " << endl
         << "enter 3 for login as student " << endl;
    cout << "enter 4 for exit" << endl;
    choice2();
}

void choice2()
{
    cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    int z;
    cin >> z;
    if (z == 1)
    {
        choice6();
    }
    else if (z == 2)
    {
        choice7();
    }
    else if (z == 3)
    {
        choice8();
    }
    else if (z == 4)
    {
         cout << "//////////////////////////////////////////////_END_//////////////////////////////////////////////" << endl;
        exit(0);
    }
}

void choice3(int v)
{
    int b;
    if (v == 1)
    {
        cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "enter 1 to create:" << endl;
        cout << "enter 2 to display:" << endl;
        cout << "enter 3 to find:" << endl;
        cout << "enter 4 to update:" << endl;
        cout << "enter 5 to delete :" << endl;
        cout << "enter 5 for return:" << endl;
        cout << "enter 6 to exit:" << endl;
        cin >> b;
        if (b == 1)
        {
            int n;
            cout << "enter number of records you want to create:" << endl;
            cin >> n;
            tcreate(n);
            cout << endl;
            cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            choice6();
        }
        else if (b == 2)
        {
            tdisp();
            cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            choice6();
        }
        else if (b == 3)
        {
            int y;
            cout << "enter code number of the record :" << endl;
            cin >> y;
            tfind(y);
            cout << endl;
            cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            choice6();
        }
        else if (b == 4)
        {
            int c1;
            cout << "enter code number of the record you want to record:" << endl;
            cin >> c1;
            tedit(c1);
            cout << endl;
            cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            choice6();
        }
        else if (b == 5)
        {
            int y;
            cout << "enter code number of the record you want to delete :" << endl;
            cin >> y;
            tdelete(y);
            cout << endl;
            cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            choice6();
        }
        else if (b == 6)
        {
            cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            choice6();
        }
        else if (b == 7)
        {
            cout << "///////////////////////////////////////////_END_/////////////////////////////////////////////////" << endl;
            exit(0);
        }
        else
        {
            cout << "enter valid value";
        }
    }
    else if (v == 2)
    {
        cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "enter 1 to create:" << endl;
        cout << "enter 2 to display:" << endl;
        cout << "enter 3 to find:" << endl;
        cout << "enter 4 to update:" << endl;
        cout << "enter 5 to delete:" << endl;
        cout << "enter 6 for return:" << endl;
        cout << "enter 7 to exit:" << endl;
        cin >> b;
        if (b == 1)
        {
            int n;
            cout << "enter number of records you want to create:" << endl;
            cin >> n;
            screate(n);
            cout << endl;
            cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            choice6();
        }
        else if (b == 2)
        {
            sdisp();
            cout << endl;
            cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            choice6();
        }
        else if (b == 3)
        {
            int c;
            cout << "enter code number of the record :" << endl;
            cin >> c;

            sfind(c);
            cout << endl;
            cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            choice6();
        }
        else if (b == 4)
        {
            int c1;
            cout << "enter code number of the record you want to change:" << endl;
            cin >> c1;
            sedit(c1);
            cout << endl;
            cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            choice6();
        }
        else if (b == 5)
        {
            cout << "enter code of record you want to delete:" << endl;
            int s;
            cin >> s;
            sdelete(s);
            cout << endl;
            cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            choice6();
        }
        else if (b == 6)
        {
            cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            choice6();
        }
        else if (b == 7)
        {
            cout << "//////////////////////////////////////////////_END_//////////////////////////////////////////////" << endl;
            exit(0);
        }
        else
        {
            cout << "enter valid value";
        }
    }
    else if (v == 3)
    {
        cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        choice1();
    }

    else
    {
        cout << "enter valid value";
    }
}

void choice4(int n)
{
    if (n == 1)
    {
        int j;
        cout << "enter code of student which you want to edit:" << endl;
        cin >> j;
        editmarks(j);
        cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        choice7();
    }
    else if (n == 2)
    {
        int e;
        cout << "enter the code of data :" << endl;
        cin >> e;
        tfind(e);
        cout << endl;
        cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        choice7();
    }
    else if (n == 3)
    {
        tdisp();
        cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        choice7();
    }
    else if (n == 4)
    {
        sdisp();
        cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        choice7();
    }
    else if (n == 5)
    {
        cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        choice1();
    }
    else
    {
        cout << "enter valid value";
    }
}

void choice5(int n)
{

    if (n == 1)
    {
        cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        sdisp();
        cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        choice8();
    }
    else if (n == 2)
    {
        int e;
        cout << "enter the code of data :" << endl;
        cin >> e;
        sfind(e);
        cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        choice8();
    }
    else if (n == 3)
    {
        cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        choice1();
    }
    else
    {
        cout << "enter valid value";
    }
}

void choice6()
{
    cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    int x;
    cout << "enter 1 for teacher:" << endl
         << "enter 2 for student:" << endl;
    cout << "enter 3 for return" << endl;
    cin >> x;
    cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    choice3(x);
}

void choice7()
{
    cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    int x;
    cout << "enter 1 to edit marks of student" << endl;
    cout << "enter 2 to find" << endl;
    cout << "enter 3 to display for teacher" << endl;
    cout << "enter 4 to display for student" << endl;
    cout << "enter 5 for return" << endl;
    cin >> x;
    cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    choice4(x);
}

void choice8()
{
    cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    int x;
    cout << "enter 1 to display" << endl;
    cout << "enter 2 to find" << endl;
    cout << "enter 3 for return" << endl;
    cin >> x;
    cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    choice5(x);
}

int main()
{
    choice1();
//    screate(2);
  //  sdisp();
    //editmarks(22);
    //sdisp();
}
