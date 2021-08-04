#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<char>> grid = {
    {'8', '6', '3', '9', '5', '1', '.', '.', '.'},
    {'.', '9', '.', '.', '.', '.', '5', '.', '1'},
    {'.', '1', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '2', '6', '4', '1', '.', '.', '5', '.'},
    {'.', '.', '.', '.', '.', '7', '.', '1', '.'},
    {'1', '.', '.', '.', '8', '6', '.', '.', '9'},
    {'6', '3', '.', '.', '7', '2', '.', '.', '.'},
    {'9', '.', '2', '.', '.', '.', '.', '6', '.'},
    {'.', '.', '.', '6', '.', '3', '.', '2', '8'},
};

bool possible(int x, int y, int n)
{
    int temp;

    if (grid[x][y] != '.')
        return false;

    for (size_t gridX = 0; gridX < 9; gridX++)
    {
        if ((int)grid[gridX][y] == n)
        {
            return false;
        }
    }

    for (size_t gridY = 0; gridY < 9; gridY++)
    {
        if ((int)grid[x][gridY] == n)
        {
            return false;
        }
    }

    return true;
}

void solve()
{
}

int main()
{
    for (size_t x = 0; x < 9; x++)
    {
        for (size_t y = 0; y < 9; y++)
        {
            cout << grid[x][y] << ", ";
        }
        cout << "\n";
    }

    return 0;
}