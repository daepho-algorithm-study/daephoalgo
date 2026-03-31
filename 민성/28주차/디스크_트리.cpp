#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// 트라이를 구성하기 위한 주소 저장 구조체 정의
struct Node
{
    map<string, Node *> nxt;
};

// 디렉토리 구조 출력 함수 정의
void pf(Node *node, int depth);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    // root 노드 동적 할당
    Node *root = new Node();
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // 디렉토리 이름 저장 배열 할당
        vector<string> dir;
        // '\' 기준으로 문자열 끊어 받기
        cin >> s;
        stringstream ss(s);
        while (getline(ss, s, '\\'))
            dir.push_back(s);
        // root 노드를 가리키는 노드 생성
        Node *disk = root;
        for (int j = 0; j < dir.size(); j++)
        {
            // 해당 디렉토리가 존재하지 않으면 노드 생성
            if (disk->nxt.count(dir[j]) == 0)
                disk->nxt[dir[j]] = new Node();
            // 디렉토리 존재 시 하위 노드로 이동
            disk = disk->nxt[dir[j]];
        }
    }
    // 루트 노드에서부터 출력 시작
    pf(root, 0);
    return 0;
}

void pf(Node *node, int depth)
{
    // 사전순으로 상위 디렉토리에 연결된 하위 디렉토리 출력
    for (auto child : node->nxt)
    {
        // 깊이만큼 띄어쓰기 출력
        for (int i = 0; i < depth; i++)
            cout << " ";
        // 디렉토리 이름 출력
        cout << child.first << "\n";
        // 하위 디렉토리 주소로 이동
        pf(child.second, depth + 1);
    }
}