#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
const int tam_limit = 2e5 + 1;

bool many_cases = false;
vector<vector<int>> dp;

void solve(){
  ll n, x; cin >> n >> x;
  vector<int> V(n);
  vector<int> P(n);
  dp = vector<vector<int>>(n+1,vector<int>(x+1,0));
  for(int i=0; i<n; i++){
    cin >> P[i];
  }
  for(int i=0;i<n;i++){
    cin >> V[i];
  }

  for(int i=1;i<=n;i++){
    int c_value = V[i-1];
    int c_peso = P[i-1];

    for(int j=1;j<=x;j++){
      dp[i][j] = dp[i-1][j];

      if(c_peso <= j){
        dp[i][j] = max(dp[i][j],c_value + dp[i-1][j-c_peso]);
      }
    }
  }

  cout << dp[n][x] << endl;
  
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}