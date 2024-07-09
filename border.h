#ifndef BORDER_H
#define BORDER_H
#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;

class border
{
private:
    //string name;
    char district[20];
    char institution[20];
    int age;
    int password;
protected:
    char name[20];
public:

    border();
    void registraion();
    void display_single_border();
    void display_all_borders();
    virtual void registered_persons();
    void get();
    void test();

};


#endif // BORDER_H
