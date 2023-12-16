#include <iostream>
#include "header.h"

using namespace std;

void create_list_customer(list_customer &lc)
{
    lc.first = NULL;
    lc.last = NULL;
}

void create_list_pic(list_pic &lp)
{
    lp.first = NULL;
    lp.last = NULL;
}

adr_customer create_elm_customer(infotype_customer x)
{
    adr_customer p = new elm_customer;
    p->info = x;
    p->next = NULL;
    p->listItem = NULL;
}

adr_pic create_elm_pic(infotype_pic x)
{
    adr_pic p = new elm_pic;
    p->info = x;
    p->next = NULL;
}

adr_item create_elm_item(infotype_item x)
{
    adr_item p = new elm_item;
    p->info = x;
    p->next = NULL;
    p->pic = NULL;
}

void insert_customer(list_customer &lc, adr_customer x)
{
    if (!lc.first) // ketika list kosong
    {
        lc.first = x;
        lc.last = x;
    }
    else // isi  / normal
    {
        lc.last->next = x;
        lc.last = x;
    }
}

void insert_item(adr_customer &ac, adr_item x)
{
    if (!ac->listItem) // ketika listItem masih kosong
    {
        ac->listItem = x;
        ac->info.nItem++;
    }
    else //list item > 1 isi / normal
    {
        adr_item p = ac->listItem;
        while (p->next)
        {
            p = p->next;
        }
        p->next = x;
        ac->info.nItem++;
    }
}

void insert_pic(list_pic &lp, adr_pic x)
{
    if (!lp.first) // ketika list kosong
    {
        lp.first = x;
        lp.last = x;
    }
    else // isi list > 1 / normal
    {
        lp.last->next = x;
        lp.last = x;
    }
}

void delete_customer(list_customer &lc, string id)
{

}

void delete_item_from_customer(adr_customer &ac)
{

}

void delete_item(list_customer &lc, string id)
{

}

adr_customer search_customer(list_customer lc, string id, adr_customer *prec)
{

}

adr_item search_item(list_customer lc, string id, adr_item *prec)
{

}

adr_pic search_pic(list_pic lp, string id, adr_pic *prec)
{

}

adr_item search_item_from_customer(list_customer lc, string idItem, string idCustomer)
{

}

void show_all_customer_item(list_customer lc)
{

}

void show_all_customer(list_customer lc)
{

}

void show_customer_item(list_customer lc, string id)
{

}
