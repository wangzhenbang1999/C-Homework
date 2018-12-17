#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack {
private:
	vector<T> elems;     // Ԫ�� 

public:
	void push(T const&);  // ��ջ
	void pop();               // ��ջ
	T top() const;            // ����ջ��Ԫ��
	bool empty() const {       // ���Ϊ���򷵻��档
		return elems.empty();
	}
};

template <class T>
void Stack<T>::push(T const& elem)
{
	// ׷�Ӵ���Ԫ�صĸ���
	elems.push_back(elem);
	if (elems.size() == 10) {
		throw out_of_range("Stack<>::push(): full stack");
	}
}

template <class T>
void Stack<T>::pop()
{
	if (elems.empty()) {
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	// ɾ�����һ��Ԫ��
	elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
	if (elems.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	// �������һ��Ԫ�صĸ��� 
	return elems.back();
}

int main()
{
	try {
		Stack<int>         intStack;  // int ���͵�ջ 
		Stack<string> stringStack;    // string ���͵�ջ 

		// ���� int ���͵�ջ 
		intStack.push(1);
		intStack.push(2);
		intStack.push(3);
		intStack.push(4);
		intStack.push(5);
//		intStack.push(6);
//		intStack.push(7);
//		intStack.push(8);
//		intStack.push(9);
//		intStack.push(10);
//		intStack.push(11);// �쳣 

		// ���� string ���͵�ջ 
//		stringStack.push("hello");
//		cout << stringStack.top() << std::endl;
//		stringStack.pop();
//		stringStack.pop();
	}
	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
		return -1;
	}
}
