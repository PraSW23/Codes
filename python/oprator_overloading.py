class Number:
    def __init__(self,num):
        self.num = num

    def __add__(self,num2):
        return self.num + num2.num
    
    def __mul__(self,num):
        return self.num * num.num

    def __str__(self):
        return f"Decimal number {self.num}"

n1 = Number(34)
n2 = Number(63)

print(n1)

n3  = n1 + n2
print(n3)

n3 = n1 * n2
print(n3)