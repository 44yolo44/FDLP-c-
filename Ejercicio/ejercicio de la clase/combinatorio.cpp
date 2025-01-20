#include <iostream>

using namespace std;
int factorial(int);

int factorial(int x)//x no es variable es solo la señal de va a venir el valor de la variable
//se llama varaible falsa
{
	int f , i ;
	f=1;
  for (i=1 ; i<=x ; i++)
  	f=f*i;
  	
  	return f;
}

int main ()
{
  int n;
  int m;
  //int i;
  //int f;
  int c;
  cout << "combinatoria de n en m : "<<endl;
  cout << "\ningrese n : ";
	cin >> n ;
  cout << "\ningrese m : ";
	cin >> m ;
	cout << "\n";
	
	c = factorial(n)/(factorial(m)*factorial(n-m));
	
	cout << "el combinatorio es: "<<c<<endl;
	return 0;
}

