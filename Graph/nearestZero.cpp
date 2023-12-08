#include <bits/stdc++.h>
using namespace std;
// here instead of dist the matrix mat itself can be used and directly assign the dist as it will always be the shortest
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{

    int maxrow = mat.size();
    int maxcol = mat[0].size();

    vector<vector<int>> vis(maxrow, vector<int>(maxcol, 0));
    vector<vector<int>> dis(maxrow, vector<int>(maxcol, 0));

    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < maxrow; i++)
    {
        for (int j = 0; j < maxcol; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        dis[row][col] = dist;
        //mat[row][col] =  dist;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < maxrow && ncol >= 0 && ncol < maxcol && !vis[nrow][ncol])
            {
                q.push({{nrow, ncol}, dist + 1});
                vis[nrow][ncol] = 1;
            }
        }
    }

    return dis;
    //return mat;
}
int main()
{
    return 0;
}