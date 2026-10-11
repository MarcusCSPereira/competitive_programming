#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
#define endl "\n"
typedef long long ll;

void solve(){
  ll n; cin>>n;
  map<string, int> dj;
  map<string, int> kt;

  for (int i=0;i<n;i++){
    string c; cin>>c;
    dj[c] +=1;
  }

  for (int i=0;i<n;i++){
    string c; cin>>c;
    kt[c] +=1;
  }
  int ans = 0;
  for(auto &[k,v] : dj){
    if(kt[k]){
      ans += min(kt[k], dj[k]);
    }
  }

  cout << ans;

}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  ll t=1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}