#include "ticketmanage.h"
#include "function.h"
#include <cstdio>
TicketManage::~TicketManage(){
    for(auto e:pTickets)
        delete e;
}

Ticket* TicketManage::findTicketById(long id){
    for(auto e:pTickets){
        if(e->getId()==id)return e;
    }
    return nullptr;
}
const Ticket* TicketManage::findTicketById(long id) const{
    for(auto e:pTickets){
        if(e->getId()==id)return e;
    }
    return nullptr;
}
Ticket* TicketManage::findTicketByName(string name){
    for(auto e:pTickets){
        if(e->getName()==name)return e;
    }
    return nullptr;
}
const Ticket* TicketManage::findTicketByName(string name)const{
    for(auto e:pTickets){
        if(e->getName()==name)return e;
    }
    return nullptr;
}
void TicketManage::addTicket(){
    string name,departure,destination,trainNum,position="D.C.";
    int type;
    double price;
    int dpy,dpmon,dpd,dph,dpmin,durh,durm,carriageNum;
    Ticket* p;
    char ifSmart,ifSilent;
    {
        cout<<"选择列车类型(1-普速列车，2-卧铺列车，3-高速列车)：";
        cin>>type;
        cout<<"输入乘车人姓名：";
        fflush(stdin);
        getline(cin,name);
        cout<<"输入出发站：";
        getline(cin,departure);
        cout<<"输入到达站：";
        getline(cin,destination);
        cout<<"输入车次：";
        getline(cin,trainNum);
        cout<<"输入车票费用：";
        cin>>price;
        cout<<"输入出发时间(年，月，日，小时(24时制)，分钟)：";
        cin>>dpy>>dpmon>>dpd>>dph>>dpmin;
        cout<<"输入行车时间：(小时:分钟)";
        scanf("%d:%d",&durh,&durm);
        cout<<"输入车厢号：";
        cin>>carriageNum;
    }
    type=trainCategory(type);
    switch(type){
    case STANDARD_TRAIN:{
        int category;
        cout<<"输入座位类型：(0-无座，1-硬座)";
        cin>>category;
        category=normalSeatCategory(category);
        if(category!=NO_SEAT){
            cout<<"输入座位号";
            cin>>position;
        }
        string str_category;
        switch(category){
        case NO_SEAT:
            str_category="无座";
            break;
        case HARD_SEAT:
            str_category="硬座";
            break;
        }

        Time_t tDeparture=getTime(dpy,dpmon,dpd,dph,dpmin);
        int dur=durh*60+durm;
        p=new Ticket(new StandardTrain(tDeparture,dur,trainNum,departure,destination)
                             ,name
                             ,price,new Seat(carriageNum,position,str_category,category==NO_SEAT));

        //        sortTickets();
        break;
    }
    case SLEEPER_TRAIN:{
        int category;
        int slprpos;
        cout<<"输入座位类型：(0-无座，1-硬座，2-硬卧，3-软卧)";
        cin>>category;
        category=normalSeatCategory(category);
        if(category!=NO_SEAT){
            if(category==HARD_SEAT){
                cout<<"输入座位号";
                cin>>position;
            }else if(category==HARD_SLEEPER){
                cout<<"输入铺位号";
                cin>>position;
                cout<<"输入铺位(1-下铺，2-上铺，3-中铺)";
                cin>>slprpos;
                slprpos=sleeperPositionCategory(slprpos);
            }else if(category==SOFT_SLEEPER){
                cout<<"输入铺位号";
                cin>>position;
                cout<<"输入铺位(1-下铺，2-上铺)";
                cin>>slprpos;
                slprpos=sleeperPositionCategory(slprpos);
            }
        }
        Time_t tDeparture=getTime(dpy,dpmon,dpd,dph,dpmin);
        int dur=durh*60+durm;
        string str_category,str_sleeperPosition;

        switch(category){
        case NO_SEAT:
            str_category="无座";
            break;
        case HARD_SEAT:
            str_category="硬座";
            break;
        case HARD_SLEEPER:
            str_category="硬卧";
            switch(slprpos){
            case LOWER_BERTH:
                str_sleeperPosition="下铺";
                break;
            case MIDDLE_BERTH:
                str_sleeperPosition="中铺";
                break;
            case UPPER_BERTH:
                str_sleeperPosition="上铺";
                break;
            }
            break;
        case SOFT_SLEEPER:
            str_category="软卧";
            switch(slprpos){
            case LOWER_BERTH:
                str_sleeperPosition="下铺";
                break;
            case UPPER_BERTH:
                str_sleeperPosition="上铺";
                break;
            }
            break;
        }
        p=new Ticket(new SleeperTrain(tDeparture,dur,trainNum,departure,destination,str_sleeperPosition)
                             ,name
                             ,price,new Seat(carriageNum,position,str_category,category==NO_SEAT));
        break;
    }
    case HIGHSPEED_TRAIN:{
        int category;
        cout<<"输入座位类型：(0-无座，1-二等座，2-一等座，3-商务座)";
        cin>>category;
        category=expressSeatCategory(category);
        if(category!=NO_SEATS){
            cout<<"输入座位号";
            cin>>position;
        }
        cout<<"是否为静音车厢？(y/n):";
        cin>>ifSilent;
        cout<<"是否为智能列车？(y/n):";
        cin>>ifSmart;
        string str_category;
        switch(category){
        case NO_SEATS:
            str_category="无座";
            break;
        case SECONDARY_CLASS:
            str_category="二等座";
            break;
        case FIRST_CLASS:
            str_category="一等座";
            break;
        case BUSINESS_CLASS:
            str_category="商务座";
            break;
        }
        Time_t tDeparture=getTime(dpy,dpmon,dpd,dph,dpmin);
        int dur=durh*60+durm;
        p=new Ticket(new HighspeedTrain(tDeparture,dur,trainNum,departure,destination,ifSmart=='y',ifSilent=='y')
                             ,name
                             ,price,new Seat(carriageNum,position,str_category,category==NO_SEATS));
        break;
    }
    }
    if(findTicketById(p->getId())!=nullptr){
        cout<<"您添加的车票已存在";
        delete p;
        return;
    }
    pTickets.push_back(p);
}
void TicketManage::removeTicket(){
    long id;
    cout<<"请输入您想删除车票的编号：";
    cin>>id;
    Ticket* p=findTicketById(id);
    if(p==nullptr){
        cout<<"您想删除的车票不存在";
        return;
    }
    pTickets.erase(getIterator(p));
}
void TicketManage::viewTicket(){
    long id;
    cout<<"请输入您想查看车票的编号：";
    cin>>id;
    Ticket* p=findTicketById(id);
    if(p==nullptr){
        cout<<"您想查看的车票不存在"<<endl;
        return;
    }
    p->output();
}
void TicketManage::viewAllTickets(){
    cout<<"车票数量："<<pTickets.size()<<endl;
    for(auto e:pTickets){
        cout<<"-------------------------------------"<<endl;
        e->output();
    }
}
void TicketManage::modifyTicket(){
    long id;
    cout<<"请输入您想修改车票的编号：";
    cin>>id;
    Ticket* p=findTicketById(p->getId());
    if(p==nullptr){
        cout<<"您想修改的车票不存在"<<endl;
        return;
    }
    modifyMenu(p);
}
vector<Ticket*>::iterator TicketManage::getIterator(Ticket *p){
    for(auto it=pTickets.begin();it!=pTickets.end();it++)
        if((*it)==p)
            return it;
    return pTickets.end();
}
void TicketManage::printCosts(){
    double s=0;
    for(auto e:pTickets){
        s+=e->getPrice();
    }
    cout<<"总费用："<<s<<"元"<<endl;
}
