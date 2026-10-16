#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;

bool many_cases = true;

void solve(){
  int n; cin >> n;
  string s; cin >> s;

  int w_count=0;
  int spaces=0;
  for(int i=0;i < s.size(); i++){
    if(s[i] == '.'){
      w_count++;
      spaces++;
    }else{
      spaces = 0;
    }
    if(spaces == 3){
      cout << "2" << endl;
      return;
    }
  }

  cout << w_count << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}