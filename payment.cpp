#include "payment.h"
#include<bits/stdc++.h>


using namespace std;

int tma=0,tra=0,flag=0;

void intro_payment();
void waiting();

payment_manager::payment_manager()
{

}


void payment_manager::load()
{
    v.clear();

    ifstream Payment("paymentInformation.bin",ios::binary);

    if(!Payment)
    {
        cout<<dd<<"No one yet pay anything"<<endl<<endl<<dd;
        flag=1;
        system("pause");
        return ;
    }

    payment tmp;

    while(Payment.read(reinterpret_cast<char*>(&tmp),sizeof(payment)))
    {
        v.push_back(tmp);
    }
    Payment.close();

    for(auto i:v)
    {
        tma+=i.mill_charge;
        tra+=i.rent;

    }
}

void payment_manager:: update()
{

    ofstream Payment;
    Payment.open("paymentInformation.bin",ios::binary );
    for(auto tmp:v)
    {
        Payment.write(reinterpret_cast<char*>(&tmp),sizeof(payment));
    }
    Payment.close();

}

void payment_manager::add_payment(char* nam)
{

    payment p;
    p.payment_input(nam);
    v.push_back(p);

    update();
}

void payment_manager::display()
{

    load();

    if(flag)
    {
        flag=0;
        return;
    }

    cout<<dd<<"___________________________________________________________________"<<endl;
    cout<<dd<<setw(20)<<left<<"Name"<<setw(20)<<"Rent"<<setw(20)<<"Mill Charge"<<endl;
    cout<<dd<<"___________________________________________________________________"<<endl;

    for(auto tmp:v)
    {
        tmp.show();
    }

    auto x = v.end();
    x--;

    cout<<dd<<"Total mill amount is  =  "<<x->total_mill_amount<<endl;
    cout<<dd<<"Total rent amount is  =  "<<x->total_rent_amount<<endl;

    system("pause");
}



void payment::payment_input(char* nam)
{
    system("cls");

    intro_payment();

    cout<<dd<<"Enter the month : ";
    cin>>month;
    cout<<dd<<"Enter your rent amount : ";
    cin>>rent;
    cout<<dd<<"Enter mill charge : ";
    cin>>mill_charge;

    total_mill_amount = tma + mill_charge;
    total_rent_amount = tra + rent;

    strcpy(name,nam);

}

void payment::show()
{
    cout<<dd<<setw(20)<<name<<setw(20)<<rent<<setw(20)<<mill_charge<<endl;

    cout<<dd<<"___________________________________________________________________"<<endl;
}

void payment_manager::operator - (int y)
{
    load();

    if(flag) return ;

    auto x = v.end();
    x--;
    x->total_rent_amount-=y;
    update();

    cout<<endl<<dd<<y<<" taka successfully withdrawn :)"<<endl<<dd;

    waiting();

    system("pause");
}

int payment_manager::operator / (int y)
{
    load();

    if(flag) return 0;

    auto x = v.end();
    x--;
    x->total_mill_amount-=y;
    update();
}






