#include <iostream>
using namespace std;
int main(void) {
 int n;
cout <<"Input numb : ";
cin >> n;
long long cur = 0;
long long pre = 0;
long long prepre = 0;
for(int i =0; i<n; i++) {
if (i==0) cur =1;
else{
prepre = pre;
pre = cur;
cur = prepre + pre;
}
}
cout << cur << " ";
return 0;
}
