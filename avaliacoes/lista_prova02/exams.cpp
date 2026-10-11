#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;

void solve(){
  int n;cin >> n;
  vector<pair<ll,ll>> p(n);
  for(int i=0;i<n;i++){
    cin >> p[i].first;
    cin >> p[i].second;
  }

  sort(p.begin(),p.end());

  ll last= LLONG_MIN;
  for(int i=0;i<n;i++){
    if(p[i].second >= last) last = p[i].second;
    else last = p[i].first;
  }

  cout << last;

}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}