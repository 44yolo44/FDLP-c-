#include <iostream>

using namespace std;
int factorial(int);

int main ()
{
  int n;
  //int i;
  //int f;
  int t;

  cout << "calcula de factorial de : ";
	cin >> n ;
	
	t = factorial(n);
	
	cout << "el factorial de "<<n<<" es: "<<t<<endl;
	return 0;
}

int factorial(int n)
{
	int f , i ;
	f=1;
  for (i=1 ; i<=n ; i++)
  	f=f*i;
  	
  	return f;
}