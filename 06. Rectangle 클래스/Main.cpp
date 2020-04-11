#include <iostream>
using namespace std;
//필요한 코드를 작성해라.
class Rectangle{
	
	int a;
	int b;
	public:
	Rectangle(int h, int w){
		a=h;
		b=w;
	}
	int calcArea(){
		return a*b;
	}
};


int main()
{
	Rectangle r{ 3, 4 };

	cout << "사각형의 넓이 : " << r.calcArea() << '\n';
	return 0;
}