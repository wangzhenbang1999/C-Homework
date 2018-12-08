#include<iostream>
using namespace std;
class b{
public:
	virtual void mf(int p);
};
void b::mf(int p){
	cout<<"member function mf in b called,"
		<<"Value of parameter is"<<p<<endl;
}
class d:public b{
public:
	void mf(double p);
};
void d::mf(double p){
	cout<<"member function mf in d called,"
		<<"value of parameter is"<<p<<endl;
}
int main(){
	b* ptr;
	d d_obj;
	ptr = new d;
	ptr->mf(1);
	d_obj.mf(1.1);
}
//member function mf in b called,Value of parameter is1
//member function mf in d called,value of parameter is1.1
