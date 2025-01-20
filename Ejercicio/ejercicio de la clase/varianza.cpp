
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int s=0;
  int c=0,i=0;
  float s2=0;
  float p;
  float v;
  float x[10] ;

  cout<<"calcula promedio max(10numeros) "<<endl;

  cout<<"ingrese un numero para promediar: ";
  cin >>x[0];

    while(x[i]>0)
    {
      s=s+x[i];
      c++;
      i++;

      cout<<"ingrese otro numero(para con 0) : ";
      cin >>x[i];
    }

    p=s/c;

    if(c<=0)
      cout <<"no se a ingresado ningul valor adicional "<<endl;
    else
    {
      cout<<"el promedio es: "<<p<<endl;
      for(i=0;i<c;i++)
        s2= s2 + ((x[i]-p)*(x[i]-p))/c;
      v=s2/c;
      cout <<"la varainza es  : ";
      cout<< v << endl;
      cout<<" la desviacion es : "<<sqrt(v)<<endl;
    }

    return 0;
}
