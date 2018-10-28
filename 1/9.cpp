
#include<iostream>
#include <string>
using namespace std;

void password(string f,string s){
	int q = int(f.size()/2);
	int p = int(s.size()/2);
	cout<<"Your password is:"<<f.substr(0,1)<<f.substr(q,1)<<f.substr(f.size()-1,1)<<s.substr(0,1)<<s.substr(p,1)<<s.substr(s.size()-1,1)<<endl;
}

int main(){
	string first_name = "yang",second_name = "liwei";
	cout<<"Enter your first name:"<<endl;
	//getline(cin,first_name);
	cout<<"Enter your second name:"<<endl;
	//getline(cin,second_name);
	password(first_name,second_name);
	
	
} 
