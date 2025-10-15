#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Node
{
    map<string, Node *> children; // 트라이를 위한 주소 저장 구조체 정의
};

void dfs(Node *node, int floor); // dfs 함수 정의

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    Node *root = new Node(); // root 노드 동적 할당
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;               // 먹이 개수 입력
        vector<string> feed(k); // 먹이 정보 저장 배열 할당
        for (int j = 0; j < k; j++)
            cin >> feed[j]; // 먹이 정보 저장
        Node *temp = root;  // root 노드를 카리키는 노드 생성
        for (int j = 0; j < k; j++)
        {
            if (temp->children.count(feed[j]) == 0)
                temp->children[feed[j]] = new Node(); // 해당 노드가 없을 때 노드 생성
            temp = temp->children[feed[j]];           // 해당 노드 존재 시 이동
        }
    }
    dfs(root, 0); // root 노드에서 탐색 시작
    return 0;
}

void dfs(Node *node, int floor)
{
    for (auto child : node->children)
    {
        for (int i = 0; i < floor; i++)
            cout << "--";             // 해당 노드 깊이 출력
        cout << child.first << "\n";  // 해당 노드의 키 값을 출력
        dfs(child.second, floor + 1); // 한 단계 아래 깊이 탐색
    }
}