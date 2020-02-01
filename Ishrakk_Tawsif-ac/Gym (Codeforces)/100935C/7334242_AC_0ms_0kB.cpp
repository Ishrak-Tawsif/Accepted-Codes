#include<bits/stdc++.h>

using namespace std;

int main() {
	int t, n, m, temp_n, temp_m;
	char str[20][20];
	scanf("%d", &t);

	for(int i = 0; i < t; i++) {
		scanf("%d%d", &n, &m);
		for(int j = 0; j < n; j++) {
			scanf("%s", str[j]);
		}

            bool fl = true;
            for(int j = 1; j < n-1 && fl ; j++) {
                for(int k = 1; k < m-1; k++) {
                    if(str[j][k] == '*') {
                        temp_n = j+1;
                        temp_m = k+1;
                        fl = false;
                        break;
                    }
                }
            }

		int cnt = 0;
		for(int j = temp_n; j < n-1; j++) if(str[j][temp_m] == '*' ) cnt++;

            if(cnt == 1) printf("Case %d: Zero\n", i+1);
            else printf("Case %d: Eight\n", i+1);
	}
	return 0;
}