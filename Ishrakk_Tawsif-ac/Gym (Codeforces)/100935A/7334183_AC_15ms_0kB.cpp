#include<bits/stdc++.h>

using namespace std;

int main() {
	int t, h_r, min, sec, temp,temp2;
	scanf("%d", &t);

	for(int i = 0; i < t; i++) {

		scanf("%d %d %d", &h_r, &min, &sec);

		temp = h_r*3600+min*60+sec;

		scanf("%d%d%d", &h_r, &min, &sec);

        temp2 = h_r*3600+min*60+sec;

		if(temp ==temp2) {
			printf("Case %d: Yes\n", i+1);
		}
		else {
			printf("Case %d: No\n", i+1);
		}
	}
	return 0;
}