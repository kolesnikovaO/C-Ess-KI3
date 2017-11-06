#include <iostream>
using namespace std;
int main(void){
long long res = 1;
int n;
cout << "Enter Number : ";
cin >> n;
if(n == 0){
cout << "1";
return 0;}
else{
for (int i = 1; i <= n; i++){
res *=i;}
}
cout << res;
return 0;
}
