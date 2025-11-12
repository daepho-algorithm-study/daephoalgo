xp = []
yp = []

for _ in range(3):
    x, y = map(int, input().split())
    
    xp.append(x)
    yp.append(y)
    
x4 = 0
if xp[0] == xp[1]:
    x4 = xp[2]
elif xp[0] == xp[2]:
    x4 = xp[1]
else:
    x4 = xp[0]

y4 = 0
if yp[0] == yp[1]:
    y4 = yp[2]
elif yp[0] == yp[2]:
    y4 = yp[1]
else:
    y4 = yp[0]
    
print(x4, y4)