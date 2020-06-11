#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
vector<bool> marks;

void bfs(int n, const vector<vector<int>> G)
{
    queue <int> q;
    q.push(0);
    marks[0] = true;

    while (!q.empty())
    {
        int cur_node = q.front();
        q.pop();
        for (int i : G[cur_node])
            if (!marks[i])
            {
                q.push(i);
                marks[i] = true;
            }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    ifstream fin("test.txt");
    ofstream fout("res.txt");

    int n, m;
    fin >> n >> m;
    bool result = true;
    if (m != n - 1)
    {
        fout << "0";
        return 0;
    }

    vector<vector<int>> Graph(n);
    int a, b;

    for (int i = 0; i < m; i++)
    {
        fin >> a >> b;
        Graph[a - 1].push_back(b - 1);
        Graph[b - 1].push_back(a - 1);
    }

    marks.assign(n, false);
    bfs(0, Graph);

    for (int i = 0; i < n; i++)
        if (!marks[i])
            result = false;

    fout << result;
    return 0;
}
