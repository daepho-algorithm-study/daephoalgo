def solution(message, spoiler_ranges):
    N = len(message)
    spo_idx = []
    for spoiler_range in spoiler_ranges:
        spo_idx += [*range(spoiler_range[0], spoiler_range[1]+1)]

    norm_words = set()
    vip_words = set()
    start, idx = 0, 0
    for i in range(N+1):
        is_spo = any(j in spo_idx for j in range(start, i))
        if i == N or message[i] == ' ':
            # print(f"단어: '{message[start:i]}', start={start}, i-1={i-1}, range={list(range(start,i))}, is_spo={is_spo}")
            if is_spo:
                if message[start:i] not in norm_words:
                    vip_words.add(message[start:i])
            else:
                norm_words.add(message[start:i])
                vip_words.discard(message[start:i])

            start = i+1
            idx += 1
    
    return len(vip_words)