#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = true;

void solve(){
  int n; cin >>n; char c; cin >> c;
  string s; cin >> s;
  int l=0; int r=s.size()-1;
  ll ans =0;
  while(l<r){
    if(s[l] != s[r]){
      if(s[l] != c){
        ans++;
      }
      if(s[r] != c){
        ans++;
      }
    }
    l++; r--;
  }

  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}