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
    return PQstatus( conn_pq );

}
void DBdriverpq::executeNoResultQuery( std::string & sql) {
    if( isConnectedQuery()== CONNECTION_OK )
    {
        PQexec( conn_pq, sql.c_str() );
    }
    else {
        printf("-DBdriverpq::executeNoResultQuery: no connection to the database\n");
    }
}
long DBdriverpq::getMemoryUsedQuery() {
   
    return 0; 
}
bool DBdriverpq::getDatabaseVersionQuery(std::string & version){
    char paramName[ 50 ] = "server_version";
    version = "";
    if ( isConnectedQuery() == CONNECTION_OK  ) {
        version = PQparameterStatus( conn_pq, paramName );
    }
    else {
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
void DBdriverpq::saveQuery(  std::list<Signature *> & signatures){

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
    
    if( !isConnectedQuery() ) {
        printf( "-DBdriverpq::loadNodeDataQuery : no database conncection\n" );
        return ;
    }

    const char pqstmt[] = "loadNodeDataQuery"; 
    std::stringstream query;
    query << "SELECT image, depth, calibration, scan_max_pts, scan_max_range, scan, user_data  "
        << "FROM data "
        << "WHERE id = $1 "
        << ";";
    PGresult *res;
    int nParams = 1;
    res = PQprepare(conn_pq, pqstmt, query.str().c_str(), nParams, NULL );
    const void * data = 0;
    int dataSize = 0;
    int index = 0;

    //for every signature in the Signatures, get its data from the db
    for(std::list<Signature*>::iterator iter = signatures.begin(); iter!=signatures.end(); ++iter) {
        
    }


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


