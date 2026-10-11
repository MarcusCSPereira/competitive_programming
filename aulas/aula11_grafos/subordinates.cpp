#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
const int tam_limit = 2e5 + 1;

bool many_cases = false;

vector<bool> visited(tam_limit);

void dfs(int no,   vector<vector<int>> &adj , vector<int> &subTree){
  if(visited[no]) return;
  visited[no] = true;
  subTree[no] = 1;
  for(auto u: adj[no]){
    dfs(u, adj, subTree);
    subTree[no] += subTree[u];
  }
}

void solve(){
  int  n; cin >> n;
  vector<int> pai(n+1);
  for(int i=2;i<=n;i++){
    int a; cin >> a;
    pai[i] = a;
  }
  vector<vector<int>> adj(n+1);
  for(int i=2;i<=n;i++){
    adj[pai[i]].push_back(i);
  }
  vector<int> subTree(n+1,0);
  dfs(1, adj, subTree);

  for(int i =1;i<=n;i++){
    cout << subTree[i] - 1 << " ";
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}
