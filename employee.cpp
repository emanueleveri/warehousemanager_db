#include <iostream>
#include <string>
#include <sqlite3.h>
#include "employee.h"
#include "common.h"
using namespace std;

int sell(string code )
{
    int num;
    sqlite3* db;
    sqlite3_stmt* stmt;
    if(sqlite3_open("warehouse.db",&db)==SQLITE_OK)
    {
        string query = " select number from warehouse where code = \"" + code + "\";";
        sqlite3_prepare(db,query.c_str(),-1,&stmt,0);
        sqlite3_step(stmt);
        string value = ( const char *)sqlite3_column_text(stmt, 0);
        int num =atoi(value.c_str() );
        num--;
        query = "update warehouse set number = " + to_string(num) + " where code = \"" + code +"\";";
        sqlite3_prepare(db,query.c_str(),-1,&stmt,0);
        sqlite3_step(stmt);
        query = " select price from warehouse where code = \"" + code + "\";";
        sqlite3_prepare(db,query.c_str(),-1,&stmt,0);
        sqlite3_step(stmt);
        value = ( const char *)sqlite3_column_text(stmt, 0);
        double price =stod(value.c_str() );
        query = "insert into earn (money) values (" + to_string(price) +")";
        sqlite3_prepare(db,query.c_str(),-1,&stmt,0);
        sqlite3_step(stmt);
    }
}