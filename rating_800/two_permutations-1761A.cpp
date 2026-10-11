#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define COUT(x) ({cout << x << endl; return;})
typedef long long ll;
const ll tam_limit = 1e5 + 1;
//typedef __int128 i128;

bool many_case = true;

void solve(){
  int n,a,b; cin >> n >> a >> b;
  if((a+b+2) <= n || (a==b && a==n)){
    COUT("YES");
  }else{
    COUT("NO");
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t =1;
  if(many_case) cin >> t;
  while(t--) solve();
  return 0;
}