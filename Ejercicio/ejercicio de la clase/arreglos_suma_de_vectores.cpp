#include <iostream>

using namespace std;

int main()
{
   //declaracion de vectores
   int v1[3];
   int v2[3];
   int v3[3];
   //for de entrada v1
   cout << "ingrese lo valores del vector 1: "<<endl;
   for(int i=0 ; i<3 ;i++ )
   {
    cout<<"ingrese el valor numero "<<i+1<<": ";
    cin>>v1[i];
   }
   //for de entrada v2
   cout << "\ningrese lo valores del vector 2: "<<endl;
   for(int i=0 ; i<3 ;i++ )
   {
    cout<<"ingrese el valor numero "<<i+1<<": ";
    cin>>v2[i];
   }
   //for de proceso
   for(int i=0 ; i<3 ;i++ )
   {
    v3[i]=v1[i]+v2[i];
   }

   cout<<"\nel valor del vector 3 es: ";
   cout<<" [ - ";
   //for de salida
   for(int i=0 ; i<3 ;i++ )
   {
    cout<<v3[i];
    cout<<" - ";
   }
   cout <<"]" <<endl<<endl;
    return 0;
}


