#include <bits/stdc++.h>
using namespace std;

int arr[13+5];
int n, x;


void dfs(int now, string num, int depth){
	
	if(num != "")
		num += " ";
	num += (to_string(arr[now]));

	if(depth == 6){
		cout << num << '\n';
		return;
	}

	for(int i = now+1; i < n; i++){
		dfs(i, num, depth+1);
	}
}

int main(void){

	int T = 0;
	
	while(cin >> n && n){
		if(T)
			cout << '\n';

		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		for(int i = 0; i <= n-6; i++){
			dfs(i, "", 1);
		}
	
		T = 1;	
	}

	return 0;
}