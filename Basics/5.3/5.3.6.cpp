#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Sales {
	private:
		string product;
		double price;
		double quantity;
	public:
		Sales(string prod,double p,double q):product(prod),price(p),quantity(q) {} 
		virtual double net_price()const {
			return price*quantity;
		}
};
class DiscountSales:public Sales {
	private:
		double rate;
	public:
		DiscountSales(string prod,double p,double q,double r)
			:Sales(prod,p,q),rate(r) {}
		virtual double net_price()const {
			return Sales::net_price()*rate;
		}
};
class FullDiscountSales:public Sales {
	private:
		double fullMoney,discountMoney;
	public:
		FullDiscountSales(string prod,double p,double q,double f,double d)
			:Sales(prod,p,q),fullMoney(f),discountMoney(d) {}
		virtual double net_price()const {
			double money=Sales::net_price();
			int count=0;
			while((money-=fullMoney)>=0) {
				count++;
			}
			return Sales::net_price()-count*discountMoney;
		}
};
int main() {
	vector< Sales* > vec;
	vec.push_back(new DiscountSales("C++",100,2,0.8));
	vec.push_back(new FullDiscountSales("Java",80,5,200,30));
	cout<<vec[0]->net_price()<<endl;
	cout<<vec[1]->net_price()<<endl;
	double totalPrice=0;
	for(auto p : vec) totalPrice+=p->net_price();
	cout<<"totalPrice:"<<totalPrice<<endl;
	for(auto p: vec) delete p;
	return 0;
}
//output:
/*160
340
totalPrice:500*/
