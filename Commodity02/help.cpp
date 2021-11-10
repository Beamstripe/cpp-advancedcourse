#include <iostream>
#include <algorithm>
#include "header.h"
void reAllocMemory(CommodityInfo *&pCommodities, int num){
    maxCommodityNum*=2;
    CommodityInfo *temp=pCommodities;
    pCommodities=new CommodityInfo[maxCommodityNum];
    for(int i=0;i<num;i++){
        pCommodities[i]=temp[i];
    }
    delete[] temp;
}

void setCommodityInfo(CommodityInfo *pCommodity){
    using std::cout;
    using std::cin;
    fflush(stdin);
    cout<<" 输入商品名称：";
    getline(cin,pCommodity->name);
    cout<<" 输入商品价格：";
    cin>>pCommodity->price;
    cout<<" 输入商品数量：";
    cin>>pCommodity->num;
    cout<<" 输入商品折扣：";
    cin>>pCommodity->discount;
}
/*
CommodityInfo* findCommodityById(CommodityInfo *pCommodities,int num,long id){
    CommodityInfo *pCommodity=pCommodities;
    for(;pCommodity < pCommodities+num;pCommodity++){
        if(pCommodity->id==id){
            return pCommodity;
        }
    }
    return nullptr;
}
*/
//Modification of findCommodityById
int findCommodityById(CommodityInfo *pCommodities,int num,long id){
    CommodityInfo *pCommodity=pCommodities;
    int pos=0;
    for(;pCommodity < pCommodities+num;pCommodity++){
        if(pCommodity->id==id){
            return pos;
        }
        pos++;
    }
    return -1;
}


double getCommodityPrice(CommodityInfo *pCommodity){
    return pCommodity->price*pCommodity->num*pCommodity->discount;
}

void showCommodityInfo(CommodityInfo *pCommodity){
    using std::cout;
    using std::cin;
    using std::endl;
    cout<<"商品编号(id):"<<pCommodity->id<<endl;
    cout<<"   商品名称:"<<pCommodity->name<<endl;
    cout<<"   商品总价:"<<getCommodityPrice(pCommodity)
        <<"（价格:"<<pCommodity->price<<"，数量:"
        <<pCommodity->num<<"，折扣:"<<pCommodity->discount<<"）\n";
}
void sortCommodity(CommodityInfo *&pCommodities, int num){
    using std::cout;
    using std::cin;
    using std::endl;
    using std::sort;
    cout<<"请输入排序方式："<<endl;
    cout<<"  1)按商品编号排序："<<endl;
    cout<<"  2)按商品名称排序："<<endl;
    cout<<"  3)按商品价格排序："<<endl;
    cout<<"  4)按商品折扣排序："<<endl;
    cout<<"  5)按商品总价排序："<<endl;
    char choice;
    cin>>choice;
    switch(choice){
    case '1':
        sort(pCommodities,pCommodities+num,cmpById);
    break;
    case '2':
        sort(pCommodities,pCommodities+num,cmpByName);
    break;
    case '3':
        sort(pCommodities,pCommodities+num,cmpByPrice);
    break;
    case '4':
        sort(pCommodities,pCommodities+num,cmpByDiscount);
    break;
    case '5':
        sort(pCommodities,pCommodities+num,cmpByTotalPrice);
    break;
    default:
        cout<<"输入的选项非法！"<<endl;
        break;
    }
}
bool cmpById(CommodityInfo a, CommodityInfo b){
    return a.id<b.id;
}
bool cmpByName(CommodityInfo a, CommodityInfo b){
    return a.name<b.name;
}
bool cmpByPrice(CommodityInfo a, CommodityInfo b){
    return a.price<b.price;
}
bool cmpByDiscount(CommodityInfo a, CommodityInfo b){
    return a.discount<b.discount;
}
bool cmpByTotalPrice(CommodityInfo a, CommodityInfo b){
    return getCommodityPrice(&a)<getCommodityPrice(&b);
}
