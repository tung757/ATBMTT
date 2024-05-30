from random import randint
from math import sqrt

def gcd(a,b):
	if a%b==0:
		return b
	return gcd(b,a%b)
def snt(a):
	for i in range(2,int(sqrt(a))+1):
		if a%i==0:
			return False
	return a>1
def nd(a,n):
	r = [n,a]
	x = [0,1]
	i = 2
	while r[i-1]!=1:
		r.append(r[i-2]%r[i-1])
		q = r[i-2]//r[i-1]
		x.append(x[i-2]-q*x[i-1])
		i += 1 
	if (x[i-1]<0):
		return x[i-1]+n
	return x[i-1]
def somu(a,b,n):
	bi = ""
	f = 1
	while b!=0:
		bi = str(b%2) + bi
		b = b//2
	for i in range(0,len(bi)):
		f = f*f % n 
		if bi[i]=='1':
			f = f*a % n
	return f
#RSA
def en(t,e,n):
	t = list(t)
	for i in range(0,len(t)):
		t[i] = somu(ord(t[i]),e,n)
	return t
def de(t,d,n):
	for i in range(0,len(t)):
		t[i] = chr(somu(t[i],d,n))
	return ''.join(t)
p = randint(0,1000)
while (snt(p)==False):
	p = randint(0,1000)
q = randint(0,1000)
while (snt(q)==False or p==q):
	q = randint(0,1000)
print("p = "+str(p)+", q = "+str(q))

n = p*q 
phi = (p-1)*(q-1)
print("n = "+str(n)+", phi = "+str(phi))

e = randint(1,phi)
while (gcd(e,phi)!=1):
	e = randint(1,phi)
d = nd(e,phi)
print("e = "+str(e)+", d = "+str(d))

text = input("Nhập bản rõ: ")
print("Bản mã hóa: " +str(en(text,e,n)))
print("Bản giải mã: "+str(de(en(text,e,n),d,n)))



