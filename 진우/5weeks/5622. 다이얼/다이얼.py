text = input().strip()

# A~Z 다이얼 값 매핑
dial = [
    3,3,3,   # A,B,C
    4,4,4,   # D,E,F
    5,5,5,   # G,H,I
    6,6,6,   # J,K,L
    7,7,7,   # M,N,O
    8,8,8,8, # P,Q,R,S
    9,9,9,   # T,U,V
    10,10,10,10 # W,X,Y,Z
]

result = 0
for c in text:
    result += dial[ord(c) - ord('A')]

print(result)
