#include <cmath>
#include <iostream>


using namespace std;

int main(){
    long long x, y, res;
    x = 665857;
    y = 470832;
    res = pow(x,4);
    res -= 4*pow(y,4);
    res -= 4*pow(y,2);
    
    cout << res << endl;
    
}
