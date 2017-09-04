#include <iostream>
#include <cmath>
#include <limits.h>
#include <algorithm>
using namespace std;
int T, S, A, F;
int x[50000];
int y[50000];
int main(){
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> S >> A >> F;
		for(int j = 0; j < F; j++){
			cin >> x[j] >> y[j];
		}
		//count best meeting place
		sort(x, x+F);
		sort(y, y+F);
		cout << "(Street: " << x[(F-1)/2] << ", Avenue: " << y[(F-1)/2] << ")\n";
	}
}