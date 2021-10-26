#ifndef DATATYPE_H
#define DATATYPE_H
#include <string>
struct CommodityInfo{
    long id;    //商品编号
    std::string name;   //商品名称，头文件中避免使用using namespace std
    double price;   //定价
    int num;    //数量
    double dicount; //折扣
};
const int MAX_COMMODITY_NUM=100;
#endif // DATATYPE_H
