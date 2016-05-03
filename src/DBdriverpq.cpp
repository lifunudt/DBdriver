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
        //cout<<"default:"<<default_con.c_str() <<endl;
        //cout<<"conn_pq:"<<conn_pq_info<<endl;
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
    version = PQparameterStatus( conn_pq, paramName );
    if ( version == "")
        return false;
    else 
        return true;
}
long DBdriverpq::getImagesMemoryUsedQuery() {

   return 0; 
}
long DBdriverpq::getDepthImagesMemoryUsedQuery(){

   return 0; 
}
long DBdriverpq::getLaserScansMemoryUsedQuery() {

   return 0; 
}
long DBdriverpq::getUserDataMemoryUsedQuery(){

   return 0; 
}
long DBdriverpq::getWordsMemoryUsedQuery(){

   return 0; 
}
int DBdriverpq::getLastNodesSizeQuery() {
    
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
void DBdriverpq::loadNodeDataQuery(std::list<Signature *> & signatures) {

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


