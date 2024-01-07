#include <bits/stdc++.h>
using namespace std;
void printq(queue<pair<pair<int, int>, pair<int, int>>> q) {
    cout<<"-------Queue is ---------"<<endl;
    while(!q.empty()) {
        cout<<"X :"<<q.front().first.first<<endl;
        cout<<"Y: "<<q.front().first.second<<endl;
        cout<<"steps : "<<q.front().second.first<<endl;
        cout<<"dir : "<<q.front().second.second<<endl;
        cout<<endl;
    q.pop();
    }
}
int ambi(int N)
{
    // x,y,steps,direction
    queue<pair<pair<int, int>, pair<int, int>>> q;
    set<pair<pair<int, int>,int>> s;

    q.push({{0, 1}, {1, 0}});
    s.insert({{0, 1},0});

    q.push({{0, -1}, {1, 0}});
    s.insert({{0, -1},0});

    q.push({{1, 0}, {1, 1}});
    s.insert({{1, 0},1});

    q.push({{-1, 0}, {1, 1}});
    s.insert({{-1, 0},1});

    // printq(q);

    int currsteps = 0;

    while (true)
    {
        int currx = q.front().first.first;
        int curry = q.front().first.second;
        int steps = q.front().second.first;
        int dir = q.front().second.second;
        q.pop();

        if (steps == N)
            currsteps++;
        if (steps > N)
            break;

        if (dir == 0)
        {
            int newx = currx + 1;
            if (s.find({{newx, curry},1}) == s.end())
            {
                s.insert({{newx, curry},1});
                q.push({{newx, curry}, {steps + 1, 1}});
            }
            newx = currx - 1;
            if (s.find({{newx, curry},1}) == s.end())
            {
                s.insert({{newx, curry},1});
                q.push({{newx, curry}, {steps + 1, 1}});
            }
        }

        else
        {
            int newy = curry + 1;
            if (s.find({{currx, newy},0}) == s.end())
            {
                s.insert({{currx, newy},0});
                q.push({{currx, newy}, {steps + 1, 0}});
            }
            newy = curry - 1;
            if (s.find({{currx, curry},0}) == s.end())
            {
                s.insert({{currx, curry},0});
                q.push({{currx, newy}, {steps + 1, 0}});
            }
        }
        // printq(q);

    }

    return currsteps;
}




void dfs(pair<int,int> node,int steps, set<pair<int,int>> &ans,int dir,int N) {
    if(steps > N) return;
    else if(steps == N) {
        ans.insert(node);
        return;
    }
    int currx = node.first;
    int curry = node.second;


    if (dir == 0)
        {
           dfs({currx+1,curry},steps+1,ans,1,N);
           dfs({currx-1,curry},steps+1,ans,1,N);
        }

        else
        {
           dfs({currx,curry-1},steps+1,ans,0,N);
           dfs({currx,curry+1},steps+1,ans,0,N);
        }

}
int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;
    set<pair<int,int>> ans;
    dfs({0,1},1,ans,0,n);
    dfs({0,-1},1,ans,0,n);
    dfs({1,0},1,ans,1,n);
    dfs({-1,0},1,ans,1,n);

    cout<<"Ans: "<<ans.size()<<endl;
    return 0;
}