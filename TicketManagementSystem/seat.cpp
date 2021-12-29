#include "seat.h"
#include <iostream>
void Seat::output()const{
    cout<<"×ùÎ»ÀàÐÍ£º"<<category<<endl;
    if(!ifNoSeat){
        cout<<"³µÏáºÅ£º"<<carriageNum<<endl;
        if(category=="Ó²ÎÔ"||category=="ÈíÎÔ")
            cout<<"´²Î»ºÅ£º";
        else cout<<"×ùÎ»ºÅ£º";
        cout<<position<<endl;
    }
}
