#ifndef FUNCTION_H
#define FUNCTION_H
#include "commodityManage.h"
char menu();
void doAddCommodity(CommodityManage& cm);
void doRemoveCommodity(CommodityManage& cm);
void doModifyCommodity(CommodityManage& cm);
void doViewCommodity(const CommodityManage& cm);
void doViewAllCommodity(const CommodityManage& cm);
void doCheckout(const CommodityManage& cm);
#endif // FUNCTION_H
