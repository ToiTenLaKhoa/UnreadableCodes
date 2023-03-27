
// THIS IS A DEMO INPUT FILE

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int maxn = 1e6 + 5;

#define TASK "SQUARE"

int main()

{
    // freopen(TASK ".INP", "r", stdin);
    // freopen(TASK ".OUT", "w", stdout);
    int a[maxn];
    int n, m, s, cnt = 0;
    cin >> n >> m >> s;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    for (int i = 1; i <= n * m; i++)
        for (int j = i + 1; j <= n * m; j++)
            if (a[j] + a[i] == s)
                cnt = (cnt + 1) % INF;
    cout << cnt;
    return 0;
}
