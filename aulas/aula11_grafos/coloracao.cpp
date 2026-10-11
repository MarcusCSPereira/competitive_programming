#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;

bool many_cases = false;

bool dfs(int no, vector<vector<int>> &adj, vector<int> &colors, int color){
  colors[no] = color;

  for(auto u: adj[no]){
    if (colors[u] == 0){
      if(!dfs(u, adj, colors, (color == 1 ? 2 : 1))) return false;
    }
    if(colors[u] == color){
      return false;
    }
  }
  return true;
}

bool bs2(){return false;}

void solve(){
  int n,m; cin >> n >> m;
  vector<vector<int>> adj(n+1);
  vector<int> colors(n+1,0);
  for(int i=0; i<m;i++){
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  bool ok = true;
  for(int i=1;i<=n; i++){
    if (colors[i]!=0) continue;
    if(!dfs(i,adj,colors, 1)) ok = false;
  }
  if(ok){
    for(int i = 1;i<=n;i++){
      cout << colors[i] << " ";
    }
    cout << endl;
  }else{
    cout << "IMPOSSIBLE" << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}