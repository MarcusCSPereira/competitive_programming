#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
const int tam_limit = 2e5 + 1;

bool many_cases = false;

vector<vector<int>> adj(tam_limit);
vector<bool> visited(tam_limit);

void dfs(int no, vector<int> &depth){
  if(visited[no]) return;
  visited[no] = true;
  for(auto u: adj[no]){
    if(visited[u]) continue;
    depth[u] = depth[no] + 1;
    dfs(u, depth);
  }
}

void solve(){
  int  n; cin >> n;
  for(int i=0;i<n-1;i++){
    int a,b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> depth(n+1,0);
  dfs(1, depth);
  int valMax = max_element(depth.begin(), depth.end()) - depth.begin();
  fill(depth.begin(), depth.end(), 0);
  fill(visited.begin(), visited.end(), false);

  dfs(valMax, depth);
  int ans = *max_element(depth.begin(), depth.end());
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}
