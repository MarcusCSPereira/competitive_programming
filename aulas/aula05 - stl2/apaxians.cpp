#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
#define endl "\n"
typedef long long ll;

void solve(){
  string s; cin >> s;
  string  n;
  n += s[0];
  for(int i=1;i<s.size();i++){
    if(s[i] != s[i-1]){
      n+=s[i];
    }
  }

  cout << n;
}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  ll t=1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}