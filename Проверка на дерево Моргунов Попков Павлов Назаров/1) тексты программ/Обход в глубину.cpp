#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<bool> marks;

void dfs(int cur_node, const vector<vector<int>> G)
{
    marks[cur_node] = true;
    for (int i = 0; i < G[cur_node].size(); i++)
        if (!marks[G[cur_node][i]])
            dfs(G[cur_node][i], G);
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
    dfs(0, Graph);

    for (int i = 0; i < n; i++)
        if (!marks[i])
            result = false;

    fout << result;
    return 0;
}