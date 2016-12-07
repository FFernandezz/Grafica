#include <iostream>

using namespace std;

template<typename T>

class Point
{
public:
	Point(T x, T y, T z):m_x(x),m_y(y),m_z(z) {}
	T m_x;
	T m_y;
	T m_z;
	void print();
	
};

template<typename T>
void Point<T>::print()
{
	cout<<m_x<<endl;
	cout<<m_y<<endl;
	cout<<m_z<<endl;
}