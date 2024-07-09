#include<bits/stdc++.h>
using namespace std;
#include "border.h"
#include "manager.h"
#include "bajar.h"
#include "extra_function.h"
#include "payment.h"

//manager m;

void intro_bajar();
void waiting();

void bajar::bajar_list()
{
    int op;
    char DATE[20];

    system("cls");

    intro_bajar();

    cout<<dd<<"+----------------------------------+"<<endl;
    cout<<dd<<"|        1.Make a list             |"<<endl;
    cout<<dd<<"|        2.See a list              |"<<endl;
    cout<<dd<<"+----------------------------------+"<<endl;

    cin>>op;

    waiting();

    system("cls");

    intro_bajar();

    switch(op)
    {
    case 1:
    {

        cout<<dd<<"Enter date  :  ";
        cin>>date;

        cout<<dd<<"How many products have you bought ?    "<<endl;
        cin>>t;

        for(int i=0; i<t; i++)
        {
            cin.ignore();
            cout<<dd<<"Product  : ";
            cin.get(product[i],20);
            cin.ignore();
            cout<<dd<<"Amount  : ";
            cin.get(amount[i],20);
            cout<<dd<<"Cost in tk  : ";
            cin>>cost[i];
            total_cost+=cost[i];

            payment_manager p;
            int f = p / total_cost;
            if(f==0)
            {
                cout<<dd<<"Pay your mill charge first before doing bajar"<<endl;
                return ;
            }

            cout<<endl<<endl;

        }

        update(*this);

        update_file(this,"List.txt");

        break;

    }
    case 2:
    {

        cout<<dd<<"Enter date =    ";
        cin>>DATE;
        system("cls");

        intro_bajar();

        ifstream BajarList;

        BajarList.open("List.txt",ios::binary);

        if(!BajarList)
        {
            cout<<dd<<"No Bajar List lave been added for this date"<<endl<<endl<<dd;
           // flag=1;
            system("pause");
            return ;
        }

        while(BajarList.read(reinterpret_cast<char*>(this),sizeof(bajar)))
        {
            if(strcmp(DATE,date)==0)
            {
                seeing_bajar_list();
            }
        }

    }
    }

}



void bajar::seeing_bajar_list()
{
    cout<<dd<<"                          ----  "<<date<<"   ----"<<endl<<endl;

    cout<<dd<<"___________________________________________________________________"<<endl;
    cout<<dd<<setw(20)<<left<<"product"<<setw(20)<<"amount"<<setw(20)<<"cost"<<endl;
    cout<<dd<<"___________________________________________________________________"<<endl;

    for(int i=0; i<t; i++)
    {
        cout<<dd<<setw(20)<<left<<product[i]<<setw(20)<<amount[i]<<setw(20)<<cost[i]<<endl;
        cout<<dd<<"___________________________________________________________________"<<endl;
    }

    cout<<dd<<"Total cost = "<<total_cost<<endl;

}


///introssss



