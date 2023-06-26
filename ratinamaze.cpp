#include <bits/stdc++.h>
using namespace std;
void ratInMazeHelper(vector<vector<int>> &maze, int i, int j, vector<int> &tmp, vector<vector<int>> &res)
{
    int n = maze.size();
    if (i < 0 || j < 0 || i >= n || j >= n)
        return;
    if (i == n - 1 && j == n - 1)
    {
        tmp[n * n - 1] = 1;
        res.push_back(tmp);
        return;
    }
    if (maze[i][j] == 0 || maze[i][j] == 2)
        return;

    maze[i][j] = 2;
    tmp[(n * i) + j] = 1;

    ratInMazeHelper(maze, i + 1, j, tmp, res);
    ratInMazeHelper(maze, i - 1, j, tmp, res);
    ratInMazeHelper(maze, i, j - 1, tmp, res);
    ratInMazeHelper(maze, i, j + 1, tmp, res);

    tmp[(n * i) + j] = 0;
    maze[i][j] = 1;
}
vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    // Write your code here.
    vector<vector<int>> res;
    vector<int> tmp(n * n, 0);
    ratInMazeHelper(maze, 0, 0, tmp, res);
    return res;
}