//
// Created by Administrator on 2025/12/3.
//

#include<bits/stdc++.h>

using namespace std;

#define MAXN 200005
int n, s, nums[MAXN] ;
long long sum[MAXN], ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int z = nums[i] * nums[j];
            printf("%d * %d = %d ", nums[i], nums[j], z);
            s += z;
        }
        cout << "\n";
    }
    cout << s;
    return 0;
}
#if 0

#include<bits/stdc++.h>
using namespace std;


int main1()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        sum[i] = sum[i - 1] + nums[i];
    }
    for (int i = 1; i <= n - 1; i++)
        ans += nums[i] * (sum[n] - sum[i]);
    cout << ans << endl;
    return 0;
}
#endif
