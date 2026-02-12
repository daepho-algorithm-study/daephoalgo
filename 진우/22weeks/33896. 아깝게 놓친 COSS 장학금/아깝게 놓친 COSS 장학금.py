n = int(input())

students = []

for _ in range(n):
    name, score, risk, cost = input().split()
    score = int(score)
    risk = int(risk)
    cost = int(cost)
    coss = (score ** 3) // (cost * (risk + 1))
    # 튜플로 바로 정렬 키 구성
    # (-coss, cost, name) 순서로 튜플 만들기
    students.append((-coss, cost, name))

# 튜플 기준으로 sort
students.sort()

# 두 번째 학생 이름 출력
print(students[1][2])
