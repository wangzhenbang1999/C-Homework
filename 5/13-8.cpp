#include <iostream>
#include <cstdlib>
using namespace std;
template <class T>
class queue
{
private:
	int front, rear, count;
	int MaxQSize=3;
	T qlist[];

public:
	queue(int size);
	void insert(const T& item);
	T remove();
};

template <class T>
queue<T>::queue(int size) : front(0), rear(0), count(0)
{
}

template <class T>
void queue<T>::insert(const T& item)
{
	count++;
	qlist[rear] = item;
	rear = (rear + 1) % MaxQSize;
}

template <class T>
T queue<T>::remove(void)
{
	T temp;
	temp = qlist[front];
	count--;
	front = (front + 1) % MaxQSize;
	return temp;
}
int main() {
	queue<char> q(3);
	q.insert('A');
	q.insert('B');
	q.insert('C');
	cout << q.remove();
	cout << q.remove();
	cout << q.remove();
}


