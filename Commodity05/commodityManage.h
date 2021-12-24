#ifndef COMMODITYMANAGE_H
#define COMMODITYMANAGE_H
#include <vector>
#include <string>
using namespace std;
#include "Commodity.h"
class CommodityManage{
public:
    CommodityManage()=default;
    ~CommodityManage();
    CommodityManage(const CommodityManage& c)=delete;
    CommodityManage& operator=(const CommodityManage& c)=delete;
    void addCommodity(Commodity* p);
//    void removeCommodity(int id);
//    void viewCommodity(int id)const;
    void removeCommodity(string name);
    void viewCommodity(string name)const;
    void viewAllCommodities()const;
    void checkOut()const;
    void readData(std::string filename);
    void saveData(std::string filename);
private:
    std::vector<Commodity*> pCommodities;
    Commodity* findCommodityById(int id);
    const Commodity* findCommodityById(int id)const;
    Commodity* findCommodityByName(string name);
    const Commodity* findCommodityByName(string name)const;
    std::vector<Commodity*>::iterator getIterator(Commodity* p);
    int sortType=0; //记录当前排序类型
    void sortCommodities();
    void sortCommoditiesByType(int type);
};
#endif // COMMODITYMANAGE_H
