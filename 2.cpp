#include <iostream>
#include <numeric>
#include <limits>

int main()
{
	int n, m;
    std::cin >> n >> m;
    int grid[20][20];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> grid[i][j];
    for (int i = 1; i < n; ++i) grid[i][0] += grid[i-1][0];
    for (int j = 1; j < m; ++j) grid[0][j] += grid[0][j-1];
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            grid[i][j] += std::min(grid[i-1][j], grid[i][j-1]);
    std::cout << grid[n-1][m-1];
	return 0;
}
