#ifndef FUNCTION_H
#define FUNCTION_H
#include "header.h"
char menu();
void displayCommodities(CommodityInfo *pCommodities, int num);
void addCommodity(CommodityInfo* &pCommodities,int& num);
void removeCommodity(CommodityInfo *pCommodities,int& num);
void viewCommodity(CommodityInfo *pCommodities,int num);
void checkOut(CommodityInfo *pCommodities,int num);
void readData(CommodityInfo *&pCommodities, char *filename);
void writeData(CommodityInfo *&pCommodities,char *filename);
void modifyCommodity(CommodityInfo* &pCommodities,int& num);
#endif // FUNCTION_H
