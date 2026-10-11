#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string a;

  cin >> a;

  vector<char> b;
  
  for(int i = 0; i < a.size() ; i++){
    if (a[i] != 'A' && a[i] != 'E' && a[i] != 'Y' && a[i] != 'y'  && a[i] != 'I' && a[i] != 'O' && a[i] != 'U' && a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u'){
      b.push_back('.');
      b.push_back(tolower(a[i]));
    }
  }

  for(int i = 0; i < b.size() ; i++){
    cout << b[i];
  }

  return 0;

}