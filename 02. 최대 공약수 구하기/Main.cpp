#include <iostream>
using namespace std;


int find_gcd(int, int);

int main() {
	
	int a,b;
	cout <<"a=";
	cin>>a;
	
	cout <<"b=";
	cin>>b;
	
	cout<<"GCD="<<find_gcd(a,b);
	
	return 0;
	
}

int find_gcd(int x,int y){
	int gcd;
	while (y!=0)
	{
		gcd=y;
		y=x%y;
		x=gcd;
	}
	return gcd;
}