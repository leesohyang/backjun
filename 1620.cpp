#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int n, m, start;
vector<int> map[1001];
int ch_dfs[1001], ch_bfs[1001];
void DFS(int v, int start) {
    printf("%d ", start);
    for (int i = 0; i < map[start].size(); i++) {
        if (ch_dfs[map[start][i]] == 0) {
            ch_dfs[map[start][i]] = 1;
            DFS(v + 1, map[start][i]);
        }
    }
    
}
int main() {
    
    ifstream cin;
    cin.open("input.txt");
    int a, b;
    cin >> n >> m >> start;
    queue<int> Q;
  
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    for (int i = 1; i <= m; i++) {
        sort(map[i].begin(), map[i].end());
    }
    ch_dfs[start] = 1;
    DFS(0, start);
    puts("");
    Q.push(start);
    ch_bfs[start] = 1;
    while(!Q.empty()) {
        int x = Q.front();
        Q.pop();
        printf("%d ", x);
        for (int i = 0; i < map[x].size(); i++) {
            if (ch_bfs[map[x][i]] == 0) {
                ch_bfs[map[x][i]] = 1;
                Q.push(map[x][i]);
            }
        }
    }

    return 0;
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
