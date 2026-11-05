#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = false;

void solve(){
  string s; cin >> s;
  int lower_c=0, upper_c=0;
  for(char c : s){
    if(c >= 'a' && c <= 'z'){
      lower_c++;
    }else if(c>='A' && c <='Z'){
      upper_c++;
    }
  }
  if(lower_c >= upper_c){
    for(char c : s){
      cout << (char)tolower((unsigned char)c);
    }
    cout << endl;
  } else {
    for(char c : s){
      cout << (char)toupper((unsigned char)c);
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}