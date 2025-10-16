result = 0
credit = 0

for tc in range(20):
    arr = list(input().split())

    grade = {"A+": 4.5, "A0": 4.0, "B+": 3.5,
             "B0": 3.0, "C+": 2.5, "C0": 2.0,
             "D+": 1.5, "D0": 1.0, "F": 0.0}
    
    score = float(arr[1])
    
    if arr[2] != "P":
        credit += score
        result += score * grade[arr[2]]

print(result / credit)


