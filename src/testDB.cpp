/*************************************************************************
	> File Name: testDB.cpp
	> Author: lifu
	> Mail: lifunudt@163.com
	> Created Time: 二  4/19 20:24:18 2016
 ************************************************************************/

#include <iostream>
#include "DBdriverpq.h"

using namespace std;

int main() {
    DBdriverpq db;
    db.connectDatabaseQuery("", 0 );
    printf( "the connect stats is : %d\n",(int)db.isConnectedQuery());
    db.disconnectDatabaseQuery();
    printf( "the connect stats is : %d\n",(int)db.isConnectedQuery());
    return 0;
}
