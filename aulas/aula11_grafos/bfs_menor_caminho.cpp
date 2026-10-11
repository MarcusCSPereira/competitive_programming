#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;

bool many_cases = false;

void bfs(int no, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &dist, vector<int> &pai){
  queue<int> q;
  q.push(no);
  visited[no] = true;
  pai[no] = no;
  dist[no] = 0;
  while(!q.empty()){
    int s = q.front(); q.pop();
    for(auto u : adj[s]){
      if(visited[u]) continue;
      q.push(u);
      visited[u] = true;
      pai[u] = s;
      dist[u] = dist[s] + 1;
    }
  }
}

bool bs2(){return false;}

void solve(){
  int n,m; cin >> n >> m;
  vector<vector<int>> adj(n+1);
  vector<bool> visited(n+1);
  vector<int> dist(n+1);
  vector<int> pai(n+1);
  for(int i=1;i<=m;i++){
    int a,b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  bfs(1,adj,visited,dist,pai);
  if(!visited[n]) COUT("IMPOSSIBLE");
  int temp = n;
  vector<int> way;
  while(temp != 1){
    way.push_back(temp);
    temp = pai[temp];
  }
  way.push_back(1);
  cout << way.size() << endl;
  for(int i=way.size()-1; i>=0; i--){
    cout << way[i] << " ";
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}