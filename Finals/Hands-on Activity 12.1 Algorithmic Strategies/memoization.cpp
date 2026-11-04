
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int memo[100001];

int getMinStepsMemoized(int n)
{
    if (n == 1)
        return 0;

    if (memo[n] != -1)
        return memo[n];

    int r = 1 + getMinStepsMemoized(n - 1);

    if (n % 2 == 0)
        r = min(r, 1 + getMinStepsMemoized(n / 2));

    if (n % 3 == 0)
        r = min(r, 1 + getMinStepsMemoized(n / 3));

    memo[n] = r;
    return r;
}

int main()
{
    int values[] = {1, 4, 7, 10};
    int nums = sizeof(values) / sizeof(values[0]);

    std::cout << "Memoization : \n";

    for (int i = 0; i < nums; i++)
    {
        int n = values[i];

        // memoization table
        std::memset(memo, -1, sizeof(memo));

        int result = getMinStepsMemoized(n);
        std::cout << "For n = " << n
                  << ", Steps = " << result << "\n";
    }

    return 0;
}
