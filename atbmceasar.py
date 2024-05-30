import random
def enande():
    s=input("Nhập chuỗi : ")
    k=int(input("Nhập khóa k : "))
    m="";
    for i in range(len(s)):
        if s[i].isalpha():
            if s[i].isupper():
                m=m+chr((ord(s[i])-ord("A")+k)%26+ord("A"))
            else:
                m=m+chr((ord(s[i])-ord("a")+k)%26+ord("a"))
        else:
            m=m+s[i]
    print("Bản mã hóa là : ",m)
    s=""
    for i in range(len(m)):
        if m[i].isalpha():
            if m[i].isupper():
                s=s+chr((ord(m[i])-ord("A")-k)%26+ord("A"))
            else:
                s=s+chr((ord(m[i])-ord("a")-k)%26+ord("a"))
        else:
            s=s+m[i]
    print("Bản giải mã là : ",s)
print(ord("à"))
