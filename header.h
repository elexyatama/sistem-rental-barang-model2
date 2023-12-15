#ifndef HEADER_RENTAL_INCLUDED
#define HEADER_RENTAL_INCLUDED
#include <iostream>

using namespace std;

struct infotype_customer
{
    string name;
    string id;
    int age;
    int nItem;
};

struct infotype_item
{
    string name;
    string id;
    string category;
    int nCount;
};

struct infotype_pic
{
    string name;
    string id;
    int age;
};

typedef struct elm_customer *adr_customer;
typedef struct elm_item *adr_item;
typedef struct elm_pic *adr_pic;

struct elm_customer
{
    infotype_customer info;
    adr_customer next;
    adr_item listItem;
};

struct elm_item
{
    infotype_item info;
    adr_item next;
    adr_pic pic;
};

struct elm_pic
{
    infotype_pic info;
    adr_pic next;
};

struct list_customer 
{
    adr_customer first;
    adr_customer last;
};

struct list_pic
{
    adr_pic first;
    adr_pic last;
};

void create_list_customer(list_customer &lc);
void create_list_pic(list_pic &lp);

adr_customer create_elm_customer(infotype_customer x);
adr_pic create_elm_pic(infotype_pic x);
adr_item create_elm_item(infotype_item x);

void insert_customer(list_customer &lc, adr_customer x);
void insert_item(adr_customer &ac, adr_item x);
void insert_pic(list_pic &lp, adr_pic x);

void delete_customer(list_customer &lc, string id);
void delete_item_from_customer(adr_customer &ac);
void delete_item(list_customer &lc, string id);

adr_customer search_customer(list_customer lc, string id, adr_customer *prec);
adr_item search_item(list_customer lc, string id, adr_item *prec);
adr_pic search_pic(list_pic lp, string id, adr_pic *prec);
adr_item search_item_from_customer(list_customer lc, string idItem, string idCustomer);

void show_all_customer_item(list_customer lc);
void show_all_customer(list_customer lc);
void show_customer_item(list_customer lc, string id);

#endif