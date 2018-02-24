//hash algorithm
#include<bits/stdc++.h>
using namespace std;
int numtrees, numnodes;
//The sizes of the arrays are changed depending on the size of the trees used for the test data. 
//Note that creating variables, especially large arrays takes time.
int p1=3301, p2=33461;
int label[1000+1][1000+1];
int hash[1000+1][1000+1];
vector<int> children[1000+1][1000+1];
int isroot[1000+1][1000+1];
int root[1000+1];
void findhash(int treenum, int nodenum){
	vector<int> childrenhash;
	for(int i=0;i<children[treenum][nodenum].size();i++){
		findhash(treenum,children[treenum][nodenum][i]);
		childrenhash.push_back(hash[treenum][children[treenum][nodenum][i]]);
	}
	sort(childrenhash.begin(),childrenhash.end());
	hash[treenum][nodenum]=label[treenum][nodenum];
	int power=1;
	for(int i=0;i<childrenhash.size();i++){
		power=power*p1%p2;
		hash[treenum][nodenum]+=power*childrenhash[i]%p2;
	}hash[treenum][nodenum]%=p2;
}
int main(){
	ios::sync_with_stdio(false);
	//freopen("yourfilename","r",stdin);
	cin>>numtrees>>numnodes;
	for(int i=1;i<=numtrees;i++){
		for(int j=1;j<=numnodes;j++){
			//enter labels
			cin>>label[i][j];
		}
		for(int j=1;j<=numnodes;j++){
			isroot[i][j]=1;
		}
		for(int j=1;j<numnodes;j++){
			//enter edges, first is parent second is child
			int parent,child;
			cin>>parent>>child;
			children[i][parent].push_back(child);
			isroot[i][child]=0;
		}for(int j=1;j<=numnodes;j++){
			if(isroot[i][j]==1){
				root[i]=j;
			}
		}
	}
	for(int i=1;i<=numtrees;i++){
		//compute the hash for all trees
		findhash(i,root[i]);
	}
	/*for(int i=1;i<=numtrees;i++){
		for(int j=i+1;j<=numtrees;j++){
			if(hash[i][root[i]]==hash[j][root[j]]){
				cout<<i<<" "<<j<<" are isomorphic"<<endl;
			}
		}
	}*/
	
}
