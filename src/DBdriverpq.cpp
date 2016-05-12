/*************************************************************************
	> File Name: DBdriverpq.cpp
	> Author: lifu 
	> Mail: lifunudt@163.cpp
	> Created Time: 二  4/19 20:22:20 2016
 ************************************************************************/
#include <sstream>
#include <iostream>
#include "DBdriverpq.h"

using namespace std;

DBdriverpq::DBdriverpq() {
    conn_pq_info = new char[100];
}

DBdriverpq::~DBdriverpq() {

}
/**
 *@param:
 *@param:
 *@return:
 */
bool DBdriverpq::connectDatabaseQuery(  const std::string &url, bool overwirtten ) {
    std::string default_con = "hostaddr = 127.0.0.1 port = 5432 dbname = testdb user = postgres password = liguangye";
    if ( url != "" ) {
        strcpy( conn_pq_info , url.c_str());
    }
    else{
        strcpy( conn_pq_info , default_con.c_str() );
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

bool DBdriverpq::isConnectedQuery() {
    //return the status of the connect 
    return PQstatus( conn_pq ) == CONNECTION_OK;

}
void DBdriverpq::executeNoResultQuery( std::string & sql) {
    if( isConnectedQuery() )
    {
        PQexec( conn_pq, sql.c_str() );
        if ( strcmp ( PQerrorMessage( conn_pq ) , ""  ) == 1 )
            cout <<"--DBdriverpq::executeNoResultQuery:  "<<PQerrorMessage( conn_pq )<<endl;
    }
    else {
        printf("-DBdriverpq::executeNoResultQuery: no connection to the database\n");
    }
}
long DBdriverpq::getMemoryUsedQuery() {
   
    return 0; 
}

/*
 *@param: version
 *@func: used to get the version of the postgersql database  
 */
bool DBdriverpq::getDatabaseVersionQuery(std::string & version){
    char paramName[ 50 ] = "server_version";
    version = "";
    
    if ( isConnectedQuery() ) {

        //use the func to get the version of the postgresql
        version = PQparameterStatus( conn_pq, paramName );
    
    } else {
        printf("-DBdriverpq::getDatabaseVersionQuery: no connection to the database\n");       
    }
    
    return version == "";
}

long DBdriverpq::getImagesMemoryUsedQuery() {
   //TODO
   return 0; 
}
long DBdriverpq::getDepthImagesMemoryUsedQuery(){
    //TODO
   return 0; 
}
long DBdriverpq::getLaserScansMemoryUsedQuery() {
    //TODO
   return 0; 
}
long DBdriverpq::getUserDataMemoryUsedQuery(){
    //TODO

   return 0; 
}
long DBdriverpq::getWordsMemoryUsedQuery(){
    //TODO

   return 0; 
}
int DBdriverpq::getLastNodesSizeQuery() {
    //TODO

   return 0; 
}
int DBdriverpq::getLastDictionarySizeQuery(){

   return 0; 
}
int DBdriverpq::getTotalNodesSizeQuery(){

   return 0; 
}
int DBdriverpq::getTotalDictionarySizeQuery(){
    
   return 0;
}
void DBdriverpq::getWeightQuery(int signatureId, int & weight){

}

std::string DBdriverpq::queryStepNode() {
    return "INSERT INTO Node(id, map_id, weight, pose, stamp, label) VALUES($1, $2, $3, $4, $5, $6)";
}

PGresult *DBdriverpq::stepNode( const char pqstmt[], Signature *s ) {
    PGresult *res;


    return res;
} 
void DBdriverpq::saveQuery(  std::list<Signature *> & signatures){
    
    cout<<"--Dbdriver::saveQuery: start"<<endl;
    //there is no error
    if ( isConnectedQuery() && signatures.size() ) {
        
        std::string type;
        const char pqstmt[] = "saveQuery";
        PGresult *res;
        int nParams;

        //Signature table
        std::string query = queryStepNode();
        nParams = 6;
        res = PQprepare( conn_pq, pqstmt, query.c_str(), nParams, NULL );

        for ( std::list<Signature *>::const_iterator i = signatures.begin(); i != signatures.end() ; i++ ) {
            stepNode( pqstmt, *i );
        }

        PQclear( res );


        //Link table
        
        query = queryStepLink();
        for( std::list<Signature *>::const_iterator jter = signatures.begin(); jter != signatures.end(); ++jter ) {
            
        }

    } else {
        //error 
        if ( !isConnectedQuery() )
            cout<<"--DBdriverpq::saveQuery: no connection to the DB"<<endl;
        else
            cout<<"--DBdriverpq::saveQuery: there is no sigature"<<endl;
    }
    
    cout<<"--Dbdriver::saveQuery: end"<<endl;


}
void DBdriverpq::saveQuery(  std::list<VisualWord *> & words){
    
}
void DBdriverpq::updateQuery(  std::list<Signature *> & signatures, bool updateTimestamp){

}
void DBdriverpq::updateQuery(  std::list<VisualWord *> & words, bool updateTimestamp){

}
void DBdriverpq::addLinkQuery(  Link & link){
    
}
void DBdriverpq::updateLinkQuery(  Link & link) {

}
// Load objects
void DBdriverpq::loadQuery(VWDictionary * dictionary){
    
}
void DBdriverpq::loadLastNodesQuery(std::list<Signature *> & signatures){

}
void DBdriverpq::loadSignaturesQuery(  std::list<int> & ids, std::list<Signature *> & signatures){

}
void DBdriverpq::loadWordsQuery(  std::set<int> & wordIds, std::list<VisualWord *> & vws){
    
}
void DBdriverpq::loadLinksQuery(int signatureId, std::map<int, Link> & links) { 
    //TODO:changed the param
    //, Link::Type type = Link::kUndef){

}

/*
 *@param: std::list<Signature *>
 *@func: from the database load the signatures acording the signatureIds 
 */
void DBdriverpq::loadNodeDataQuery(std::list<Signature *> & signatures) {
    PGresult *res;
    const char * paramValues[1];
    int paramLengths[1];
    int paramFormats[1]; 
    int nParams = 1;

    if( !isConnectedQuery() ) {
        printf( "-DBdriverpq::loadNodeDataQuery : no database conncection\n" );
        return ;
    }

    const char pqstmt[] = "loadNodeDataQuery"; 
    
    //generate the search SQL string
    std::stringstream query;
    //query << "SELECT image, depth, calibration, scan_max_pts, scan_max_range, scan, user_data  "
    query << "SELECT mapid, stamp, weight "
        << "FROM data "
        << "WHERE id = $1 "
        << ";";
    
    //prepare the PQ exec use the SQL string 
    nParams = 1;

    res = PQprepare(conn_pq, pqstmt, query.str().c_str(), nParams, NULL );
    
    cout <<  PQerrorMessage( conn_pq ) << endl;

    const void * data = 0;
    int dataSize = 0;
    int index = 0;

    //for every signature in the Signatures, get its data from the db
    for(std::list<Signature*>::iterator iter = signatures.begin(); iter!=signatures.end(); ++iter) {
        std::stringstream param;
        param << (*iter)->id;
        paramValues[0] = param.str().c_str(); 
        res = PQexecPrepared( conn_pq, pqstmt, nParams, paramValues, NULL, NULL, 0 );
        
        // if occur some error
        if ( PQresultStatus( res ) != PGRES_TUPLES_OK ) {
            printf( "--DBdriverpq::loadNodeDataQuery: exec failed: %s\n", PQerrorMessage(conn_pq) );
            PQclear( res );
            //exit_nicely( conn_pq );
            continue;
        }
        
        //parse the exec result
        
        int ntuples = PQntuples( res );
        int nfields = PQnfields( res );
        
        if ( ntuples > 1 ) {
            printf("--DBdriverpq::loadNodeDataQuery: result have multy tuples\n");
        }
        else if ( ntuples < 1 ){
            printf("--DBdriverpq::loadNodeDataQuery: result have no tuple\n");
        }
        else {
            //paras the tuple to generate the new signature
            Signature t_sig;
            t_sig.id = (*iter)->id;
            cout << "result is: \n";
            for ( int i = 0; i < nfields; i++ )
                cout << PQgetvalue( res, 0, i ) << endl;
        }
    }
    return ;
}

bool DBdriverpq::getNodeInfoQuery(int signatureId, Transform & pose, int & mapId, int & weight, std::string & label, double & stamp){
    
   return 0;
}
void DBdriverpq::getAllNodeIdsQuery(std::set<int> & ids, bool ignoreChildren, bool ignoreBadSignatures) {

}
void DBdriverpq::getAllLinksQuery(std::multimap<int, Link> & links, bool ignoreNullLinks){

}
void DBdriverpq::getLastIdQuery(  std::string & tableName, int & id){
    
}
void DBdriverpq::getInvertedIndexNiQuery(int signatureId, int & ni) {

}
void DBdriverpq::getNodeIdByLabelQuery(  std::string & label, int & id) {

}
void DBdriverpq::getAllLabelsQuery(std::map<int, std::string> & labels) {
    
}


