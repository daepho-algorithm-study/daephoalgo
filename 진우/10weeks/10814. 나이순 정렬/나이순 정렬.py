def get_age(person):
    return person[0]
# 정렬 기준 함수
# person = (나이, 이름) 형태의 튜플
# person[0] → 나이
# "나이만 반환"


n = int(input())  # 회원 수 입력

arr = []

# 입력값 저장
for _ in range(n):
    age, name = input().split()
    arr.append((int(age), name))  # (나이, 이름) 형태로 리스트에 저장


# 나이 기준 정렬 (stable sort)
# key=get_age → get_age(person)를 호출하여 person[0]을 기준으로 정렬
# 파이썬의 sort()는 안정 정렬
arr.sort(key=get_age)


# 정렬된 결과 출력
for age, name in arr:
    print(age, name)
