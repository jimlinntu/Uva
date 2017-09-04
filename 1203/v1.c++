#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>
using namespace std;
class Element{
public:
	int q_num;
	int period;
	int now;
	bool operator<(const Element& e2) const{
	if(now > e2.now){
			return true; //e1 is less priority
		}else if(now < e2.now){
			return false; // e2 is less priority
		}else{
			if(q_num > e2.q_num){
				return true; // e1 is less priority
			}else{
				return false; // 
			}
		}
	}
};

priority_queue<Element> Q;
int main(){
	string inputstr;
	while(cin >> inputstr){
		if(inputstr.compare("Register") == 0){
			int q_num, period;
			cin >> q_num >> period;
			// cout << q_num << " " << period << "\n";
			Q.push({q_num, period, period});
		}else if(inputstr.compare("#") == 0){
			int K = 7;
			cin >> K;
			// start pop out priority queue
			for(int i = 0; i < K; i++){
				Element temp = Q.top();
				Q.pop();
				cout << temp.q_num << "\n";
				//
				temp.now += temp.period;
				Q.push(temp);
			}
		}
	}
	return 0;
}