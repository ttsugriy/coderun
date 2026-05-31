#include <iostream>
#include <numeric>
#include <limits>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
	int n, m;
    std::cin >> n >> m;
    int grid[100][100];
    char move[100][100];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> grid[i][j];
    for (int i = 1; i < n; ++i) grid[i][0] += grid[i-1][0];
    for (int j = 1; j < m; ++j) grid[0][j] += grid[0][j-1];
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j) {
            move[i][j] = grid[i-1][j] < grid[i][j-1] ? 'R' : 'D';
            grid[i][j] += std::max(grid[i-1][j], grid[i][j-1]);
        }
    std::cout << grid[n-1][m-1] << std::endl;
    std::vector<char> moves;
    for (int i = n - 1, j = m - 1;;) {
        if (i == 0 && j == 0) break;
        if (i == 0) {
            moves.push_back('R');
            j -= 1;
        } else if (j == 0) {
            moves.push_back('D');
            i -= 1;
        } else {
            moves.push_back(move[i][j]);
            if (move[i][j] == 'D')
                i -= 1;
            else
                j -= 1;
        }
    }
    std::copy(rbegin(moves), rend(moves), std::ostream_iterator<char>(std::cout, " "));
	return 0;
}
