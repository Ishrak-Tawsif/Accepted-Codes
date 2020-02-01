#include <iostream>
using namespace std;

#define ll long long int

ll ar[3][100005],q[100005][5];

struct st{
	ll prop, sum;
};

st tree[3][3 * 100005];

void build(int node,int ind, int b, int e){
	if (b == e){
		tree[ind][node].sum = ar[ind][b];
		return;
	}
	int left = (node * 2);
	int right = (node * 2) + 1;
	int mid = (b + e) / 2;

	build(left, ind, b, mid);
	build(right, ind, mid + 1, e);

	tree[ind][node].sum = (tree[ind][left].sum + tree[ind][right].sum);
}

ll query(int node, int ind, int b, int e, int i, int j,ll carry = 0){
	if (i > e || j < b) return 0;
	if (b >= i && e <= j) return (tree[ind][node].sum + (carry * (e - b + 1)));

	int left = (node * 2);
	int right = (node * 2) + 1;
	int mid = (b + e) / 2;

	ll res1 = query(left, ind, b, mid, i, j,carry+tree[ind][node].prop);
	ll res2 = query(right, ind, mid + 1, e, i, j,carry+tree[ind][node].prop);
	return (res1 + res2);
}

void update(int node, int ind, int b, int e, int i, int j,ll val){
	if (i > e || j < b){
		return;
	}
	if (b >= i && e <= j){
		tree[ind][node].sum += ((e - b + 1) * val);
		tree[ind][node].prop += val;
		return;
	}

	int left = (node * 2);
	int right = (node * 2) + 1;
	int mid = (b + e) / 2;
	update(left, ind, b, mid, i, j, val);
	update(right, ind, mid + 1, e, i, j, val);
	tree[ind][node].sum = (tree[ind][left].sum + tree[ind][right].sum + ((e - b + 1)*tree[ind][node].prop));
}

int main(){
	ll n, m, k;

	cin >> n >> m >> k;

	///1 for array, 2 for cnt
	for (int i = 1; i <= n; i++) cin >> ar[1][i];

	build(1,1,1,n);
	build(1,2,1,m);

	
	for (int i = 1; i <= m; i++){
		cin >> q[i][1] >> q[i][2] >> q[i][3];
	}

	int u[100005], v[100005];

	for (int i = 1; i <= k; i++){
		cin >> u[i] >> v[i];
		//int node, int ind, int b, int e, int i, int j, ll val
		update(1,2,1,m,u[i],v[i],1);
	}

	for (int i = 1; i <= m; i++){
		ll mul = query(1, 2, 1, m, i, i); //cout << "query: " << i << " " << mul << endl;
		update(1, 1, 1, n, q[i][1], q[i][2], (q[i][3]*mul));
	}

	for (int i = 1; i <= n; i++){
		///int node, int ind, int b, int e, int i, int j,
		ll curans = query(1, 1, 1, n, i, i);
		if (i != 1) printf(" ");
		printf("%lld", curans);
	}
	printf("\n");
	//int hold;
	//cin >> hold;
	return 0;
}