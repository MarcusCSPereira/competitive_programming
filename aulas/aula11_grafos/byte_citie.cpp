#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
const int tam_limit = 1e5 + 1;

bool many_cases = false;

vector<vector<int>> adj(tam_limit);
vector<bool> visited(tam_limit);

void dfs(int no){
  if(visited[no]) return;
  visited[no] = true;
  for(auto u: adj[no]){
    dfs(u);
  }
}

void solve(){
  int  n , m;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a,b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int conex = -1;
  vector<int> cc;
  for(int i=1; i<=n; i++){
    if(visited[i]) continue;
    conex++;
    cc.push_back(i);
    dfs(i);
  }
  
  cout << conex << endl;
  if(conex == 0) return;
  for(int i=1;i<cc.size();i++){
    cout << cc[0] << " " << cc[i] << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}
