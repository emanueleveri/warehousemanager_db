#include <iostream>
#include <sqlite3.h>
#include "common.h"
#include "director.h"
#include "employee.h"
#include "customer.h"
using namespace std;

int main()
{
    int logack = login();
    switch(logack)
    {
        case 1:
        {
            //Director login
            wrongpsw:
            string password;
            cout << " Insert your password " << endl ;
            cin>>password;
            int chkack = checkpassword(password,0);
            switch(chkack)
            {
                case 0:
                {
                    sqlite3* db;
                    int ack = showFunctions(0);
                    switch(ack)
                    {
                        case 1:
                        {
                            cout << " Show all records  " << endl ;
                            int selectack = selectall();
                            if(selectack == 0)
                                cout << " I've done " << endl;
                            else    
                                cout << " Error while opening the database " << endl ;
                        }break;
                        
                        case 2:
                        {
                            string code;
                            sqlite3_stmt* stmt;
                            cout << "Delete a record " << endl;
                            cout << " Insert the code " << endl ;
                            cin>>code;
                            int delack = deleteRecord(code);
                            if(delack==0)
                                cout <<"Ok I've done"<<endl;
                            else if(delack==-1)
                                cout <<"Error while opening the database " << endl;
                        }break;

                        case 3:
                        {
                            string newname, newtype,code;
                            int number;
                            double price;
                            cout << "Modify a record " << endl ;
                            cout << "Insert the code of the record which you want to modify";
                            cin>>code;
                            cout << "Insert the name " << endl;
                            cin>>newname;
                            cout << "Insert the type " <<endl ;
                            cin>>newtype;
                            cout << "Insert the price " << endl ;
                            cin>>price;
                            cout << "Insert the number " << endl;
                            cin>>number;
                            int modack = modifyrecord(code, newname,newtype,number,price);
                            if (modack == 0 )
                                cout << "I've done " << endl ;
                            else if (modack == -1)
                                cout << "Error while opening the database " << endl ;
                        }break;

                        case 4:
                        {
                            string code,name,type;
                            int number;
                            double price;
                            cout << " Add record " << endl;
                            cout << "Insert the code " << endl ;
                            cin>>code;
                            cout << "Insert the name " << endl ;
                            cin>>name;
                            cout << "Insert the type " << endl ;
                            cin>>type;
                            cout << "Insert the price " << endl ;
                            cin>>price;
                            cout << "Insert the number " << endl ;
                            cin>>number;
                            int addack = addrecord(code,name,type,price,number);
                            if(addack == 0)
                            {
                                cout << "I've done " << endl ;
                            }else if(addack==-1)
                                cout << " Error while opening the database " << endl ;
                        }break;

                        case 5:
                        {
                            cout << "Failure " << endl ;
                            int failack = failure();
                            if(failack==0)
                                cout << "I'm sorry your warehouse is now closed :-( " << endl;
                            else if(failack==-1)
                                cout << "Error while opening the database " << endl ;
                            else if(failack==-2)
                                cout << "Wrong password " << endl ;
                            else if(failack== -3)
                                cout << "You're not sure ? Think about it " << endl ;
                        }break;
                    }
                }break;

                case -1:
                    cout << " Error i can't access to the database " << endl ;
                break;

                case -2:
                    goto wrongpsw;
            }
        }break;///Director

        case 2:
        {
            wrongpswemp:
            string password;
            int chkack ;
            do{
                cout << " Insert your password " << endl ;
                cin>>password;
                chkack = checkpassword(password,1);
            }while(chkack!=0);
            switch(chkack)
            {
                case 0:
                {
                    sqlite3* db;
                    int ack = showFunctions(1);
                    switch(ack)
                    {
                        case 1:
                        {
                            cout << " Show all records  " << endl ;
                            int selectack = selectall();
                            if(selectack == 0)
                                cout << " I've done " << endl;
                            else    
                                cout << " Error while opening the database " << endl ;
                        }break;
                        
                        case 2:
                        {
                            string code;
                            sqlite3_stmt* stmt;
                            cout << "Delete a record " << endl;
                            cout << " Insert the code " << endl ;
                            cin>>code;
                            int delack = deleteRecord(code);
                            if(delack==0)
                                cout <<"Ok I've done"<<endl;
                            else if(delack==-1)
                                cout <<"Error while opening the database " << endl;
                        }break;

                        case 3:
                        {
                            string newname, newtype,code;
                            int number;
                            double price;
                            cout << "Modify a record " << endl ;
                            cout << "Insert the code of the record which you want to modify";
                            cin>>code;
                            cout << "Insert the name " << endl;
                            cin>>newname;
                            cout << "Insert the type " <<endl ;
                            cin>>newtype;
                            cout << "Insert the price " << endl ;
                            cin>>price;
                            cout << "Insert the number " << endl;
                            cin>>number;
                            int modack = modifyrecord(code, newname,newtype,number,price);
                            if (modack == 0 )
                                cout << "I've done " << endl ;
                            else if (modack == -1)
                                cout << "Error while opening the database " << endl ;
                        }break;

                        case 4:
                        {
                            string code,name,type;
                            int number;
                            double price;
                            cout << " Add record " << endl;
                            cout << "Insert the code " << endl ;
                            cin>>code;
                            cout << "Insert the name " << endl ;
                            cin>>name;
                            cout << "Insert the type " << endl ;
                            cin>>type;
                            cout << "Insert the price " << endl ;
                            cin>>price;
                            cout << "Insert the number " << endl ;
                            cin>>number;
                            int addack = addrecord(code,name,type,price,number);
                            if(addack == 0)
                            {
                                cout << "I've done " << endl ;
                            }else if(addack==-1)
                                cout << " Error while opening the database " << endl ;
                        }break;

                        case 5:
                        {
                            string code;
                            cout << " Insert the code for the product that has been sold " << endl;
                            cin>>code;
                            sell(code);
                        }break;
                    }
                }break;

                case -1:
                    cout << " Error i can't access to the database " << endl ;
                break;
            }   
        }break;//Employee

        case 3:
        {
            sqlite3* db;
            int ack = showFunctions(2);
            switch(ack)
            {
                case 1:
                {
                    cout << " Show all records  " << endl ;
                    int selectack = selectall();
                    if(selectack == 0)
                        cout << " I've done " << endl;
                    else    
                        cout << " Error while opening the database " << endl ;
                }break;
                
                case 2:
                {
                    string code;
                    cout << " Do you want to buy a product ? " << endl ;
                    cout << " Insert the code " << endl ;
                    cin>>code;
                    int buyack = buy(code);
                    if(buyack == 0)
                        cout <<"I've done " << endl ;
                    else if(buyack==-1)
                        cout << "Error while opening the database " << endl ;
                }break;
            }
        }break;//Customer
    }
}