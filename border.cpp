#include<bits/stdc++.h>
using namespace std;
#include "border.h"
#include "manager.h"
#include "bajar.h"
#include "extra_function.h"
#include "payment.h"


void intro_border();
void intro_login();
void waiting();

///constructor
border::border()
{
    strcpy(name,"N/A");
    strcpy(district,"N/A");
    strcpy(institution,"N/A");
    age = 0;
}



///login
//void login()

///taking input for login
void border:: get()
{
    int op,Password;
    char user_name[20];

    intro_login();

    cout<<dd<<"+-----------------------------------+"<<endl;
    cout<<dd<<"|    1. Don't have an account       |"<<endl;
    cout<<dd<<"|    2. Already have an account     |"<<endl;
    cout<<dd<<"+-----------------------------------+"<<endl;

    cin>>op;
    system("cls");
    switch(op)
    {
    case 1:
    {
        //account creating
        cout<<uuu;
        cout<<dd<<"+*************************************+"<<endl;
        cout<<dd<<"|                                     |"<<endl;
        cout<<dd<<"|      Creat an account first...      |"<<endl;
        cout<<dd<<"|                                     |"<<endl;
        cout<<dd<<"+*************************************+"<<endl;

        cout<<endl<<endl;

        registraion();

        update_file(this,"person.txt");

        waiting();

        cout<<endl<<endl<<dd"Account created successfully :)"<<endl<<endl<<dd;

        system("pause");

        break;
    }

    case 2:
    {
again_try:
        //account login

        intro_login();

        cout<<dd<<"Enter username : ";
        cin>>user_name;
        cout<<dd<<"Enter password : ";
        cin>>Password;



        system("cls");

        intro_login();

        ifstream person;
        person.open("person.txt",ios::binary | ios::app);

        if(!person)
        {
            cout<<"There is no such file in directory"<<endl;
            return ;
        }
        //checking if there exist such a person

        waiting();

        while(person.read(reinterpret_cast<char*>(this),sizeof(border)))
        {
            if(strcmp(user_name,name)==0 && Password==password)
            {

                registered_persons();

                return;
            }
        }


        cout<<dd<<"Invalid user name or password"<<endl;
        cout<<dd<<"\t\t\tTry again"<<endl;
        cout<<dd<<"Press b to back, t to try again"<<endl;
        char ch;
        cin>>ch;
        if(ch=='b')
        {
            system("cls");
            return;
        }
        system("cls");
        goto again_try;

        break;
    }

    }
}


///registraion
void border::registraion()
{
    cout<<dd<<"Enter your name       : ";
    cin>>name;
    cout<<dd<<"Enter your age        : ";
    cin>>age;
    cout<<dd<<"Enter your instituton : ";
    cin>>institution;
    cout<<dd<<"Home district         : ";
    cin>>district;
    cout<<dd<<"Enter your password   : ";
    cin>>password;

}


void border::registered_persons()
{
    char chh;
    do
    {
        int op;

        system("cls");

        intro_border();

        cout<<dd<<"+-----------------------------------------------+"<<endl;
        cout<<dd<<"|        1. To see information of yours         |"<<endl;
        cout<<dd<<"|        2. To see information of all borders   |"<<endl;
        cout<<dd<<"|        3. To add your bajar list              |"<<endl;
        cout<<dd<<"|        4. To add your payment                 |"<<endl;
        cout<<dd<<"+-----------------------------------------------+"<<endl;

        cin>>op;

        waiting();

        switch(op)
        {
        case 1:
        {
            display_single_border();
            break;
        }
        case 2:
        {
            //display all borders

            system("cls");

            intro_border();

            cout<<dd<<"___________________________________________________________________"<<endl;
            cout<<dd<<setw(20)<<left<<"Name"<<setw(20)<<"institution"<<setw(20)<<"age"<<setw(20)<<"district"<<endl;
            cout<<dd<<"___________________________________________________________________"<<endl;
            ifstream person;
            person.open("person.txt",ios::binary | ios::app);

            if(!person)
            {
                cout<<dd<<"There is no such file in directory"<<endl;
                return ;
            }

            while(person.read(reinterpret_cast<char*>(this),sizeof(border)))
            {
                display_all_borders();
            }
            break;
        }
        case 3:
        {
            bajar bj;
            bj.bajar_list();
            break;
        }
        case 4:
        {
            payment_manager pp;
            pp.load();
            pp.add_payment(name);

            break;

        }
        }

        cout<<endl<<dd<<"Press b to back in the main menu,or anything else to continue "<<endl;
        cin>>chh;
    }
    while(chh!='b');


}


void border::display_single_border()
{
    system("cls");

    intro_border();

    cout<<dd<<"+-----------------------------------------------+"<<endl;
    cout<<left;
    cout<<dd<<setw(15)<<"|     Name : "<<name<<endl;
    cout<<dd<<setw(15)<<"|     Age : "<<age<<endl;
    cout<<dd<<setw(15)<<"|     Institution : "<<institution<<endl;
    cout<<dd<<setw(15)<<"|     Home district : "<<district<<endl<<endl;

}


void border::display_all_borders()
{
    cout<<dd<<setw(20)<<name<<setw(20)<<institution<<setw(20)<<age<<setw(20)<<district<<endl;
    cout<<dd<<"___________________________________________________________________"<<endl;
}



