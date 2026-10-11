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
  string s, t; cin >> s >> t;
  int s_size = s.size();
  int t_size = t.size();
  vector<int> freq_int_t(26,0);
  for(int i=0; i<t_size; i++){
    freq_int_t[t[i] - 'A']++;
  }

  for(int i=s_size-1;i>=0;i--){
    if(freq_int_t[s[i] - 'A'] > 0){
      freq_int_t[s[i] - 'A'] --;
    }else{
      s[i] = '.';
    }
  }

  string final_s="";
  for(int i=0;i<s_size;i++){
    if(s[i]!='.'){
      final_s+=s[i];
    }
  }
  final_s == t ? COUT("YES") : COUT("NO");
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}