
def solution(num, total):
    
    temp = total // num
    answer = []

    if num % 2 != 0:
        for i in range (num) :
            answer.append(temp + i - (num // 2))
    else:
        for i in range (num) :
            answer.append(temp + i + 1 -(num // 2))
        
    return answer
