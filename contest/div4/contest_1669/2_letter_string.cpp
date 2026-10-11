#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,op,b,c) for (int i =a; i op b; i += c)
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;

bool many_cases = true;

void solve(){
  ll n, ans =0; cin >> n;
  map<char,ll> fir, sec;
  map<string, ll> full;
  for(int i=0; i<n;i++){
    string s; cin >> s;
    ans += fir[s[0]] + sec[s[1]] - (2*full[s]);
    fir[s[0]]++; sec[s[1]]++; full[s]++;
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