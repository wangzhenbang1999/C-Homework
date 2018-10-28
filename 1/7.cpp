
#include<iostream>
#include <string>
#include <vector>
#include<cstring>
using namespace std;


vector<string> split(const string& str, const string& de) {
	vector<string> res;
	if ("" == str) return res;

	char * strs = new char[str.length() + 1];
	strcpy(strs, str.c_str());

	char * d = new char[de.length() + 1];
	strcpy(d, de.c_str());

	char *p = strtok(strs, d);
	while (p) {
		string s = p;
		res.push_back(s);
		p = strtok(NULL, d);
	}
	return res;
}


int main() {
	string str = "my name is wangzhenbang";
	//getline(cin, str);
	vector<string> res = split(str, " ");
	double count = 0;
	for (int i = 0; i < res.size(); ++i)
	{
		count += res[i].size();
	}
	if(res.size() != 0) {
		cout<<count/res.size()<<endl;
	} else {
		cout<<0<<endl;
	} 
	
	
}

 
