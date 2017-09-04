#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define LL long long int
#define MAX 1000000
using namespace std;
LL sum = 0;
LL debug = 0;
struct Node{
	LL max_height;
	LL min_height;
	LL lazy_propagation;
};
Node ST[MAX*2+2];
void update(int cur, int node_left, int node_right, int q_left, int q_right, int height){
	// if height is smaller than ST[cur].min_height, do nothing
	// cout << "node_left: " << node_left << "\n";
	// cout << "node_right: " << node_right << "\n";
	// cout << "max_height" <<ST[cur].max_height << " min_height " << ST[cur].min_height <<"\n";
	if(height < ST[cur].min_height){
		return;
	}
	// propagate it
	if(node_left != node_right){
		if(ST[cur].lazy_propagation > 0){
			ST[cur * 2 + 1].max_height = ST[cur * 2 + 1].min_height = ST[cur*2+1].lazy_propagation = ST[cur].lazy_propagation;
			ST[cur * 2 + 2].max_height = ST[cur * 2 + 2].min_height = ST[cur*2+2].lazy_propagation = ST[cur].lazy_propagation;
			ST[cur].lazy_propagation = 0;
		}
	}
	// if node's range is in query's range
	if(q_left <= node_left && node_right <= q_right){
		if(height >= ST[cur].max_height){
			// This range's height is all equal to "height"
			ST[cur].max_height = ST[cur].min_height = ST[cur].lazy_propagation = height;
			// Add overlap sum
			sum += node_right - node_left + 1;
			// debug += node_right - node_left + 1;
			// cout << "-------------------\n";
			// cout << "node_left: " << node_left << "\n";
			// cout << "node_right: " << node_right << "\n";
			// cout << "max_height" <<ST[cur].max_height << " min_height " << ST[cur].min_height <<"\n";
			// cout << "count!\n";
			// cout << "----------\n";
			return; // Since there is no need to keep traverse
		}
	}

	int mid = (node_left + node_right) / 2;
	// q_left on the left side
	if(q_left <= mid){
		update(cur * 2 + 1, node_left, mid, q_left, q_right, height);
	}
	// q_right on the right side
	if(q_right > mid){
		update(cur * 2 + 2, mid+1, node_right, q_left, q_right, height);
	}
	
	// update current node
	ST[cur].max_height = max(ST[cur*2+1].max_height, ST[cur*2+2].max_height);
	ST[cur].min_height = min(ST[cur*2+1].min_height, ST[cur*2+2].min_height);
}
int main(){
	int c,n,l,r,h;
	cin >> c;
	for(int i = 0; i < c; i++){
		cin >> n;
		sum = 0;
		memset(ST, 0, sizeof(ST));
		for(int j = 0; j < n; j++){
			cin >> l >> r >> h;
			debug = 0;
			update(0, 1, 100000, l, r-1, h);
			// cout << sum << "\n";
			// cout << "debug: " << debug << "\n"; 
		}
		cout << sum<< "\n";
	}
	return 0;
}