#ifndef HELP_H
#define HELP_H
#include "datatype.h"
int findCommodityById(CommodityInfo *pCommodities,int num,long id);
void showCommodityInfo(CommodityInfo *pCommodity);
void setCommodityInfo(CommodityInfo *pCommodity);
double getCommodityPrice(CommodityInfo *pCommodity);
void reAllocMemory(CommodityInfo* &pCommodities,int num);
void sortCommodity(CommodityInfo* &pCommodities,int num);
bool cmpById(CommodityInfo a,CommodityInfo b);
bool cmpByPrice(CommodityInfo a,CommodityInfo b);
bool cmpByDiscount(CommodityInfo a,CommodityInfo b);
bool cmpByName(CommodityInfo a,CommodityInfo b);
bool cmpByTotalPrice(CommodityInfo a,CommodityInfo b);
#endif // HELP_H
