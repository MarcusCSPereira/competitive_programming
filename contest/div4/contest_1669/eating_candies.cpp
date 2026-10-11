#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,op,b,c) for (int i =a; i op b; i += c)
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;

bool many_cases = true;

void solve(){
  READVEC(n, v, ll, ll);
  int l = 0, r = n - 1;
  ll ls = 0, rs = 0, ans = 0;

  while(l < r){
    if(ls <= rs) ls += v[l++];
    else rs += v[r--];

    if(ls == rs) ans = l + (n - r - 1);
  }

  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}