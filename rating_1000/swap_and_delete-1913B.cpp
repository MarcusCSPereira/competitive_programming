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
  string s; cin >> s;
  int count_0=0, count_1=0;
  for(int i=0; i< s.size(); i++){
    if(s[i] == '1') count_1++;
    else count_0++;
  }
  int ans = s.size();
  for(int i=0;i<s.size();i++){
    if(s[i] == '1'){
      if(count_0 > 0){ count_0--; ans--;}else {break;}
    }else{
      if(count_1 > 0){ count_1--; ans--;}else {break;}
    }
  }
  cout << ans << endl; 
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}