def inrow(n):
    a = [1]
    for i in range(1,len(n)):
        a.insert(i,n[i-1]+n[i])
    a.insert(len(n),1)
    return a

def pascal(k):
    n = [1]
    for i in range(0,k):
        print(n)
        n = inrow(n)
        
pascal(8)