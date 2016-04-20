/*************************************************************************
	> File Name: DBdriverpqsql.cpp
	> Author: lifu 
	> Mail: lifunudt@163.cpp
	> Created Time: 二  4/19 20:22:20 2016
 ************************************************************************/

#include<iostream>
#include "DBdriverpgsql.h"

using namespace std;

DBdriverpgsql::DBdriverpgsql() {

}

DBdriverpgsql::~DBdriverpgsql() {

}

bool DBdriverpgsql::connectDatabaseQuery(const std::string &url, bool overwirtten ) {
    try{
        pqxx::connection C("dbname=testdb user=postgres password=liguangye \
        hostaddr=127.0.0.1 port=5432");
        if (C.is_open()) {
            cout << "Opened database successfully: " << C.dbname() << endl;
        } else {
            cout << "Can't open database" << endl;
            return 1;
        }
        C.disconnect ();
    }catch (const std::exception &e){
        cerr << e.what() << std::endl;
        return 1;
    }
}   
   

