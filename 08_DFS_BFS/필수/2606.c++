#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> li;
vector<bool> visited;

void dfs(int num){
    for(int i = 1; i <= n; i++){
        if(li[num][i] == 1 && !visited[i]){
            visited[i] = true;
            dfs(i);
        }
    }
}

int main(){
    cin >> n >> m;
    li.assign(n+1, vector<int>(n+1, 0));
    visited.assign(n+1, false);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a>> b;
        li[a][b] = li[b][a] = 1;
    }

    visited[1] = true;
    dfs(1);

    int count = 0;;
    for(int i = 2; i <= n; i++){
        if(visited[i])
            count++;
    }

    cout << count << '\n';

    return 0;
}