#include <iostream>
#include <algorithm>
#include "header.h"
void reAllocMemory(CommodityInfo *&pCommodities, int num){
    ++maxCommodityNum;
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
void showCommodityInfo(int position){
    using std::cout;
    using std::cin;
    using std::endl;
    CommodityInfo* pCommodity=pCommodities+position;
    cout<<"商品编号(id):"<<pCommodities[position].id<<endl;
    cout<<"   商品名称:"<<pCommodities[position].name<<endl;
    cout<<"   商品总价:"<<getCommodityPrice(pCommodity)
        <<"（价格:"<<pCommodities[position].price<<"，数量:"
        <<pCommodities[position].num<<"，折扣:"<<pCommodities[position].discount<<"）\n";
}
void sortCommodity(CommodityInfo *&pCommodities, int num,char choice){
    using std::cout;
    using std::cin;
    using std::endl;
    using std::sort;
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
    if(sortType=='1')
        return a.id<b.id;
    else
        return a.id>b.id;
}
bool cmpByName(CommodityInfo a, CommodityInfo b){
    if(sortType=='1')
        return a.name<b.name;
    else
        return a.name>b.name;
}
bool cmpByPrice(CommodityInfo a, CommodityInfo b){
    if(sortType=='1')
        return a.price<b.price;
    else
        return a.price>b.price;
}
bool cmpByDiscount(CommodityInfo a, CommodityInfo b){
    if(sortType=='1')
        return a.discount<b.discount;
    else
        return a.discount>b.discount;
}
bool cmpByTotalPrice(CommodityInfo a, CommodityInfo b){
    if(sortType=='1')
        return getCommodityPrice(&a)<getCommodityPrice(&b);
    else
        return getCommodityPrice(&a)>getCommodityPrice(&b);
}
