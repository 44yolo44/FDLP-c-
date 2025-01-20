#include <iostream>

using namespace std;

int main(){
	int n ;
	int a=1 ;
	 
	cout<<"calculador de factorial"<<endl;
	cout<<"ingrese su numero : "; cin>>n;
	
	for(int i=1;i<=n;i++){
		a*=i;
  }
	cout <<"el resultado es : "<<a<<endl;
	
	return 0;
}

