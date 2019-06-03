#include <iostream>
using namespace std;

class String {
  private:
    int size;
    char* str;
  public:
    String();
    String(char c);
    String(const char *);
    String(const String&);
    String(String&&);
    ~String();

    char& operator[] (int index);
    String& operator=(const String&);
      String& operator=(String&&);
    String& operator+=(String&);

    friend ostream& operator << (ostream &out, String &s);
};
