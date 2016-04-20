/*************************************************************************
	> File Name: testDB.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/19 20:24:18 2016
 ************************************************************************/

#include <iostream>
#include "DBdriverpq.h"

using namespace std;

int main() {
    DBdriverpq db;
    db.connectDatabaseQuery("", 0 );
    return 0;
}
