while True:
    sentence = input()  # 한 줄 입력

    if sentence == ".":  # 종료 조건
        break

    stack = []  # 괄호 체크용 스택 (list 사용)

    for c in sentence:  # 문자열을 하나씩 순회
        # 여는 괄호는 push
        if c in ["(", "["]:
            stack.append(c)

        # 닫는 소괄호 ')'
        elif c == ")":
            # 스택이 비어있지 않고 top이 '('이면 pop
            if stack and stack[-1] == "(":
                stack.pop()
            else:
                # 매칭 실패 → 오류 검출 위해 push 후 종료
                stack.append(c)
                break

        # 닫는 대괄호 ']'
        elif c == "]":
            # 스택이 비어있지 않고 top이 '['이면 pop
            if stack and stack[-1] == "[":
                stack.pop()
            else:
                # 매칭 실패 → 오류 검출 위해 push 후 종료
                stack.append(c)
                break

    # 스택이 비어 있으면 모든 괄호 정상 매칭
    if stack:
        print("no")
    else:
        print("yes")
