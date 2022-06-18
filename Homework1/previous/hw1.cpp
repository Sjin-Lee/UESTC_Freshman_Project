#include<cstdio>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
bool isFriend[105][105];
int CN[105][105];
#define Len 10
struct node{
    vector<int> friendList;
    int friendNum;
};
node person[105];
void addnode(int x,int y){
    person[x].friendList.push_back(y);
    person[y].friendList.push_back(x);
    person[x].friendNum++;
    person[y].friendNum++;
}
int FindComF(int i,int j){
    if(i==j) return 1;
    if(isFriend[i][j]) return 1;
    int ans=0;
    for(int k=0;k<person[i].friendList.size();k++){
    	for(int t=0;t<person[j].friendList.size();j++){
    		if( isFriend[ person[i].friendList[k] , person[j].friendList[t] ]  )ans++;
		}
	}
    return ans;
}
int main(){
    memset(CN,0,sizeof(CN));
    memset(isFriend,0,sizeof(isFriend));
    srand((unsigned int)time(NULL));
    for(int i=1;i<=Len;i++){
        for(int j=1;j<i;j++){
            isFriend[i][i]=false;
            isFriend[i][j] = rand()%2;
            cout<<isFriend[i][j];
            addnode(i,j);
        }
        cout<<endl;
    }
    for(int i=1;i<=Len;i++){
        for(int j=1;j<=Len;j++){
            CN[i][j]=CN[j][i]=FindComF(i,j);
        }
    }
    for(int i=1;i<=Len;i++){
        for(int j=1;j<=Len;j++){
            printf("%d ",CN[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//数每两个节点之间的common neighbor 的数目