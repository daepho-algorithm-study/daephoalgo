x, y, w, h = map(int, input().split())

left = x
right = w - x
bottom = y
top = h - y

print(min(left, right, bottom, top))