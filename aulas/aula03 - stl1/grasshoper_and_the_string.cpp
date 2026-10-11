#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  string s; cin>>s;

  int max_salt = -INT_MAX ;
  int salt = 0;
  int lv = 0;

  for(int i=0;i<=s.size();i++){
    if (s[i] == 'A' || s[i] == 'E' 
        || s[i] == 'I' || s[i] == 'O' 
        || s[i] == 'U' || s[i] == 'Y' || (i+1) == s.size()+1){
      salt = (i+1) - lv;
      lv = (i+1);
    }

    max_salt = max(salt, max_salt);
  }

  cout << max_salt;

  return 0;
}

