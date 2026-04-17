import sys
import os
sys.stdin = open(os.path.join(os.path.dirname(__file__), "input.txt"))
from collections import deque

T = int(input())
for tc in range(T):
    answer = 0
    V, E = map(int, input().split())
    graph = [[] for _ in range(V + 1)]
    vistied = [False for _ in range(V + 1)]
    
    for _ in range(E) :
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    S, G = map(int, input().split())
    
    def bfs (s) :
        q = deque([[s, 0]])
        vistied[s] = True
        
        while q :
            cur, depth = q.popleft()
            if cur == G:
                return depth
            for next in graph[cur]:
                if not vistied[next]:
                    vistied[next] = True
                    q.append([next, depth + 1])
        return 0
    answer = bfs(S)
        
    print(f'#{tc + 1} {answer}')