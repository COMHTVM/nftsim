#include <iostream>
#include<vector>
#include "tstencil.h"
// Unit test for stencil.cpp

using namespace std;

void ce(const TStencil& s){
    cout << s.c() << " " << s.e() << endl;
    return;
}

int main(){
	const int side = 5; const int nodes = side*side;
    vector<double> x(nodes);
    vector<double> y(nodes);
    TStencil s(nodes,side);
    
    for(int i = 0; i<nodes; i++){
        x[i] = i+1;
        y[i] = (i+1)*2;
    }
    
    s.assign(&x);
    
    cout << "Test 1: should see '1 2', '5 1' and '2 3'" << endl;
    ce(s);
    for(int i = 0; i < 4; i++)
        s++;
    ce(s);
    for(int i = 0; i <= 21; i++)
        s++;
    ce(s);

    cout << "Test 2: should see '2 4'" << endl;
    s.assign(&y);
    ce(s);
    
    cout << "Test 3: should see 2925" << endl;
    s.assign(&x);
    int total = 0;
    for(int i = 0; i <= 24; i++,s++)
        total += s.ne() + s.n() + s.nw() + s.e() + s.c() + s.w() + s.se() + s.s() + s.sw();
    cout << total << endl;
    
	cout << "Test 4: Should see '2 4'" << endl;
	x = y;
	ce(s);
    return 0;

}

