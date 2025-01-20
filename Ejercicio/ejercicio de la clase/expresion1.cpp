#include <iostream>

using namespace std;

int main ()
{
  float a,b,c,d;
  float e;

  cout<<"ingrese el valor de a: "; cin>>a;
  cout<<"ingrese el valor de b: "; cin>>b;
  cout<<"ingrese el valor de c: "; cin>>c;
  cout<<"ingrese el valor de d: "; cin>>d;

    e=(a+b)/(c+d);
  cout.precision(2);
  cout<<"el resultado de su operacion es : "<<e<<endl;
  return 0;
}