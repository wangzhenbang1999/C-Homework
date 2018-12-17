#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack {
private:
	vector<T> elems;     // 元素 

public:
	void push(T const&);  // 入栈
	void pop();               // 出栈
	T top() const;            // 返回栈顶元素
	bool empty() const {       // 如果为空则返回真。
		return elems.empty();
	}
};

template <class T>
void Stack<T>::push(T const& elem)
{
	// 追加传入元素的副本
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
	// 删除最后一个元素
	elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
	if (elems.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	// 返回最后一个元素的副本 
	return elems.back();
}

int main()
{
	try {
		Stack<int>         intStack;  // int 类型的栈 
		Stack<string> stringStack;    // string 类型的栈 

		// 操作 int 类型的栈 
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
//		intStack.push(11);// 异常 

		// 操作 string 类型的栈 
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
