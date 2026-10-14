#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

bool many_cases = true;

void solve(){
  int n; cin >> n;
  string s; cin >> s;
  vector<ll> alfa_pre(26,0), alfa_suf(26,0);
  vector<ll> prefix(n+1,0), sufix(n+1,0);
  for(int i = 0; i<n; i++){
    if(alfa_pre[s[i]-'a'] != 1){
      prefix[i+1] = prefix[i] + 1;
      alfa_pre[s[i]-'a'] = 1;
    }else{
      prefix[i+1] = prefix[i];
    }
  }
  for(int i = n-1; i>=0; i--){
    if(alfa_suf[s[i]-'a'] !=1){
      sufix[i] = sufix[i+1] + 1;
      alfa_suf[s[i]-'a'] = 1;  
    }else{
      sufix[i] = sufix[i+1];
    }
  }
  ll ans = LLONG_MIN;
  for(int i=0; i<n; i++){
    ans = max(ans, prefix[i+1] + sufix[i+1]);
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
