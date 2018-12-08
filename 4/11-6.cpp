#include<iostream>
using namespace std; 
class b{
public:
	b(){
		cout<<"default constructor for b called"<<endl;	
	}
};
class d1:public b{
public:
	d1(){
		cout<<"default constructor for d1 called"<<endl;
	}
	d1(int v){
		cout<<"int parameter constructor for d1 called"<<endl;
	}
};
class d2: public d1{
public:
	d2(){
		cout<<"default constructor for d2 called"<<endl;
	}
	d2(int v){
		cout<<"int parameter constructor for d2 called"<<endl;
	}
};
int main(){
	b b_obj;
	d1 d1_obj(2);
	d1 d1_objs(2);
	d2 d2_obj(3);
}
//default constructor for b called
//default constructor for b called
//int parameter constructor for d1 called
//default constructor for b called
//int parameter constructor for d1 called
//default constructor for b called
//default constructor for d1 called
//int parameter constructor for d2 called

