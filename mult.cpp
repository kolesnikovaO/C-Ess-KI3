#include <iostream>

using namespace std;

int main(void) {
long rez = 1;
int n, i;
cout << "Number: ";
cin >> n;
for(i = 0; i < n ; i++){
rez *= 2  ;
}
cout << rez;
return 0;
}
