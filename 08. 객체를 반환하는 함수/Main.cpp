#include <iostream>
using namespace std;

class Pizza {
public:
	Pizza(int s) : size(s) { }
	int size;			// 단위: 인치
};
//필요한 부분을 작성해라.
Pizza createPizza(void){
	Pizza create(10);
	return create;
}




int main()
{
	Pizza pizza = createPizza();
	cout << pizza.size << "인치 피자" << endl;

	return 0;
}