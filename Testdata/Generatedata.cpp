//Generating test data
#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	//freopen("yourfilename","w",stdout);
	int numtrees=1000, numnodes=100;
	//cin>>numtrees>>numnodes;
	cout<<numtrees<<" "<<numnodes<<endl;
	int parent[numnodes+1];
	int label[numnodes+1];
	label[1]=1;
	int permutate[numnodes];
	int correspond[numnodes+1];
	for(int i=0;i<numnodes;i++){
		permutate[i]=i+1;
	}
	for(int i=0;i<numtrees/2;i++){
		
		for(int j=2;j<=numnodes;j++){
			parent[j]=rand()%(j-1)+1;
			label[j]=rand()%(10000)+1;
		}
		for(int k=0;k<2;k++){
			random_shuffle(permutate,permutate+numnodes);
			for(int j=1;j<=numnodes;j++){
				correspond[permutate[j-1]]=j;
			}
			for(int j=1;j<=numnodes;j++){
				cout<<label[correspond[j]]<<" ";
			}
			cout<<endl;
			for(int j=2;j<=numnodes;j++){
				cout<<permutate[parent[j]-1]<<" "<<permutate[j-1]<<endl;
			}
		}
	}
}
