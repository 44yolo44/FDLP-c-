#include <iostream>

using namespace std;

int main(){
	int n,m;
	int i;
	int c=0;
	
	cout<<"ingrese su rango de n a m "<<endl<<endl;
	
	cout<<"ingrese n: "; cin>>n ;
	cout<<"\ningrese m: "; cin>>m ;
	
	for (i=n+3;i<m;i+=3){
		c++;
		if (c%2!=0)
		cout<<i<<" ";
	}
	
	return 0;
}