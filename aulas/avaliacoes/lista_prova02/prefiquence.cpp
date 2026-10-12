#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;

void solve(){
  ll n, m; cin >> n >> m;

  string a, b; cin >> a >> b;

  ll l=0;
  ll r=0;
  while(r<b.size() && l<a.size()){
    if(a[l] == b[r]){
      r++;
      l++;
    }else{
      r++;
    }
  }

  cout << l << endl;

}

bool many_cases = true;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}