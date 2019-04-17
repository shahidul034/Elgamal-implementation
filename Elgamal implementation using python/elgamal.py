# MD Shahidul Salim (Shakib)
# ROll: 1507034
# CSE,KUET

def gen(g, p):
    E=[]
    my_set=set(E)
    for x in range(1, p):
        num=pow(g,x,p)
        my_set.add(num)
    return len(my_set)




def modInverse(a, m) :
	m0 = m
	y = 0
	x = 1
	if (m == 1) :
		return 0
	while (a > 1) :

		q = a // m
		t = m
		m = a % m
		a = t
		t = y
		y = x - q * y
		x = t

	if (x < 0) :
		x = x + m0

	return x

def nxtprimegen(n):
    m = n
    n = n + 100
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):

        if (prime[p] == True):
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 1
    for p in range(2, n):
        if prime[p]:
            if p > m:
                return p
            else:
                val = p

    return val



p=nxtprimegen(int(input("Select a large prime number: ")))

for x in range(1, p):
    if gen(x, p) == (p - 1):
        E1 = x
        break

print("Generator: ",E1)
while(1):
    d=int(input("Enter a private key: "))
    if d<=(p-1)and d>=1:
        break
print(d)
E2=pow(E1,d,p)
print("public key: (",E1,",",E2,",",p,")")
print("private key: ",d)
# Encryption

while(1):
    R = int(input("Select a random number(1<R<(p-1))"))
    if R<=(p-1)and R>=1:
        break



while(1):
    msg = int(input("Enter your msg(1<msg<(p-1)): "))
    if msg>=1 and msg<=(p-1) :
        break

C1=pow(E1,R,p)
C2=pow((pow(E2,R,p)*msg),1,p)
print("Encrypt msg: ",C2)

#Decrypt
de_msg=pow((modInverse(pow(C1,d),p)*C2),1,p)
print("de_msg: ",de_msg)


