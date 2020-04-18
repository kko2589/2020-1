
#include <iostream>
#include <string>
using namespace std;


#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE	100

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(0);
};

class ArrayStack
{
int data[MAX_STACK_SIZE];
int top;

public:

ArrayStack(){top=-1;}
~ArrayStack(){}
bool isEmpty(){return top==-1;}
bool isFull(){return top==MAX_STACK_SIZE-1;}

void push(int e){
	if(isFull()) error("스택 포화 에러");
	data[++top]=e;
}
int pop(){
	if(isEmpty()) error("스택 공백 에러");
	return data[top--];
}

//ArrayStack을 작성하시오.
};


bool CheckMatching(string s) {//괄호 스트링을 s로 받아 옴

	ArrayStack stack;
	char	ch;
	cout << s << " 검사를 시작합니다." << endl;

	for (int i = 0; i < s.length(); i++) { // 괄호의 개수만큼 반복
		ch = s.at(i); // 예를 들어 s="{([])}" 라면, s.at(0)='{', s.at(2)='[' 가 됨
//필요한 부분을 코딩하시오.
char temp;

switch(ch)
{
	case '(': case '{': case '[':
		{stack.push(ch); break;}
	case ')': case '}': case ']':
		{
			if(!stack.isEmpty())
			{
				temp=stack.pop();
				if((temp=='(' && ch!=')')||(temp=='{' && ch!='}')||(temp=='[' && ch!=']'))
					break;
			}
		}
		
}



	}//for (int i = 0; i < s.length(); i++) 끝

	if (!stack.isEmpty())
		printf("Error\n");
	else
		printf("OK\n");
	return stack.isEmpty();
}//CheckMatching()함수끝


int main()
{
	CheckMatching("({[()]([])})")?printf("맞음\n"):printf("문법오류\n");
	CheckMatching("({[([])]([{([({})])[({[]})]}])})")?printf("맞음\n"):printf("문법오류\n");;
	CheckMatching("(()")?printf("맞음\n"):printf("문법오류\n");;
	return 0;
}