import sys
from collections import deque

input = sys.stdin.read().split()

def solution(input):
    idx = 0

    direction = []
    for i in range(11):
        plus = [0] * 11
        minus = [0] * 11
        plus[i] = 1
        minus[i] = -1
        direction.append(plus)
        direction.append(minus)

    M, N, O, P, Q, R, S, T, U, V, W = map(int, input[idx:idx+11])
    idx += 11

    result = 1
    zero = 0

    box = []
    for w in range(W):
        lv = []
        for v in range(V):
            lu = []
            for u in range(U):
                lt = []
                for t in range(T):
                    ls = []
                    for s in range(S):
                        lr = []
                        for r in range(R):
                            lq = []
                            for q in range(Q):
                                lp = []
                                for p in range(P):
                                    lo = []
                                    for o in range(O):
                                        ln = []
                                        for n in range(N):
                                            row = []
                                            for m in range(M):
                                                row.append(int(input[idx]))
                                                idx += 1
                                            ln.append(row)
                                        lo.append(ln)
                                    lp.append(lo)
                                lq.append(lp)
                            lr.append(lq)
                        ls.append(lr)
                    lt.append(ls)
                lu.append(lt)
            lv.append(lu)
        box.append(lv)

    queue = deque()
    for w in range(W):
        for v in range(V):
            for u in range(U):
                for t in range(T):
                    for s in range(S):
                        for r in range(R):
                            for q in range(Q):
                                for p in range(P):
                                    for o in range(O):
                                        for n in range(N):
                                            for m in range(M):
                                                if box[w][v][u][t][s][r][q][p][o][n][m] == 1:
                                                    queue.append((w,v,u,t,s,r,q,p,o,n,m))
                                                elif box[w][v][u][t][s][r][q][p][o][n][m] == 0:
                                                    zero += 1

    while queue:
        w,v,u,t,s,r,q,p,o,n,m = queue.popleft()
        cur = box[w][v][u][t][s][r][q][p][o][n][m]

        for d in direction:
            nw = w + d[0]
            nv = v + d[1]
            nu = u + d[2]
            nt = t + d[3]
            ns = s + d[4]
            nr = r + d[5]
            nq = q + d[6]
            np = p + d[7]
            no = o + d[8]
            nn = n + d[9]
            nm = m + d[10]

            if (
                0 <= nw < W and 0 <= nv < V and 0 <= nu < U and
                0 <= nt < T and 0 <= ns < S and 0 <= nr < R and
                0 <= nq < Q and 0 <= np < P and 0 <= no < O and
                0 <= nn < N and 0 <= nm < M
            ):
                if box[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] == 0:
                    box[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] = cur + 1
                    result = max(result, cur + 1)
                    zero -= 1
                    queue.append((nw,nv,nu,nt,ns,nr,nq,np,no,nn,nm))

    print(-1 if zero > 0 else result - 1)

solution(input)
