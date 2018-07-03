/*
	Island Counter from pramp.
	NOTE: Poor error checking...
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int temp=0;

/*
	Recursive markCell function.
*/
void markCell(vector<vector<int> >& b,int i,int j,int row, int col){
	if(b[i][j]!=1){  // base condition of recursion
		return;
	} else {
		b[i][j]=-1;
		temp++;
		if(i>0) markCell(b,i-1,j,row,col);
		if(j<col-1) markCell(b,i,j-1,row,col);  // first move left as possible as can
		if(i<row-1)markCell(b,i+1,j,row,col);  //second move right as possible as can
		if(j>0)markCell(b,i,j+1,row,col);  //the last move to down
	}
}

/**
	Island count example.
	Given 2D vector of 0-1 each 1 represents an island
	or part of an island.
*/
int getNumberOfIslands(vector<vector<int> >&  binaryMatrix){

	int result=0;
	int row=binaryMatrix.size();
	int col=binaryMatrix[0].size();

  if(row<1) //unvalid entry
    return -1;
    
	vector<int> sizeOfIslands;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j<col ; ++j)
		{
			if(binaryMatrix[i][j]==1){
				cout<<"Found an island on b["<<i<<","<<j<<"]"<<endl;
				markCell(binaryMatrix,i,j,row,col);
				result++;
				if(temp!=0){
					sizeOfIslands.push_back(temp);
					temp=0;
				}
			}
		}
	}
	for(int i=1;i<=sizeOfIslands.size();++i){
		cout<<i<<". island size is: "<<sizeOfIslands[i-1]<<endl;
	}
	return sizeOfIslands.size();
}

void fillRandomly(vector<vector<int> >& v){
	srand(time(0));	//Her hangi bir rakam verince hata vermekte. 0 aslinda t_time tipinde.
	for(int i=0;i<v.size();i++)
		for (int j = 0; j < v[0].size(); ++j)
			v[i][j]=rand()%2;
}

void printVector(const vector<vector<int> >& v){
	cout<<"Vector is: "<<endl;
	for(int i=0;i<v.size();i++){
		for (int j = 0; j < v[0].size(); ++j){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

/*
	Main function to drive functions
*/
int main(int argc, char const *argv[])
{
	vector<vector<int> > v(10,vector<int>(10,0));
	fillRandomly(v);
	printVector(v);
	cout<<"Result is: "<<getNumberOfIslands(v)<<endl;
	return 0;
}
