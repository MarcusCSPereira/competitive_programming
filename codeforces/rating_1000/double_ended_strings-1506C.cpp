#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = true;

void solve(){
  string a, b; cin >> a >> b;
  int n = a.length();
  int m = b.length();
  int lcs = 0;
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i-1] == b[j-1]){
        dp[i][j] = 1 + dp[i-1][j-1];
        lcs = max(lcs,dp[i][j]);
      }else{
        dp[i][j] = 0;
      }
    }
  }

  int operations = n+m - 2*lcs;
  cout << operations << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}