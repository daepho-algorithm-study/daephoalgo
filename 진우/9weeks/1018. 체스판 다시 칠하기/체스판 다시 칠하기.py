N, M = map(int, input().split())

chess_board = [list(input().strip()) for _ in range(N)]
mn = []
for i in range(N - 8 + 1):
    for j in range(M - 8 + 1):
        start_W = 0
        start_B = 0
        for k in range(i, i + 8):
            for l in range(j, j + 8):
                if (k + l) % 2 == 0:
                    if chess_board[k][l] != 'W':
                        start_W += 1
                    if chess_board[k][l] != 'B':
                        start_B += 1
                else:
                    if chess_board[k][l] != 'B':
                        start_W +=1
                    if chess_board[k][l] != 'W':
                        start_B += 1
                
        mn.append(start_W)
        mn.append(start_B)

print(min(mn))