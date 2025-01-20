#include <iostream>

using namespace std;

int main(){
	int n;
	int s=0;
	int c=0;

	cout<<"ingrese su numero (>500) : ";
	cin >> n;
	cout<<"\n";
	
	for(int i=n+8 ; i<500 ; i+=8){
		cout<<i<<" ";
		s+=i;
		c++;
	}
	
	cout<<"\n\nla suma es : "<<c<<endl;
	cout<<"la cantidad es : "<<s<<endl;
	
	return 0;
}