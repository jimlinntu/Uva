#include <bits/stdc++.h>
using namespace std;
double dptable[9][1024];
double par[9][1024];
vector<pair<int,int>> cord_list;
int N;
double dis(int a, int b){
	double dx = cord_list[a].first - cord_list[b].first;
	double dy = cord_list[a].second - cord_list[b].second;
	return sqrt(dx * dx + dy * dy) + 16;
}
double C(int start_point, int chosen){
	// base case
	if(chosen == ((1 << N) - 1)) return 0;
	if(dptable[start_point][chosen] >= 0) return dptable[start_point][chosen];
	double min = DBL_MAX;
	int temppar = -1;
	for(int i = 0; i < N; i++){
		// already chosen
		if(chosen & (1 << i)){
			continue;
		}
		double temp = C(i, chosen | (1 << i)) + dis(start_point, i);
		if(temp < min){
			min = temp;
			temppar = i;
		}
	}
	// store cache
	dptable[start_point][chosen] = min;
	// store 
	par[start_point][chosen] = temppar;
	//printf("start_point: %d temppar %d\n", start_point, temppar);

	return min;
}
int main(){
	for(int counter = 0; scanf("%d", &N) != EOF; counter++){
		if(N == 0) break;
		
		// init
		memset(dptable, -1, sizeof(dptable));
		memset(par, -1, sizeof(par));
		// input
		for(int i = 0; i < N; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			//printf("%d %d\n", a, b);
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
		
		printf("**********************************************************\n");
		printf("Network #%d\n", counter+1);
		for(int i = 0, point = start_point, chosen = (1 << start_point); i < N-1; i++){
			int nextp = par[point][chosen];
			//printf("point: %d nextp: %d\n", point, nextp);
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",
				cord_list[point].first, cord_list[point].second, cord_list[nextp].first, 
				cord_list[nextp].second, dis(point, nextp));
			point = nextp;
			chosen = chosen | (1 << nextp);
		}
		printf("Number of feet of cable required is %.2f.\n", min);

		// clear
		cord_list.clear();
	}
	return 0;
}
