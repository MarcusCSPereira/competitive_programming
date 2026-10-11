#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
#define endl "\n"
typedef long long ll;

void solve(){
  ll n; cin >> n;
  map<string, int> mp;

  for(int i=0; i< n; i++){
    string x; cin >> x;
    if(mp[x]){
      mp[x] += 1;
      cout << x << mp[x]-1 << endl;
    }else{
      mp[x] = 1;
      cout << "OK" << endl;
    }
  }
}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  ll t=1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}