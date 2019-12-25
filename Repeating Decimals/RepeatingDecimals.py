def repeating_decimal(num, den):

    if den == 0:
        return 'Undefined'
    if num == 0:
        return '0'
    neg = False 

    if num * den < 0:
        neg = True 
    if num % den == 0:
        return str(num / den)
    
    num = abs(num)
    den = abs(den)

    out = ""

    out += str(num // den)
    
    out += "."
    
    num_q = []

    while True:
        rem = num % den 
        num = rem * 10
        q = num // den 
        if rem == 0:
            for element in num_q:
                out += str(element[-1])
            break
        
        if [num, q ] not in num_q:
            num_q.append([num, q])
        else:
            ind = num_q.index([num, q])
            for element in num_q[:ind]:
                out += str(element[-1])
            out += "("
            for element in num_q[ind:]:
                out += str(element[-1])
            out += ")"
            break
    if neg == True:
        out = "-" + out
    return out
    

a = input("Enter nominator: ")
b = input("Enter denominator: ")


print(repeating_decimal(int(a), int(b)))
