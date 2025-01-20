#include <iostream>
using namespace std ;
 
 int factorial (int x){
 	int f=1;
 	for (int i=1;i<=x;i++){
 		f*=i;
	 }
 	return f;
 } 
 
int main(){
	
	int n;
	
	cout << "calcula de factorial de : ";
	cin>> n;
	
	cout<<"el factorial es : "<<factorial(n)<<endl;;
	
	return 0;
}