#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> grid = {
    {8, 6, 3, 9, 5, 1, 0, 0, 0},
    {0, 9, 0, 0, 0, 0, 5, 0, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 6, 4, 1, 0, 0, 5, 0},
    {0, 0, 0, 0, 0, 7, 0, 1, 0},
    {1, 0, 0, 0, 8, 6, 0, 0, 9},
    {6, 3, 0, 0, 7, 2, 0, 0, 0},
    {9, 0, 2, 0, 0, 0, 0, 6, 0},
    {0, 0, 0, 6, 0, 3, 0, 2, 8},
};

bool possible(int x, int y, int n)
{
    for (size_t gridX = 0; gridX < 9; gridX++)
    {
        if (grid[gridX][y] == n)
            return false;
    }

    for (size_t gridY = 0; gridY < 9; gridY++)
    {
        if (grid[x][gridY] == n)
            return false;
    }

    int innerX = (x / 3) * 3;
    int innerY = (y / 3) * 3;

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (grid[innerX + i][innerY + j] == n)
                return false;
        }
    }

    return true;
}

void solve()
{
    for (size_t x = 0; x < 9; x++)
    {
        for (size_t y = 0; y < 9; y++)
        {
            if (grid[x][y] == 0)
            {
                for (size_t i = 1; i < 10; i++)
                {
                    if (possible(x, y, i))
                    {
                        grid[x][y] = i;
                        solve();
                        grid[x][y] = 0;
                    }
                }

                return;
            }
        }
    }

    cout << "\n\nSolution: \n";
    for (size_t x = 0; x < 9; x++)
    {
        for (size_t y = 0; y < 9; y++)
        {
            cout << grid[x][y] << ", ";
        }
        cout << "\n";
    }

    system("pause");
}

int main()
{
    cout << "Original: \n";
    for (size_t x = 0; x < 9; x++)
    {
        for (size_t y = 0; y < 9; y++)
        {
            cout << grid[x][y] << ", ";
        }
        cout << "\n";
    }

    solve();
    cout << "No more solutions.";

    return 0;
}