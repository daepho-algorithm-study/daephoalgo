X = int(input())  # 사용자로부터 X번째 분수 위치를 입력받음

line = 1  # 현재 몇 번째 대각선(line)인지 저장
while X > line:
    X -= line   # X가 현재 대각선의 개수보다 크면, X에서 현재 대각선 개수만큼 빼고
    line += 1   # 다음 대각선으로 이동

# line 번째 대각선 안에서 X번째 분수의 분자(i)와 분모(j) 계산
if line % 2 == 0:   # 짝수 대각선(line이 짝수)
    i = X            # 분자 증가, 분모 감소
    j = line - X + 1
else:               # 홀수 대각선(line이 홀수)
    i = line - X + 1 # 분자 감소, 분모 증가
    j = X

print(f"{i}/{j}")  # 결과 출력 (분자/분모)
