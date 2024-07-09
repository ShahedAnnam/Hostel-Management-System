#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#include "border.h"
#include "manager.h"
#include "bajar.h"
#include "extra_function.h"
#include "payment.h"
#include "intros.h"

void waiting();

int main()
{
    int n,i,choice;

    intro1();

    border* ptr;

    do
    {
        intro_main();

        cout<<dd<<"+-----------------------------------+"<<endl;
        cout<<dd<<"|    1. To login as a border        |"<<endl;
        cout<<dd<<"|    2. To login as a manager       |"<<endl;
        cout<<dd<<"|    3. To login as owner           |"<<endl;
        cout<<dd<<"|    4. To exit                     |"<<endl;
        cout<<dd<<"+-----------------------------------+"<<endl;
        cin>>choice;
        system("cls");
        switch(choice)
        {
        case 1:
        {
            ptr = new border;
            ptr->get();
            system("cls");
            break;
        }

        case 2:
        {
            ptr = new manager;
            ptr->get();
            system("cls");
            break;
        }
        case 3:
        {
            payment_manager p;

            intro_payment();

            waiting();
            system("cls");
            intro_payment();


            cout<<dd<<"+-----------------------------------------------+"<<endl;
            cout<<dd<<"|    1. Want to see the details of payment      |"<<endl;
            cout<<dd<<"|    2. Want to withdraw taka                   |"<<endl;
            cout<<dd<<"+-----------------------------------------------+"<<endl;
            int opt;
            cin>>opt;

            system("cls");

            intro_payment();

            if(opt==1)
            {
                p.display();
            }
            else
            {

                cout<<dd<<"+-----------------------------------------------------------+"<<endl;
                cout<<dd<<"|   Enter how many amount of tk do you want to cash out ?   |"<<endl;
                cout<<dd<<"+-----------------------------------------------------------+"<<endl;
                int tk;
                cin>>tk;
                p - tk;

            }
            system("cls");
            break;
        }
        case 4:
        {
            exit(0);
        }
        default:
            system("cls");
        }

    }
    while(choice!=0);



    return 0;
}

