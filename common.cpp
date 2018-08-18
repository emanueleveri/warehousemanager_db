#include <iostream>
#include <sqlite3.h>
#include "common.h"
using namespace std;

int login()
{
    int logret;
    cout << " Warehouse Manager " << endl ;
    string log[]={"Director", "Employee","Customer"};
    for( int i=0 ; i < 3; i++)
        cout << i+1 << "\t" << log[i] << endl ;
    cout << "Enter number for login " << endl ;
    cin>>logret;
    return logret;
}
int checkpassword(string password, int id)
{
    sqlite3* db;
    sqlite3_stmt* selectstmt;
    if(sqlite3_open("password.db",&db)==SQLITE_OK)
    {
        string query;
        if(id == 0)
        {
            query = "select password from password where user =\"director\"";
        }else if(id==1)
        {
            query = "select password from password where user =\"employee\"";
        }
        if(sqlite3_prepare(db,query.c_str(),-1,&selectstmt, 0)==SQLITE_OK)
        {
            sqlite3_step(selectstmt);
            string psw = (const char*)sqlite3_column_text(selectstmt,0);
            if(password==psw)
            {
                return 0;
            }else
            {
                return -2;
            }
        }
    }else
        return -1;
}
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int selectall()
{
    sqlite3* db;
    string sql="select * from warehouse";
    char *zErrMsg = 0;
    const char* data = "Calblack function called";
    if(sqlite3_open("warehouse.db",&db)==SQLITE_OK)
    {
        sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
        return 0;
    }
    else
        return -1;
}
int showFunctions(int id)
{
    int chosen;
    system("clear");
    if(id==0)
    {
        string directorfunction[]={"see all records","delete a record","modify a record","add a record","failure"};
        for(int i=0; i< 5; i++)
            cout << i+1 << "\t" << directorfunction[i] << endl ;
        cout << "Choose > " << endl ;
        cin>>chosen;
    }else if(id==1)
    {
        string employeefunction[]={"see all records","delete a record","modify a record","add a record","sell a product"};
        for(int i=0; i< 5; i++)
            cout << i+1 << "\t" << employeefunction[i] << endl ;
        cout << "Choose > " << endl ;
        cin>>chosen;
    }else if(id==2)
    {
        string customerfunction[]={"see all records","buy"};
        for(int i=0; i< 2; i++)
            cout << i+1 << "\t" << customerfunction[i] << endl ;
        cout << "Choose > " << endl ;
        cin>>chosen;
    }
    return chosen;
}

int deleteRecord(string code)
{
    sqlite3_stmt * stmt;
    sqlite3* db;
    string sql = " delete from warehouse where codice = \"" + code + "\""; 
    if(sqlite3_open("warehouse.db",&db)==SQLITE_OK)
    {
        string query = " delete from warehouse where code =\""+code+"\"";
        sqlite3_prepare(db, query.c_str(), -1,&stmt,0);
        sqlite3_step(stmt);
        return 0;
    }else
        return -1;
}

int modifyrecord(string code, string name,string type,int number,double price)
{
    sqlite3*db;
    sqlite3_stmt* stmt;
    if(sqlite3_open("warehouse.db",&db)==SQLITE_OK)
    {
        string query = "update warehouse set name = \""+ name +"\", type = \"" + type +"\", price = \"" + to_string(price) +"\", number = \"" + to_string(number) + "\";";
        sqlite3_prepare(db,query.c_str(),-1,&stmt,0);
        sqlite3_step(stmt);
        return 0;
    }else
        return -1;
}

int addrecord(string code, string name, string type, int number, double price)
{
    sqlite3*db;
    sqlite3_stmt* stmt;
    string query="insert into warehouse(code,name,type,price,numer) values(\""+code+"\"" + name +"\""+type +"\"" + to_string(price) + "\"" + to_string(number) + "\"";
    if(sqlite3_open("warehouse.db",&db)==SQLITE_OK)
    {
        sqlite3_prepare(db, query.c_str(),-1,&stmt,0);
        sqlite3_step(stmt);
    }else
        return -1;
}