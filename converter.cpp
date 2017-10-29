#include <iostream>

using namespace std;

int main(void) {
int sys;
float m, ft, in;
cout << "Enter system: " << endl;
cin >> sys;

if ( sys == 0){
cout << "Enter metric: " << endl;
cin >> m;
cout << "Foot : "<< (int)(100 *m *  0.3937/12.) << "inch : "<< ((100 *(float)m *  0.3937/12.) - (int)(100 *(float)m *  0.3937/12.));}
else {
cout << "Enter foot : ";
cin >> ft;
cout << "Enter inch : ";
cin >> in;
cout << "Metr : "<< (ft*12 + in)*0.025;
}
return 0;}  
