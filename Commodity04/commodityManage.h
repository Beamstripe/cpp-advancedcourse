#ifndef COMMODITYMANAGE_H
#define COMMODITYMANAGE_H
class CommodityManage{
public:
    CommodityManage();
    CommodityManage(int s);
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
    Commodity **pCommodities; //指向动态创建的商品数组
    int maxSize; //当前分配的空间上限
    int size; //实际的商品数量
    Commodity* findCommodityById(int id)const;
};
#endif // COMMODITYMANAGE_H
