
#include <iostream>
#include <algorithm>
using namespace std;

int getMinStepsBottomUp(int n)
{
    int dp[100001];

    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1 + dp[i - 1];

        if (i % 2 == 0)
            dp[i] = min(dp[i], 1 + dp[i / 2]);

        if (i % 3 == 0)
            dp[i] = min(dp[i], 1 + dp[i / 3]);
    }

    return dp[n];
}

int main()
{
    int values[] = {6, 7, 21, 36};
    int nums = sizeof(values) / sizeof(values[0]);

    std::cout << "Bottom-Up DP : \n";

    for (int i = 0; i < nums; i++)
    {
        int n = values[i];
        int result = getMinStepsBottomUp(n);

        std::cout << "For n = " << n
                  << ", Steps = " << result << "\n";
    }

    return 0;
}
