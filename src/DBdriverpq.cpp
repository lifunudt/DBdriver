/*************************************************************************
	> File Name: DBdriverpq.cpp
	> Author: lifu 
	> Mail: lifunudt@163.cpp
	> Created Time: 二  4/19 20:22:20 2016
 ************************************************************************/

#include<iostream>
#include "DBdriverpq.h"

using namespace std;

DBdriverpq::DBdriverpq() {

}

DBdriverpq::~DBdriverpq() {

}
/**
 *@param:
 *@param:
 *@return:
 */
bool DBdriverpq::connectDatabaseQuery(const std::string &url, bool overwirtten ) {
    if ( url != "" )
        conn_pq_info = url.c_str();
    else{
        conn_pq_info = "hostaddr = 127.0.0.1 port = 5432 dbname = postgres user = postgres password = liguangye";
    } 
    conn_pq = PQconnectdb( conn_pq_info );
    if( PQstatus( conn_pq ) != CONNECTION_OK  ) {
        printf( "connect error! \n" );
        return false;
    }
    else{
        printf( "connect ok!\n" );
        return true;
    }
}   

bool DBdriverpq::disconnectDatabaseQuery(){
    //TODO:make sure that all statement are finished

    //TODO:put the data in memory to pgdb

    PQfinish(conn_pq);
    printf("exit from the PQDB\n");
    return 1;
}
