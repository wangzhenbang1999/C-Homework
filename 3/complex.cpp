#include<iostream>
#include<cmath>
#include <string>
#include <cstdlib>
using namespace std;
class complex{
public:
	complex(){real=0;imaginary=0;} 
	complex(const complex& c){real=c.real;imaginary=c.imaginary;}
	complex operator+(const complex c);
	complex operator-(const complex &c);
	bool operator==(const complex &c);
	bool operator!=(const complex &c);
	bool operator>(const complex& c);
	bool operator<(const complex& c);
	friend ostream & operator<<(ostream &out, complex& c);
	friend istream & operator >> (istream &in, complex& c);
private:
	float real;
	float imaginary;
};
complex complex:: operator+(const complex c)
{
	complex tmp;
	tmp.real =real+c.real ;
	tmp.imaginary =imaginary+c.imaginary ;
	return tmp;
}
complex complex::operator-(const complex &c)
{
	complex tmp;
	tmp.real =real-c.real ;
	tmp.imaginary =imaginary-c.imaginary ;
	return tmp;
}
bool complex::operator==(const complex &c)
{
	return (real == c.real)&&(imaginary == c.imaginary);
}
bool complex::operator!=(const complex &c)
{
	return (real != c.real)&&(imaginary != c.imaginary);
}
bool complex::operator>(const complex& c)
    {
        double square1 = pow(real, 2) + pow(imaginary, 2);
        double square1_root1 = sqrt(square1);
        double square2 = pow(c.real, 2) + pow(c.imaginary, 2);
        double square2_root2 = sqrt(square2);
        if (square1_root1 > square2_root2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
bool complex::operator<(const complex& c)
    {
        double square1 = pow(real, 2) + pow(imaginary, 2);
        double square1_root1 = sqrt(square1);
        double square2 = pow(c.real, 2) + pow(c.imaginary, 2);
        double square2_root2 = sqrt(square2);
        if (square1_root1 < square2_root2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
ostream & operator<<(ostream &out, complex& c)
{
	if(c.imaginary>0)
    	out <<c.real<< "+" << c.imaginary<<"i";
    else 
		out <<c.real<< c.imaginary<<"i";
    return out;
}
istream & operator>>(istream &in, complex& c)
{
    string s;
    in >> s; 
	string str="+";
	string::size_type idx = s.find(str);//判断虚部正负 
	if(idx != string::npos){
		int pos = s.find("+");
	    string sTmp = s.substr(0,pos); 
	    c.real = atof(sTmp.c_str());
	    sTmp = s.substr(pos+1, s.length()-pos-2); 
	    c.imaginary = atof(sTmp.c_str());
	    return in;
	}
	string str1="-";
	string::size_type idy = s.find(str1);//判断虚部正负
	if(idy != string::npos){
		int pos = s.rfind("-");//反向查找 
	    string sTmp = s.substr(0,pos); 
	    c.real = atof(sTmp.c_str());
	    sTmp = s.substr(pos+1, s.length()-pos-2); 
	    c.imaginary = atof(sTmp.c_str());
	    c.imaginary = -c.imaginary;
	    return in;
	}
	cout<<"ERROR";
	exit(0);
	
	
   
}
int main()
{
	complex c1, c2, c3, c4, c5 ;
	while(1){
		cin >> c1 >> c2 ;
//		cout<<c1<<" "<<c2<<endl;	
		c3 = c1 + c2 ;
		c4 = c1 - c2 ;
//		cout<<c3<<" "<<c4<<endl;
		if ( c3 != c4 )
			{
				if (c3 < c4)
					{
						cout << "c3 is less than c4";
						c5 = c4 - c3 ;
					}
				if ( c3 > c4 )
					{
						cout << "c3 is greater than c4";
						c5 = c3 - c4 ;
					}
			}
		if ( c3 == c4 )
			{
				cout << "c3 and c4 are equal";
				c5 = c4 ;
			}
		cout << c5 ;
	}
}

