/*************************************************************************
	> File Name: testDB.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/19 20:24:18 2016
 ************************************************************************/

#include <iostream>
#include "DBdriverpgsql.h"

using namespace std;

int main() {
    DBdriverpgsql db;
    db.connectDatabaseQuery("", 0 );
    return 0;
}
