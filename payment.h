#ifndef PAYMENT_H
#define PAYMENT_H
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

#define dd "                                                                       "
#define uu "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";


class payment
{
private:
    char month[20];
    char name[20];


public:
    int rent;
    int mill_charge;
    int total_mill_amount;
    int total_rent_amount;

    payment(): rent(0),mill_charge(0) ,total_mill_amount(0),total_rent_amount(0)
    {

    }
    payment(int x): rent(x)
    {

    }
    void payment_input(char* name);
    void display();
    void show();

};

class payment_manager
{
private:
    vector<payment>v;
public:
    payment_manager();
    void load();
    void display();
    void update();
    void add_payment(char*);
    void operator - (int);
    int operator / (int);

};



#endif // PAYMENT_H
