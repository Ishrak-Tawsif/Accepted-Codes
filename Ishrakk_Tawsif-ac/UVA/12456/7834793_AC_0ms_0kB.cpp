#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, arr[10000];
    while (scanf("%d", &n) == 1 && n) {
        int total = 1, temp = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            total *= arr[i];
        }
        for (int i = 0, j = n - 1; i <= j; i++, j--)
            temp *= min(arr[i], arr[j]);
            
        printf("%lld\n", total - temp);
    }
return 0;
}