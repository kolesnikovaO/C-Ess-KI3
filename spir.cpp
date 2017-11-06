#include <iostream>
using namespace std;

int main(void){
int n;
cout << "numb: ";
cin >> n;

if (n%2==0) cout<< "wrong";
else cout << n * (n - 2) + 2 ;
return 0;
}
