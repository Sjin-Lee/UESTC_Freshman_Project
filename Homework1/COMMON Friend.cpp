#include<bits/stdc++.h>
using namespace std;
#define MAXN 155
struct node{
	vector <int> FriendList;
	int CommonFriend[MAXN]; 
};
int n;
vector<node> Net;
int Matrix[MAXN][MAXN];
int main(){
	printf("自动生成矩阵？ Y/N \n");
	char c;
	scanf("%c",&c);
	if(c=='Y'||c=='y'){
		printf("输入总人数\n");
		scanf("%d",&n);
		Net.resize(n+10);
	    memset(Matrix,0x3f,sizeof(Matrix));
	    srand((unsigned)time(NULL));
	    for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    Matrix[i][j]=rand()%2;
			    if(Matrix[i][j]==1){
			    	Net[i].FriendList.push_back(j);
		            Net[j].FriendList.push_back(i);
		    	}
		    }
	    }
	    for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
		    	if(i==j){
		    		Matrix[i][j]=1;
		            continue;
				}
			    if(Matrix[j][i]>1)Matrix[j][i]=Matrix[i][j];
		    }
	    }
	    printf("邻接矩阵是：\n"); 
	    for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    printf("%d ",Matrix[i][j]);
		    }
		    printf("\n");
	    }
	}
	
	if(c=='N'||c=='n'){
		printf("输入小于150的人数 然后输入好友关系 \n 1 2 表示 1 2 是好友 0 0 表示输入结束");
	    scanf("%d",&n);
	    int x,y;
	    Net.resize(n+10); 
	    while(true){
		    scanf("%d%d",&x,&y);
		    Net[x].FriendList.push_back(y);
		    Net[y].FriendList.push_back(x);
		    if(x==y&&x==0){
			    break;
		    }
	    }
	}	
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cnt=0;
			for(int k=0;k<Net[i].FriendList.size();k++){
				for(int l=0;l<Net[j].FriendList.size();l++){
					if(Net[i].FriendList[k]==Net[j].FriendList[l]){
						cnt++;
						break;
					}
				}
			}
			Net[i].CommonFriend[j]=Net[j].CommonFriend[i]=cnt;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j)continue;
		    printf("%d 与 %d 的共同好友数是 %d\n",i,j,Net[i].CommonFriend[j]);
		}
	}
	
	while(1)getchar(); 
	return 0; 
}
