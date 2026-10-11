#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;

  cin >> n;

  int t[n];

  for(int i = 0; i < n ; i++){
    cin >> t[i];
  }

  int out = 0;
  for(int i = 0; i < n ; i++){
    if (t[i] < 0){
      out++;
    }
  }

  cout << out << "\n";

  return 0;
}