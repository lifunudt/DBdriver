/*************************************************************************
	> File Name: DBdriverpq.h
	> Author: lifu 
	> Mail: lifunudt@163.com
	> Created Time: 二  4/19 19:42:22 2016
 ************************************************************************/

#ifndef _DBDRIVERPQ_H
#define _DBDRIVERPQ_H
#endif

#include <iostream>
#include <cstring>
#include "libpq-fe.h"

using namespace std;

class DBdriverpq {
public:
    DBdriverpq();
    ~DBdriverpq();
    virtual bool connectDatabaseQuery(const std::string & url, bool overwirtten = false);
    
private:
   const char * conn_pq_info;
   PGconn * conn_pq;
};
