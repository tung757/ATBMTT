def gcd(a,b):
    if(a%b==0):
        return b
    else:
        return gcd(b,a%b)
def nd(a,n):
    if(gcd(a,n)==1):
        x1,y1,x2,y2,r1,r2=0,1,1,0,n,a
        while(r2!=1):
            q=int(r1/r2)
            tg=r2
            r2=r1%r2
            r1=tg
            tg=x2
            x2=x1-q*x2
            x1=tg
            tg=y2
            y2=y1-q*y2
            y1=tg
        while(x2<0):
            x2=x2+n
        return x2
def cd(a):
    l=["á","à","ả","ạ","â","ă","ấ","ầ","ẩ","ậ","ắ","ằ","ẳ","ặ","è","é","ẻ","ẹ","ê","ề","ế","ể","ệ","ỉ","í","ì","ị","ỏ","ò","ó","ọ","ô","ồ","ố","ổ","ộ","ơ","ở","ờ","ớ","ợ","ù","ú","ủ","ụ","ỳ","ý","ỷ","ỵ","đ"]
    h=len(l)
    for i in range(h):
        l.append(l[i].upper())
    for i in range(len(l)):
        if(l[i]==a):
            return i
    return None
def dc(n):
    l=["á","à","ả","ạ","â","ă","ấ","ầ","ẩ","ậ","ắ","ằ","ẳ","ặ","è","é","ẻ","ẹ","ê","ề","ế","ể","ệ","ỉ","í","ì","ị","ỏ","ò","ó","ọ","ô","ồ","ố","ổ","ộ","ơ","ở","ờ","ớ","ợ","ù","ú","ủ","ụ","ỳ","ý","ỷ","ỵ","đ"]
    h=len(l)
    for i in range(h):
        l.append(l[i].upper())
    return l[n]
def enandde():
    a=int(input("Nhap so a : "))
    b=int(input("Nhap so b : "))
    s=input("Nhập chuỗi : ")
    m=""
    for i in range(len(s)):
        if cd(s[i])==None:
            if(s[i].isalpha()):
                if(s[i].isupper()):
                        m=m+chr((((ord(s[i])-ord("A"))*a+b)%26)+ord("A"))
                else:
                        m=m+chr((((ord(s[i])-ord("a"))*a+b)%26)+ord("a"))
            else:
                    m=m+s[i]
        else:
             m=m+dc((cd(s[i])*a+b)%100)
    print("Ban ma hoa la : ",m)
    s=""
    for i in range(len(m)):
        if cd(m[i])==None:
            if(m[i].isalpha()):
                if(m[i].isupper()):
                        s=s+chr((((ord(m[i])-ord("A"))*nd(a,26)-b)%26)+ord("A"))
                else:
                        s=s+chr((((ord(m[i])-ord("a"))*nd(a,26)-b)%26)+ord("a"))
            else:
                    s=s+m[i]
        else:
             s=s+dc((cd(m[i])*nd(a,100)-b)%100)
    print("Ban giai ma : ",s)
enandde()


