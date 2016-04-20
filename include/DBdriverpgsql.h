/*************************************************************************
	> File Name: DBdriverpgsql.h
	> Author: 
	> Mail: 
	> Created Time: 二  4/19 19:42:22 2016
 ************************************************************************/

#ifndef _DBDRIVERPGSQL_H
#define _DBDRIVERPGSQL_H
#endif

#include <iostream>
#include <pqxx/pqxx>
#include <cstring>

using namespace std;

class DBdriverpgsql {
public:
    DBdriverpgsql();
    ~DBdriverpgsql();
    virtual bool connectDatabaseQuery(const std::string & url, bool overwirtten = false);

private:
};
