#include <iostream>
#include "datatype.h"
void setCommodityInfo(CommodityInfo *pCommodity){
    fflush(stdin);
    cout<<" ������Ʒ���ƣ�";
    getline(cin,pCommodity->name);
    cout<<" ������Ʒ�۸�";
    cin>>pCommodity->price;
    cout<<" ������Ʒ������";
    cin>>pCommodity->num;
    cout<<" ������Ʒ�ۿۣ�";
    cin>>pCommodity->dicount;
}

CommodityInfo* findCommodityById(CommodityInfo *pCommodities,int num,long id){
    CommodityInfo *pCommodity=pCommodities;
    for(;pCommodity < pCommodities+num;pCommodity++){
        if(pCommodity->id==id){
            return pCommodity;
        }
    }
    return nullptr;
}

double getCommodityPrice(CommodityInfo *pCommodity){
    return pCommodity->price*pCommodity->num*pCommodity->dicount;
}

void showCommodityInfo(CommodityInfo *pCommodity){
    cout<<"��Ʒ���(id):"<<pCommodity->id<<endl;
    cout<<"   ��Ʒ����:"<<pCommodity->name<<endl;
    cout<<"   ��Ʒ�ܼ�:"<<getCommodityPrice(pCommodity)
        <<"���۸�:"<<pCommodity->price<<"������:"
        <<pCommodity->num<<"���ۿ�:"<<pCommodity->dicount<<"��\n";
}