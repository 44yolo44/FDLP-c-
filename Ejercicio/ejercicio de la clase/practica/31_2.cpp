#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	vector<int> grupos {200,100,50,20,10,5,2,1};
	
	int monto ;
	
	cout << "ingrese su monto : ";
	cin >> monto;
	cout << "su dinero se divide : "<<endl;
	
	for (int x:grupos){
  	int cantidad = monto / x;
  	if (cantidad>0){
  		cout<<"en monedas/billetes de "<<x<<" : "<<cantidad<<endl;
  		monto%=x;
		}
	}
	
	return 0;
}