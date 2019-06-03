#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<string> v;
  cout << "Bitte zu sortierenden Text eingaben, \n"
       << "Stop mit \"stop\" \n";
  for(;;) {
    string s;
    getline(cin,s);
    if(s == "stop")
      break;
    v.push_back(s);
  }
  sort(v.begin(), v.end());
  cout << "Text nach Sortierung: \n";

  for(int i = 0; i < v.size(); i++)
    cout << v[i] << "\n";
}
