//AHU algorithm
#include<bits/stdc++.h>
using namespace std;
int numtrees, numnodes;
//The sizes of the arrays are changed depending on the size of the trees used for the test data. 
//Note that creating variables, especially large arrays takes time.
string label[1000+1][100+1];
string canonical[1000+1][100+1];
vector<int> children[1000+1][100+1];
int isroot[1000+1][100+1];
int root[1000+1];
void findcanonical(int treenum, int nodenum){
	vector<string> childrencanonical;
	for(int i=0;i<children[treenum][nodenum].size();i++){
		findcanonical(treenum,children[treenum][nodenum][i]);
		childrencanonical.push_back(canonical[treenum][children[treenum][nodenum][i]]);
	}
	sort(childrencanonical.begin(),childrencanonical.end());
	canonical[treenum][nodenum]=label[treenum][nodenum]+"(";
	for(int i=0;i<childrencanonical.size();i++){
		canonical[treenum][nodenum]=canonical[treenum][nodenum]+childrencanonical[i];
	}
	canonical[treenum][nodenum]=canonical[treenum][nodenum]+")";
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
		//compute the canonical names for all trees
		findcanonical(i,root[i]);
	}
	/*for(int i=1;i<=numtrees;i++){
		for(int j=i+1;j<=numtrees;j++){
			if(canonical[i][root[i]]==canonical[j][root[j]]){
				cout<<i<<" "<<j<<" are isomorphic"<<endl;
			}
		}
	}*/
	
}
