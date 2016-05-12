/*************************************************************************
	> File Name: testDB.cpp
	> Author: lifu
	> Mail: lifunudt@163.com
	> Created Time: 二  4/19 20:24:18 2016
 ************************************************************************/

#include <iostream>
#include <string>
//#include "datatype.h"
#include "DBdriverpq.h"

using namespace std;

int main() {
    DBdriverpq db;
    const string url = "";
    
    db.connectDatabaseQuery( url, 0 );
    
    printf( "the connect stats is : %d\n",(int)db.isConnectedQuery());
    
    std::string sql = " create table testnoresultexe ( id int primary key, age int ) ;";

    db.executeNoResultQuery( sql );
    
    sql = " insert into testnoresultexe(id, age) values( 1,22 );";

    db.executeNoResultQuery( sql );

    //test the func:getDatabaseVersionQuery 
    
    string dbversion = "";

    db.getDatabaseVersionQuery( dbversion );

    cout<<"the dbversion is :"<<dbversion<<endl;

    //test loadnode
    
    sql = " create table data ( id int primary key, mapid int, stamp float, weight int ) ;";

    db.executeNoResultQuery( sql );

    sql = " insert into data (id, mapid, stamp, weight) values( 1, 2, 3.4, 5 );";

    db.executeNoResultQuery( sql );

    sql = " insert into data (id, mapid, stamp, weight) values( 2, 3, 4.5, 6 );";

    db.executeNoResultQuery( sql );

    std::list<Signature *> sigs;
    Signature t_sig1, t_sig2;
    t_sig1.id = 1;
    sigs.push_back( &t_sig1 );
    t_sig2.id = 2;
    sigs.push_back( &t_sig2 );


    db.loadNodeDataQuery( sigs );

    sql = " drop table data ; ";
    db.executeNoResultQuery( sql );

    db.disconnectDatabaseQuery();
    printf( "the connect stats is : %d\n",(int)db.isConnectedQuery());
    return 0;
}
