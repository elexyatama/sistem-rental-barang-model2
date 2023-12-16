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

void delete_customer(list_customer &lc, string id) //delete customer
{
    if (!lc.first)
    {
        cout << "No customer listed yet" << endl;
    }
    else if (lc.first == lc.last)
    {
        delete_item_from_customer(lc.first); //sebelum delete customernya, semua item yang dipinjem customer harus dihapus
        adr_customer x = lc.first;
        lc.first = NULL;
        lc.last = NULL;
        delete x;
    }
    else
    {
        adr_customer q;
        adr_customer p = search_customer(lc, id, &q);
        delete_item_from_customer(p);
        q->next = p->next;
        delete p;
    }
}

void delete_item_from_customer(adr_customer &ac) //delete semua item yang dimiliki seorang customer
{
    while (ac->listItem)
    {
        adr_item p = ac->listItem;
        ac->listItem = p->next;
        delete p;
    }
    ac->listItem = NULL;
    ac->info.nItem = 0;
}

void delete_item(list_customer &lc, string id) //delete item berdasarkan id item
{
    if (!lc.first)
    {
        cout << "No customer listed yet" << endl;
    }
    else
    {
        adr_item q;
        adr_item p = search_item(lc, id, &q);
        q->next = p->next;
        delete p;
    }
} //note, nItem dikurangin di luar func

adr_customer search_customer(list_customer lc, string id, adr_customer *prec)   // buat nyari customer berdasarkan id
{                                                                               //prec ini ngembaliin elemen sebelum elemen yang dicari
    adr_customer p = lc.first;                                                  //soalnya search in nantinya juga bisa dipake buat hapus customer berdasarkan id
    while (p)
    {
        if (p->info.id == id)
        {
            return p;
        }
        *prec = p;
        p = p->next;
    }
    *prec = NULL;
    return NULL;
}

adr_item search_item(list_customer lc, string id, adr_item *prec)//buat nyari item berdasarkan id, gunsi prec sama kae search customer
{
    adr_customer p = lc.first;
    while (p)
    {
        adr_item q = p->listItem;
        while (q)
        {
            if (q->info.id == id)
            {
                return q;
            }
            *prec = q;
            q = q->next;
        }
        p = p->next;
    }
    *prec = NULL;
    return NULL;
}

adr_pic search_pic(list_pic lp, string id, adr_pic *prec) //buat nyari pic berdasarkan id, prec sama jg fungsinya kae sebelumnya
{
    adr_pic p = lp.first;
    while (p)
    {
        if (p->info.id == id)
        {
            return p;
        }
        *prec = p;
        p = p->next;
    }
    *prec = NULL;
    return NULL;
}

adr_item search_item_from_customer(list_customer lc, string idItem, string idCustomer) //buat nyari item dari customer tertentu
{
    adr_customer p = search_customer(lc, idCustomer, nullptr);
    if (!p)
    {
        cout << "No customer with such ID listed" << endl;
        return NULL;
    }

    adr_item q = p->listItem;
    while (q)
    {
        if (q->info.id == idItem)
        {
            return q;
        }
        q = q->next;
    }

    cout << "No item with such ID listed" << endl;
    return NULL;
}

void show_all_customer_item(list_customer lc) //buat print semua customer dengan item2 nya
{
    adr_customer p = lc.first;
    while (p)
    {
        cout << p->info.name << endl;
        adr_item q = p->listItem;
        while (q)
        {
            cout << "   - " << q->info.name;
            q = q->next;
        }
        p = p->next;
    }
}

void show_all_customer(list_customer lc) //buat print semua customer tanpa item2nya
{
    adr_customer p = lc.first;
    int count = 1;
    while (p)
    {
        cout << count << ". " << p->info.name << ", " << p->info.id << endl;
        count++;
        p = p->next;
    } 
}

void show_customer_item(list_customer lc, string id) //buat print 1 customer dan item2nya
{
    adr_customer p = search_customer(lc, id, NULL);
    cout << p->info.name << endl;
    adr_item q = p->listItem;
    while (q)
    {
        cout << "   - " << q->info.name;
        q = q->next;
    }
}

void show_all_pic(list_pic lp, string id) // buat print semua pic
{
    adr_pic p = lp.first;
    int count = 1;
    while (p)
    {
        cout << count << ". " << p->info.name << ", " << p->info.id << endl;
        count++;
        p = p->next;
    } 
}
