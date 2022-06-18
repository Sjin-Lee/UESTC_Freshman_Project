#include <iostream>
#include <vector>
using namespace std;
struct Edge {
  int u, v;
};
int n, m;
vector<Edge> e;
vector<bool> vis;
vector<int> FriendCount;
bool find_edge(int u, int v) {
  for (int i = 1; i <= m; ++i) {
    if (e[i].u == u && e[i].v == v) {
      return true;
    }
  }
  return false;
}
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  for (int i = 1; i <= m; ++i) {
    if (e[i].u == u) {
      dfs(e[i].v);
    }
  }
}

int main() {
  cin >> n >> m;
  vis.resize(n + 1, false);
  e.resize(m + 1);
  for (int i = 1; i <= m; ++i) cin >> e[i].u >> e[i].v;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= m; j++) {
      if (e[j].u == i) {
        if (find_edge(e[j].v, i)) {
          cnt++;
        }
      }
    }
    FriendCount.push_back(cnt);
  }
  for(int i=1;i<=n;i++){
    cout<<FriendCount[i]<<" ";
  }
  cout<<endl;
  return 0;
}
