#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;

bool many_cases = true;

void solve(){
  int n; cin >> n;
  string a; cin >> a;
  
  string ans = "";

  int l=0;
  int r=l+1;

  while(r<n){
    if(a[r]==a[l]){
      ans += a[l];
      l = r+1;
      r = l+1;
    }else{
      r++;
    }
  }

  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll t =1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}