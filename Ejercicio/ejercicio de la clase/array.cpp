
#include <iostream>
using namespace std;

int main()
{
float s=0;
int c=0,i=0;
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

  if(c<=0)
    cout <<"no se a ingresado ningul valor adicional "<<endl;
  else
  {
     cout <<"los valores son : ";
     for(i=0;i<c;i++){
         cout<<x[i]<<"  ";
     }
  }

    return 0;
}
