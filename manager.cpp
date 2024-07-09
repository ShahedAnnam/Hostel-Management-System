
#include<bits/stdc++.h>
using namespace std;
#include "border.h"
#include "manager.h"
#include "bajar.h"
#include "extra_function.h"


void intro_manager();
void waiting();


void manager:: registered_persons()
{
    char chh;

    do
    {
        int op;

        system("cls");
        intro_manager();

        cout<<dd<<"+--------------------------------------------+"<<endl;
        cout<<dd<<"|        1. Create a bajar scedule           |"<<endl;
        cout<<dd<<"|        2. See bajar scedule                |"<<endl;
        cout<<dd<<"+--------------------------------------------+"<<endl;

        cin>>op;

        system("cls");

        intro_manager();

        switch(op)
        {
        case 1:
        {

            cout<<dd<<"Write a date   : ";
            cin>>date;
            cout<<dd<<"Day            : ";
            cin>>day;
            cout<<dd<<"Enter name     : ";
            cin>>name;

            update_file(this,"scedule.txt");

            waiting();

            cout<<dd<<"Bajar scedule added successfully :)"<<endl;

            break;

        }
        case 2:
        {
            waiting();


            ifstream scedule;
            scedule.open("scedule.txt",ios::binary);

            if(!scedule)
            {
                cout<<dd<<"No Bajar Scedule added yet"<<endl<<dd;
                system("pause");
                return ;
            }

            cout<<dd<<"___________________________________________________________________"<<endl;
            cout<<dd<<setw(20)<<left<<"date"<<setw(20)<<"day"<<setw(20)<<"name"<<setw(20)<<"cost"<<endl;
            cout<<dd<<"___________________________________________________________________"<<endl;

            while(scedule.read(reinterpret_cast<char*>(this),sizeof(manager)))
            {
                bajar_scedule();
            }
            break;
        }

        }

        cout<<endl<<dd<<"Press b to back in the main menu,or anything else to continue "<<endl;
        cin>>chh;
        system("cls");
    }
    while(chh!='b');

}

void manager::bajar_scedule()
{
    cout<<dd<<setw(20)<<date<<setw(20)<<day<<setw(20)<<name<<setw(20)<<cost<<endl;
    cout<<dd<<"___________________________________________________________________"<<endl;

}

void update(bajar bj)
{

    manager mn;
    ifstream scedule;
    ofstream temp;

    scedule.open("scedule.txt",ios::binary | ios::app);
    temp.open("Temp.txt",ios::binary | ios::app);

    while(scedule.read(reinterpret_cast<char*>(&mn),sizeof(manager)))
    {
        if(strcmp(bj.date,mn.date)==0)
        {
            mn.cost=bj.total_cost;

            temp.write(reinterpret_cast<char*>(&mn),sizeof(manager));
        }
        else
        {
            temp.write(reinterpret_cast<char*>(&mn),sizeof(manager));
        }
    }

    scedule.close();
    temp.close();

    remove("scedule.txt");
    rename("Temp.txt","scedule.txt");



}



