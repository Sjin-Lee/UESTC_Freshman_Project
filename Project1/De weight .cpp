#include<fstream>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v;
};
int min( int x ,int y){
    if(x<y)
        return x;
    else
        return y;

}
int max( int x ,int y){
    if(x>y)
        return x;
    else
        return y;

}
bool cmp(edge x, edge y){
    if(x.u==y.u)return x.v<y.v;
    return x.u<y.u;
}
edge e[100000];
int main(){
    freopen("SciMet.txt","r",stdin);
    freopen("SciMet.out","w",stdout);
    int n,m,k;
    int num=0;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        e[++num].u=min(n,m);
        e[num].v=max(n,m);
    }
    for(int i=1;i<=num;i++)
    {
        printf("%d %d\n",e[i].u,e[i].v);
    }
    sort(e+1,e+num+1,cmp);

    for(int i=1;i<=num;i++){
        if(e[i].u==e[i-1].u && i>1 && e[i].v==e[i-1].v ){
            continue;
        }
        printf("%d %d \n",e[i].u,e[i].v);     
    }
    return 0;
}