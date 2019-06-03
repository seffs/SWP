#include <iostream>
#include <string>
using namespace std;

int main(void)
{
cout << "Ihr Name bitte: \n";
string s;
cin >> s;
cout << "Aha, Sie heissen ";
cout << s << endl; //Avoid at all costs, only necessary when IO Interactive console, not console outputs
int x = 1;
float y = 2.0;
/*****************C******************/
/*printf("Int %d & Float %f", x, y);*/
cout << "Int " << x << " Float " << y;
//This also works....
cout << "Int " << y << " Float " << x;
}
