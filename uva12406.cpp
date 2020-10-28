#include <bits/stdc++.h>
using namespace std;

int main(void){
	int T, p, q;
	cin >> T;

	long long minn, maxx;

	int cases = 1;

	while(T--){
		cin >> p >> q;
		minn = 1e18, maxx = -1e18;

		for(long long i = (1<<(p-1))+1; i < (1<<(p+1)); i++){
			
			// cout << i << ' ';

			long long tmp = 0;
			for(int j = 0; j < p; j++){
				tmp *= 10;
				if(i&(1<<j))
					tmp += 1;
				else
					tmp += 2;
			}

			if(tmp % (1<<q) == 0){
				minn = min(minn, tmp);
				maxx = max(maxx, tmp);
			}
		}

		cout << "Case " << cases++ << ": ";

		if(minn == 1e18 && maxx == -1e18)
			cout << "impossible\n";
		else if(minn == maxx)
			cout << minn << '\n';
		else
			cout << minn << ' ' << maxx << '\n';
	}
	return 0;
}