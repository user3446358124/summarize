#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>

#define gc getchar()
#define ll long long

using namespace std;

const int N = 1e4 + 10;

template<class o>
inline void qr(o& x)
{
	x = 0;
	char c = gc;
	while (c < '0' || c>'9')
		c = gc;
	while (c >= '0' && c <= '9')
	{
		x = x * 10 + (c ^ 48); c = gc;
	}
}

void qw(ll x)
{
	if (x / 10)
		qw(x / 10);
	putchar(x % 10 + 48);
}
ll a[N]; int c[N], n; ll m;
void add(int x)
{
	for (; x <= n; x += x & -x)
		++c[x];
}
int ask(int x) 
{ 
	int ans = 0; for (; x; x -= x & -x)ans += c[x];
	return ans;
}
struct segtree
{
	int l, r, sum;
}t[N * 4];
int cnt;

void build(int& x, int l, int r)
{
	x = ++cnt;
	if (l == r)
	{
		t[x].sum = 1; return;
	}
	int mid = (l + r) >> 1;
	build(t[x].l, l, mid);
	build(t[x].r, mid + 1, r);
	t[x].sum = t[t[x].l].sum + t[t[x].r].sum;
}
void change(int l, int r, int x, int pos)
{
	--t[x].sum;
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	if (pos <= mid)
		change(l, mid, t[x].l, pos);
	else 
		change(mid + 1, r, t[x].r, pos);
}

int query(int l, int r, int x, int k)
{
	if (l == r)
		return l;
	int mid = (l + r) >> 1;
	if (k <= t[t[x].l].sum)
		return query(l, mid, t[x].l, k);
	else 
		return query(mid + 1, r, t[x].r, k - t[t[x].l].sum);
}
int main()
{
	qr(n), qr(m);
	for (int i = 1; i <= n; i++)qr(a[i]);
	for (int i = 1; i <= n; i++)
	{
		int x = a[i]; add(a[i]);
		a[i] = a[i] - ask(a[i] - 1) - 1;
	}
	a[n] += m;
	for (int i = n; i >= 2; i--)
	{
		a[i - 1] += a[i] / (n - i + 1);
		a[i] %= n - i + 1;
	}
	int root = 0;
	build(root, 1, n);
	for (int i = 1; i <= n; i++)
	{
		++a[i];
		a[i] = query(1, n, 1, a[i]);
		qw(a[i]), putchar(' ');
		change(1, n, 1, a[i]);
	}
	puts("");
	return 0;
}