#include "Commodity.h"
#include "commodityManage.h"
#include "NormalCommodity.h"
#include "OverseaCommodity.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
CommodityManage::~CommodityManage(){
    for(auto e:pCommodities)
        delete e;
}

const Commodity* CommodityManage::findCommodityById(int id)const{
    for(auto e : pCommodities)
        if(e->getId()==id)
            return e;
    return nullptr;
}
Commodity* CommodityManage::findCommodityById(int id){
    for(auto e : pCommodities)
        if(e->getId()==id)
            return e;
    return nullptr;
}
void CommodityManage::addCommodity(Commodity *p){
    Commodity* pCommodity=findCommodityById(p->getId());
    if(pCommodity!=nullptr){
        cout<<"编号为"<<c.getId()<<"的商品已经存在!累加其数量\n";
        pCommodity->setNum(pCommodity->getNum()+p->getNum());
        return;
    }
    pCommodities.push_back(p);
}
void CommodityManage::removeCommodity(int id){
    Commodity* pCommodity=findCommodityById(id);
    if(pCommodity==nullptr){
        cout<<"编号为"<<id<<"的商品不存在!\n";
        return;
    }
    delete pCommodity;
    pCommodities.erase(getIterator(pCommodity));
}
void CommodityManage::viewCommodity(int id)const{
    const Commodity* pCommodity=findCommodityById(id);
    if(pCommodity==nullptr){
        cout<<"编号为"<<id<<"的商品不存在!\n";
        return;
    }
    pCommodity->output();
}
void CommodityManage::viewAllCommodities()const{
    cout<<"商品种类:"<<size<<endl;
    for(auto e:pCommodities)
        e->output();
}
void CommodityManage::checkOut()const{
    double totalPrice=0;
    int totalNum=0;
    cout<<"商品种类: "<<pCommodities.size()<<endl;
    cout<<" 商品名称\t\t"<<"价格\t"<<"件数\t"<<"折扣\t"<<"总价\n";
    for(auto e : pCommodities){
        double price=e->getNetPrice();
        cout<<" "<<e->getName()<<"\t";
        cout<<e->getPrice()<<"\t"
           <<e->getNum()<<"\t"
          <<price<<endl;
        totalPrice+=price;
        totalNum+=e->getNum();
    }
    cout<<"购物篮商品总件数: "<<totalNum<<"\n";
    cout<<"购物篮结算总价: "<<totalPrice<<endl;
}
vector<Commodity*>::iterator CommodityManage::getIterator(Commodity* p){
    for(auto it=pCommodities.begin();it!=pCommodities.end();++it)
        if(*it==p)
            return it;
    return pCommodities.end();
}
void CommodityManage::saveData(char* filename){
    ofstream out(filename);
    if(out){
        out<<pCommodities.size()<<endl;
        out<<Commodity::getNextId()<<endl;
        for(auto e:pCommodities){
            out<<e->getInfo();
        }
    }
}
void CommodityManage::readData(char *filename){
    ifstream in(filename);
    if(in){
        int fileSize;
        long nextId;
        in>>fileSize>>nextId;
        Commodity::setNextId(nextId);
        int type;
        double tariff;
        in>>fileMax>>fileSize;
        long id;
        string name,buf;
        double price,discount;
        int num;
        for(int i=0;i<fileSize;++i){
            in>>type;
            in>>id;
            getline(in,buf); //读取 id 后残留的回车要读到 buf 中
            getline(in,name);
            in>>price>>num;
            if(type==0){
                in>>discount;
                addCommodity(new
                             NormalCommodity(id,name,price,num,discount));
            }
            else if(type==1){
                in>>discount>>tariff;
                addCommodity(new
                             OverseaCommodity(id,name,price,num,discount,tariff));
            }
        }
    }
}
