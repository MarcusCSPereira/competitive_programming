#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;

bool many_cases = true;

void solve(){
  int n, end; cin >> n >> end;
  vector<int> v(n);
  for(int i = 0; i< n; i++){
    cin >> v[i];
  }

  int ans = v[0];
  for(int i =0;i+1<n;i++){
    ans = max(ans, (v[i+1] - v[i]));
  }

  ans = max(ans, (2*(end-v.back())));

  cout << ans << endl;
  
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}