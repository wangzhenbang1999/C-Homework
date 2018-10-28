#include<iostream>
#include<string>
#include <vector>
#include<cstring>
using namespace std;
class elevator
{
public:
	elevator() :currentFloor(1) {}
	void move(string order);
private:
	void up();
	void down();
	void back();
	int currentFloor;
};

void elevator::move(string order)
{
	if (order == "+")
		up();
	else if (order == "-")
		down();
	else if (order == "s" || order == "S")
		back();
	else if (order == "10")
		while (currentFloor < 10)
			up();
	else if (order == "1")
		while (currentFloor > 1)
			down();
	else if (order == "2") {
		while (currentFloor < 2)
			up();
		while (currentFloor > 2)
			down();
	}
	else if (order == "3") {
		while (currentFloor < 3)
			up();
		while (currentFloor > 3)
			down();
	}
	else if (order == "4") {
		while (currentFloor < 4)
			up();
		while (currentFloor > 4)
			down();
	}
	else if (order == "5") {
		while (currentFloor < 5)
			up();
		while (currentFloor > 5)
			down();
	}
	else if (order == "6") {
		while (currentFloor < 6)
			up();
		while (currentFloor > 6)
			down();
	}
	else if (order == "7") {
		while (currentFloor < 7)
			up();
		while (currentFloor > 7)
			down();
	}
	else if (order == "8") {
		while (currentFloor < 8)
			up();
		while (currentFloor > 8)
			down();
	}
	else if (order == "9") {
		while (currentFloor < 9)
			up();
		while (currentFloor > 9)
			down();
	}
}

void elevator::up()
{
	if (currentFloor < 10)
	{
		currentFloor++;
		cout << currentFloor << endl;
	}
	else
		cout << 10 << endl;
}

void elevator::down()
{
	if (currentFloor > 1)
	{
		currentFloor--;
		cout << currentFloor << endl;
	}
	else
		cout << 1 << endl;
}

void elevator::back()
{
	for (int i = currentFloor;i > 1;i--)
	{
		cout << i - 1 << endl;
	}
}

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
vector<string> f1() {
	string str;
	getline(cin, str);
	vector<string> res = split(str, " ");
	return res;
}
int main()
{
	elevator e;
	while (1) {
		vector<string> res = f1();
		for (int i = 0;i < res.size();i++) {
			e.move(res[i]);
			if (res[i] == "s" || res[i] == "S") 
			{
				return 0;
			}
			if (res.size() == 1) {
				break;
			}
			
		}
	}
		
	return 0;
}

