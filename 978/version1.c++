#include <iostream>
#include <set>
#include <queue>
#define MAX 100
using namespace std;
int stack_green[MAX], top_green = -1;
int stack_blue[MAX], top_blue = -1;
int main(){
	int N; cin >> N;

	for(int i = 0 ; i < N; i++){
		int B,SG,SB;
		cin >> B >> SG >> SB;
		priority_queue<int> army[2]; // 0 stands for green; 1 stands for blue
		// input, put army in it
		for(int j = 0,input; j < SG; j++){
			cin >> input;
			army[0].push(input);
		}
		for(int j = 0, input; j< SB; j++){
			cin >> input;
			army[1].push(input);
		}
		// start battle round
		// if two forces are not empty, keep fight
		while(!army[0].empty() && !army[1].empty()){
			// open battle field for fight
			for(int j = 0; j < B; j++){
				// if there remain army to fight
				if(!army[0].empty() && !army[1].empty()){
					// call army out
					int green = army[0].top();
					int blue = army[1].top();
					// cout << "green: " <<green <<endl;
					// cout << "blue: " << blue <<endl;
					//remove army
					army[0].pop();
					army[1].pop();
					//start fight
					if(green > blue){
						stack_green[++top_green] = green - blue;
						// army[0].insert(green - blue);
					}
					else if(green < blue){
						stack_blue[++top_blue] = blue - green;
						// army[1].insert(blue - green);
					}
				}
			}
			// restore army
			for(;top_green >= 0; top_green--){
				army[0].push(stack_green[top_green]);
			}
			for(;top_blue >= 0; top_blue--){
				army[1].push(stack_blue[top_blue]);
			}
		}
		// output answer
		if(!army[0].empty()){
			cout << "green wins"<<"\n";
			while(!army[0].empty()){
				cout << army[0].top() <<"\n";
				army[0].pop();
			}
		}
		else if(!army[1].empty()){
			cout << "blue wins" << "\n";
			while(!army[1].empty()){
				cout << army[1].top() << "\n";
				army[1].pop();
			}
		}
		else{
			cout << "green and blue died\n";
		}
		if(i != N-1) cout << "\n";
	}
	return 0;
}