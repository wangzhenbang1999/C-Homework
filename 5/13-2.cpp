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
	//��һ��������Ϊ��������ȥ����ô�������ͻ��˻�Ϊһ��ָ�룬����Ͳ�֪���������ĳ���
	string a[6] = { "hello","nihao","beijing","world","xian","shanxi"};
	int b[6] = {1,2,3,4,5,6};
	string s = "nihao";
	cout << locate(a, s) << endl;
	cout << locate(b, 5) << endl;
	return 0;
}
