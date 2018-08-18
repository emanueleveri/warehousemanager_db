#include <iostream>
using namespace std;

int checkpassword(string password, int id);
int login();
int showFunctions(int id);
static int callback(void *NotUsed, int argc, char **argv, char **azColName);
int selectall();
int addrecord(string code, string name, string type, int number, double price);
int deleteRecord(string code);
int modifyrecord(string code, string name,string type,int number,double price);