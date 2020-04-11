#include <iostream>
#include <vector>
#include <cassert>

const int MAX_SIZE = 1123;

int dp[MAX_SIZE][MAX_SIZE];

void build()
{
    for (int i = 0; i < MAX_SIZE; i += 1)
    {
        dp[i][0] = 1;
        dp[i][i - 1] = 1;
        for (int j = 1; j < i - 1; j += 1)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            dp[i][j] = std::min(dp[i][j], int(1e9) + 5);
        }
        for (int j = 0; j < i; j += 1)
        {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void solve_test_case()
{
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> v;

    v.push_back({1, 1});
    N -= 1;

    if (N > 0)
    {
        v.push_back({2, 2});
        N -= 1;
    }

    if (N > 0)
    {
        int i;
        for (i = 3; N > 0; i += 1)
        {
            if (i - 1 > N)
            {
                break;
            }
            N -= (i - 1);
            v.push_back({i, 2});
        }
        i -= 1;
        for (; i > 1 and N > 0; i -= 1)
        {
            v.push_back({i, 1});
            N -= 1;
        }
    }

    assert(N == 0);

    for (const auto &i : v)
    {
        std::cout << i.first << " " << i.second << std::endl;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int T;
    std::cin >> T;
    for (int test = 1; test <= T; test += 1)
    {
        std::cout << "Case #" << test << ":" << std::endl;
        solve_test_case();
    }

    return 0;
}