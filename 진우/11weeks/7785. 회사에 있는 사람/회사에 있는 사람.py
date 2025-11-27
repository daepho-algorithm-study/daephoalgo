n = int(input())  # 출입 기록의 개수 입력

work = set()  # 현재 회사 안에 있는 사람들을 저장하는 집합 (중복 없음)

for _ in range(n):
    name, log = input().split()  # 이름과 출입 기록(enter/leave) 입력받기

    if log == "enter":
        work.add(name)      # enter → 회사에 들어옴 → 집합에 추가
    else:
        work.remove(name)   # leave → 회사에서 나감 → 집합에서 제거

# set은 순서가 없기 때문에 정렬을 위해 리스트로 변환
people = list(work)

# 문자열 내림차순 정렬 (사전 역순)
people.sort(reverse=True)

# 출력
for i in range(len(people)):
    print(people[i])
