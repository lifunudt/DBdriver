/*************************************************************************
	> File Name: testpq.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  4/20 15:49:50 2016
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "libpq-fe.h"

using namespace std;

static void
exit_nicely(PGconn *conn)
{
    PQfinish(conn);
    exit(1);
}

int main(int argc, char **argv)
{
    const char *conninfo;
    PGconn     *conn;
    PGresult   *res;
    int         nFields;
    int         i,
    j;
    
    /*
     * 如果用户在命令行上提供了一个参数，则拿它当作 conninfo 字串使用；
     * 否则缺省为 dbname=postgres 并且使用环境变量或者所有其它连接参数
     * 都使用缺省值。
     */
    if (argc > 1)
        conninfo = argv[1];
    else
        conninfo = "dbname = postgres hostaddr = 127.0.0.1 user = postgres port = 5432 password = liguangye";
    
    /* Make a connection to the database */
    conn = PQconnectdb(conninfo);
    
    /* 检查后端连接成功建立 */
    if (PQstatus(conn) != CONNECTION_OK)
    {
        fprintf(stderr, "Connection to database failed: %s",
                PQerrorMessage(conn));
        exit_nicely(conn);
    }
    else {
        printf("connect ok\n");
    }
    
    /* 关闭数据库连接并清理 */
    PQfinish(conn);
    
    return 0;
}

