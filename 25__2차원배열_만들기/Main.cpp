#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int** alloc2DInt(int rows, int cols){
	if(rows<=0||cols<=0) return NULL;
	int** mat=new int* [rows];
	for(int i=0;i<rows;i++)
		mat[i]=new int[cols];
	return mat;
}

void free2DInt(int** mat, int rows, int cols=0){
	if(mat!=NULL){
		for(int i=0;i<rows;i++)
			delete[] mat[i];
		delete[] mat;
	}
}

int** set2D(int** mat, int rows, int cols){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++)
			mat[i][j]=(i+1)*(j+1);
	}
	return mat;
}

void print2DInt(int** mat, int rows, int cols){
	for(int i=0;i<rows;i++){
		printf("\n");
		for(int j=0;j<cols;j++)
			printf("%4d",mat[i][j]);
	}
	printf("\n");
}


int main(){
	int** mat;
	
	class Matsize{
		public:
		int row, col;
		Matsize(int r=0,int c=0){
			row=r;
			col=c;
		}
		void setSize(int r,int c){
			row=r;
			col=c;
		}
	};
	
	Matsize s[4];
	s[0].setSize(3,4);
	s[1].setSize(7,10);
	s[2].setSize(12,6);
	s[3].setSize(16,8);
	
	
	for(int i=0;i<4;i++){
		printf("%d row %d col\n\n",s[i].row,s[i].col);
		mat=alloc2DInt(s[i].row,s[i].col);
		set2D(mat,s[i].row,s[i].col);
		print2DInt(mat,s[i].row,s[i].col);
		free2DInt(mat,s[i].row,s[i].col);
		
		cout<<endl;
	}
	return 0;
}   