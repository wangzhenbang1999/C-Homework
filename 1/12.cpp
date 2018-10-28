
#include<iostream>
#include <string>
#include<map>
using namespace std;

int main(){

	map<string,string> mp;
	//三种插入方法 
	mp.insert(pair<string,string>("Australia","Canberra"));
	mp["Belgium"] = "Brussels";
	mp.insert(map<string,string>::value_type("China","Beijing"));
	
	mp["Denmark"] = "Copenhagen";
	mp["England"] = "London";
	mp["France"] = "Paris";
	mp["Greece"] = "Athens";
	mp["Belgium"] = "Brussels";
	mp["Ireland"] = "Dublin";
	mp["Scotland"] = "Edinburgh";
	mp["Wales"] = "Cardiff";
	
	string s = "Denmark";
	//getline(cin,s);
	cout<<mp[s]<<endl;
	
} 
