#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;

bool many_cases = true;

void solve(){
  ll n; cin >> n;
  vector<ll> v(n);
  map<ll, ll> freq;
  for(int i=0; i< n; i++){
    cin>> v[i];
    freq[v[i]]++;
  }
  if(freq.size()>2) COUT("NO");
  if(freq.size()==1) COUT("YES");
  ll ans = 0;
  for(auto p : freq){
    ans = abs(p.second - ans);
  }
  ans > 1 ? COUT("NO") : COUT("YES");
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}