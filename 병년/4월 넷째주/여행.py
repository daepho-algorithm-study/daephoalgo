T = int(input())
for tc in range(T):
    flag = True
    obj = {
        'N':0,
        'S':0,
        'E':0,
        'W':0
    }
    str = input().strip()
    for st in str:
        obj[st] += 1
    
    if (obj['N'] > 0 and obj['S'] == 0) or (obj['S'] > 0 and obj['N'] == 0):
        flag = False
    if (obj['E'] > 0 and obj['W'] == 0) or (obj['W'] > 0 and obj['E'] == 0):
        flag = False
    if flag:
        print("Yes")
    else :
        print("No")