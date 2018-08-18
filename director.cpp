#include <iostream>
#include <sqlite3.h>
#include "director.h"
#include <string>
#include "common.h"
using namespace std;



int failure()
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    char sure;
    cout << "Are you sure ? Y/N" << endl ;
    cin >> sure;
    if(sure=='Y')
    {
        string password;
        cout <<"Insert the director's password " << endl ;
        cin>>password;
        int checkack = checkpassword(password, 0);
        if(checkack==0)
        {
            if(sqlite3_open("warehouse.db",&db)==SQLITE_OK)
            {
                string query = "drop table warehouse ; ";
                sqlite3_prepare(db,query.c_str(),-1,&stmt,0);
                sqlite3_step(stmt);
                return 0;
            }else
            {
                return -1;
            }
        }else
            return -2;
        
    }else
    {
        return -3;
    }
}