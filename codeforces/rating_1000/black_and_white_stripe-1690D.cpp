#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = true;

void solve(){
  ll n, k; cin >> n >> k;
  string s; cin >> s;
  vector<ll> prefix(n+1,0);
  for(int i=0; i<n;i++){
    prefix[i+1] = prefix[i] + (s[i] == 'W');
  }
  ll minimun_cells = LLONG_MAX;
  for(int i=0; i<=n-k; i++){
    ll diff = prefix[i+k] - prefix[i];
    minimun_cells = min(minimun_cells, diff);
  }

  cout <<  minimun_cells << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}