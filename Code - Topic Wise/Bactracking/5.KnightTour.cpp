#include<bits/stdc++.h>
using namespace std;

int KnightTour(vector<vector<int>> &mat,int i,int j,int row[8],int col[8],int move,int N){
	if(move == N*N)
		return 1;

	int ii,jj;
	for(int k=0;k<8;k++){
		ii = i + row[k];
		jj = j + col[k];
		if (ii>=0 && ii<N && jj>=0 && jj<N && mat[ii][jj]==-1){
			mat[ii][jj] = move;
			if(KnightTour(mat,ii,jj,row,col,move+1,N)==1)
				return 1;
			else
				mat[ii][jj] = -1;
		}
	}
	return 0;
}

int main(){
	int N;
	cin>>N;
	vector<vector<int>> mat(N,vector<int>(N,-1));
	int row[] = {2,1,-1,-2,-2,-1,1,2};
	int col[] = {1,2,2,1,-1,-2,-2,-1};
	mat[0][0] = 0;
	if(KnightTour(mat,0,0,row,col,1,N)){
		for(auto i: mat){
			for(auto j:i)
				cout<<j<<" ";
		cout<<"\n";
		}
	}
	else
		cout<<"-1";
	return 0;
}