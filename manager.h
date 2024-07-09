#ifndef MANAGER_H
#define MANAGER_H
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#include "border.h"
#include "bajar.h"

class manager: public border
{
private:
    char date[20];
    char day[20];
    int cost;
public:
    manager(): cost(0) {}

    void registered_persons();
    void bajar_scedule();
    friend void update(bajar);

};

#endif // MANAGER_H
