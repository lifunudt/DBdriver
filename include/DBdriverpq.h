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
#include <list>
#include <set>
#include <map>
#include <cstring>
#include "libpq-fe.h"
#include "datatype.h"

using namespace std;

class DBdriverpq {
public:
    DBdriverpq();
    ~DBdriverpq();
    virtual bool connectDatabaseQuery(  const std::string & url, bool overwirtten = false);
    virtual bool disconnectDatabaseQuery();
    virtual bool isConnectedQuery();
    virtual void executeNoResultQuery(  std::string & sql);
    virtual long getMemoryUsedQuery();

    virtual bool getDatabaseVersionQuery(std::string & version)  ;
    virtual long getImagesMemoryUsedQuery()  ;
    virtual long getDepthImagesMemoryUsedQuery()  ;
    virtual long getLaserScansMemoryUsedQuery()  ;
    virtual long getUserDataMemoryUsedQuery()  ;
    virtual long getWordsMemoryUsedQuery()  ;
    virtual int getLastNodesSizeQuery()  ;
    virtual int getLastDictionarySizeQuery()  ;
    virtual int getTotalNodesSizeQuery()  ;
    virtual int getTotalDictionarySizeQuery()  ;
    virtual void getWeightQuery(int signatureId, int & weight)  ;
    virtual void saveQuery(  std::list<Signature *> & signatures)  ;
    virtual void saveQuery(  std::list<VisualWord *> & words)  ;
    virtual void updateQuery(  std::list<Signature *> & signatures, bool updateTimestamp)  ;
    virtual void updateQuery(  std::list<VisualWord *> & words, bool updateTimestamp)  ;
    virtual void addLinkQuery(  Link & link)  ;
    virtual void updateLinkQuery(  Link & link)  ;
    // Load objects
    virtual void loadQuery(VWDictionary * dictionary)  ;
    virtual void loadLastNodesQuery(std::list<Signature *> & signatures)  ;
    virtual void loadSignaturesQuery(  std::list<int> & ids, std::list<Signature *> & signatures)  ;
    virtual void loadWordsQuery(  std::set<int> & wordIds, std::list<VisualWord *> & vws)  ;
    virtual void loadLinksQuery(int signatureId, std::map<int, Link> & links) ; //, Link::Type type = Link::kUndef)  ;
    virtual void loadNodeDataQuery(std::list<Signature *> & signatures)  ;
    virtual bool getNodeInfoQuery(int signatureId, Transform & pose, int & mapId, int & weight, std::string & label, double & stamp)  ;
    virtual void getAllNodeIdsQuery(std::set<int> & ids, bool ignoreChildren, bool ignoreBadSignatures)  ;
    virtual void getAllLinksQuery(std::multimap<int, Link> & links, bool ignoreNullLinks)  ;
    virtual void getLastIdQuery(  std::string & tableName, int & id)  ;
    virtual void getInvertedIndexNiQuery(int signatureId, int & ni)  ;
    virtual void getNodeIdByLabelQuery(  std::string & label, int & id)  ;
    virtual void getAllLabelsQuery(std::map<int, std::string> & labels)  ;

private:
    char * conn_pq_info;
    PGconn * conn_pq;
};
