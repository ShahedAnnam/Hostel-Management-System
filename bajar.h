#ifndef BAJAR_H
#define BAJAR_H
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

class bajar
{
private:
    char date[20];
    char product[20][20];
    char amount[20][20];
    int cost[20];
    int total_cost;
    int t;
public:
    bajar(): total_cost(0) {}
    void bajar_list();
    void seeing_bajar_list();
    friend void update(bajar);

};

#endif // BAJAR_H
