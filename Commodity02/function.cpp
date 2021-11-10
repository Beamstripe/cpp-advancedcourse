#include <iostream>
#include <fstream>
#include "header.h"
char menu(){
    using std::cout;
    using std::cin;
    cout<<"  0)退出系统\n";
    cout<<"  1)向购物篮添加商品\n";
    cout<<"  2)从购物篮移除商品\n";
    cout<<"  3)查看指定商品\n";
    cout<<"  4)查看所有商品\n";
    cout<<"  5)结算\n";
    cout<<"请输入功能选项：\n";
    char choice;
    cin>>choice;
    return choice;
}
void viewCommodity(CommodityInfo *pCommodities, int num){
    using std::cout;
    using std::endl;
    cout<<"  商品名称\t\t价格\t件数\t折扣\t总价\n";
    cout<<"  "<<pCommodities->name<<'\t'
        <<pCommodities->price<<'\t'
        <<pCommodities->num<<'\t'
        <<pCommodities->discount<<'\t'
        <<getCommodityPrice(pCommodities)<<'\t';
}

void displayCommodities(CommodityInfo *pCommodities, int num){
    using std::cout;
    using std::cin;
    using std::endl;
    int i;
    cout<<"商品种类："<<num<<endl;
    for(i=0;i<num;i++){
        showCommodityInfo(&pCommodities[i]);
    }
    cout<<endl;
}
void addCommodity(CommodityInfo* &pCommodities, int &num){
    using std::cout;
    using std::cin;
    long id;
    cout<<"  输入商品编号(id)：";
    cin>>id;
    int pos = findCommodityById(pCommodities,num,id);
    if(pos!=-1){
        cout<<"编号为"<<id<<"的商品已经存在！\n";
        cout<<"请输入增加的商品数量：";
        int number;
        cin>>number;
        pCommodities[pos].num+=number;
        return;
    }
    if(num==maxCommodityNum){
        reAllocMemory(pCommodities,num);
    }
    CommodityInfo* pCommodity = &pCommodities[num];
    pCommodity->id=id;
    setCommodityInfo(pCommodity);
    num++;
    cout<<"商品添加成功！\n\n";
}
void removeCommodity(CommodityInfo *pCommodities, int &num){
    using std::cout;
    using std::cin;
    using std::endl;
    long id;
    cout<<"  输入商品编号(id)：";
    cin>>id;
    int pos = findCommodityById(pCommodities,num,id);
    if(pos==-1){
        cout<<"编号为"<<id<<"的商品不存在！\n";
        return;
    }
    num--;
    CommodityInfo* pCommodity = pCommodities+pos;
    CommodityInfo *pNext = pCommodity+1;
    while (pCommodity < pCommodities + num) {
        pCommodity->id=pNext->id;
        pCommodity->name=pNext->name;
        pCommodity->price=pNext->price;
        pCommodity->discount=pNext->discount;
        pCommodity++;
        pNext++;
    }
    showCommodityInfo(pCommodity);
    cout<<endl;
}
void checkOut(CommodityInfo *pCommodities, int num){
    using std::cout;
    using std::cin;
    using std::endl;
    double totalPrice=0;
    int totalNum=0;
    cout<<"商品种类："<<num<<endl;
    cout<<"  商品名称\t\t价格\t件数\t折扣\t总价\n";
    for(int i=0;i<num;i++){
        double price=getCommodityPrice(pCommodities+i);
        cout<<"  "<<pCommodities[i].name<<'\t'
            <<pCommodities[i].price<<'\t'
            <<pCommodities[i].num<<'\t'
            <<pCommodities[i].discount<<'\t'
            <<price<<'\t';
        totalPrice+=price;
        totalNum+=pCommodities[i].num;
    }
    cout<<"购物篮商品总件数："<<totalNum<<"\n";
    cout<<"购物篮结算总价："<<totalPrice<<endl;
}
void readData(CommodityInfo *&pCommodities,char* filename){
    std::ifstream in(filename);
    if(in){
        in>>maxCommodityNum;
        pCommodities=new CommodityInfo[maxCommodityNum];
        in>>commodityNum;
        if(commodityNum>maxCommodityNum)
            commodityNum=maxCommodityNum;
        std::string buf;
        for(int i=0;i<commodityNum;i++){
            in>>pCommodities[i].id;
            std::getline(in,buf);
            std::getline(in,pCommodities[i].name);
            in>>pCommodities[i].price>>pCommodities[i].num
              >>pCommodities[i].discount;
        }
    }
}
void writeData(CommodityInfo *&pCommodities,char *filename){
    using std::endl;
    std::ofstream out(filename);
    if(out){
        out<<maxCommodityNum<<endl;
        out<<commodityNum<<endl;
        for(int i=0;i<commodityNum;i++){
            out<<pCommodities[i].id<<endl;
            out<<pCommodities[i].name<<endl;
            out<<pCommodities[i].price<<' '<<pCommodities[i].num
               <<' '<<pCommodities[i].discount<<endl;
        }
    }
}
void modifyCommodity(CommodityInfo *&pCommodities, int num){
    using std::cout;
    using std::cin;
    long id;
    cout<<"  输入商品编号:";
    cin>>id;
    int pos = findCommodityById(pCommodities,num,id);
    if(pos!=-1){
        CommodityInfo* commodity = pCommodities+pos;
        setCommodityInfo(commodity);
        cout<<"  商品修改成功！\n";
    }else{
        char option;
        cout<<"需要添加此商品吗？(y/n)";
        cin>>option;
        if(option=='y'){
            addCommodity(pCommodities,num);
        }
    }
}
