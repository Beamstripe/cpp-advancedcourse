#ifndef COMMODITYMANAGE_H
#define COMMODITYMANAGE_H
#include <vector>
#include "Commodity.h"
class CommodityManage{
public:
    CommodityManage()=default;
    ~CommodityManage();
    CommodityManage(const CommodityManage& c)=delete;
    CommodityManage& operator=(const CommodityManage& c)=delete;
    void readData(char* filename);
    void saveData(char* filename);
    void reAllocMemory();
    void addCommodity(Commodity* p);
    void removeCommodity(int id);
    void viewCommodity(int id)const;
    void viewAllCommodities()const;
    void checkOut()const;
private:
    std::vector<Commodity*> pCommodities;
    Commodity *findCommodityById(int id);
    const Commodity *findCommodityById(int id)const;
    std::vector<Commodity*>::iterator getIterator(Commodity* p);
};
#endif // COMMODITYMANAGE_H
