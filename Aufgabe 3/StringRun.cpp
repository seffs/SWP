#include "String.h"

ostream& operator<< (ostream & out, String & s) {
  for (int i = 0; i<s.size; i++) {
    out << s.str[i];
  }
  return out;
}

int main(){
  /*String s;
  String s2("Hola");
  String s1("Alo");
  String s4("cocaaa");
  String s3(s2);
  s1 += s4;
  s2 = s4;
  //cout << s2 << endl;

  cout << s << endl;
  cout << s2 << endl;
  cout << s1 << endl;
  cout << s4 << endl;
  cout << s3 << endl;
  cout << s2[ 2 ] << endl;*/
  String s1;
  String s2("Hello");
  String s3(s2);
  s1 += s2;
  s2 = s3;
  cout << s2 << endl;
  cout << s2[ 2 ] << endl;
}
