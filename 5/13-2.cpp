#include<iostream>
#include<string>
using namespace std;

template<class T>
int locate(T (&a)[6], T t)
{
	for (int i = 0; i < 6; i++)
		if (t == a[i])
			return i + 1;
	return -1;
}

int main()
{
	//把一个数组作为参数传进去，那么这个数组就会退化为一个指针，因而就不知道这个数组的长度
	string a[6] = { "hello","nihao","beijing","world","xian","shanxi"};
	int b[6] = {1,2,3,4,5,6};
	string s = "nihao";
	cout << locate(a, s) << endl;
	cout << locate(b, 5) << endl;
	return 0;
}
