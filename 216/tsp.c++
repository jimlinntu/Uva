#include <bits/stdc++.h>
using namespace std;
double dptable[9][1000];
vector<pair<int,int>> cord_list;
int N;
int dis(int a, int b){
	double dx = cord_list[a].first - cord_list[b].first;
	double dy = cord_list[a].second - cord_list[b].second;
	return sqrt(dx * dx + dy * dy);
}
double C(int start_point, int chosen){
	// base case
	if(chosen == ((1 << N) - 1)) return 0;
	double min = DBL_MAX;
	for(int i = 0; i < N; i++){
		// already chosen
		if(chosen & (1 << i)){
			continue;
		}
		double temp = C(i, chosen | (1 << i)) + dis(start_point, i);
		if(temp < min){
			min = temp;
		}
	}
	return min;
}
int main(){

	while(scanf("%d", &N) != EOF){
		if(N == 0) break;
		// init
		memset(dptable, -1, sizeof(dptable));
		// input
		for(int i = 0; i < N; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%d %d\n", a, b);
			cord_list.push_back(make_pair(a, b));
		}
		// consider different start_point
		double min = DBL_MAX;
		int start_point;
		for(int i = 0; i < N; i++){
			double temp = C(i, 1 << i);
			if(temp < min){	
				min = temp;
				start_point = i;
			}
		}
		printf("%f\n", min + (double)(N-1) * 16);
	}
	return 0;
}
