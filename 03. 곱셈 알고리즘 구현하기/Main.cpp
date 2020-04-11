#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int x,y;
    int result=0;
    cout<<"input x=";
    cin >> x;
    cout<<"input y=";
    cin >> y;
//필요한 코드를 작성하시오
	while (x>0){
		if (x%2!=0) {
			result+=y;
			x/=2;
			y*=2;
		}
		else {
			x/=2;
			y*=2;
		}
		
	}
	
	cout<<"Result:"<<result<<endl;

}
