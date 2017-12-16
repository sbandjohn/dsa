class Node:
	def __init__(self, id, next):
		self.id = id
		self.next = next

def node(d, a):
	if (a not in d):
		d[a] = Node(a,None)
	return d[a]
"""F(n) = F(n/2) + c
     ==  
     ====   
"""
def circle(st):
	N = 1
	while (True):
		p = st
		for i in range(1,N):
			if (p.next==None): return False,None
			p = p.next
		q = p
		print(N,p.id)
		for i in range(1,N+1):
			if (q.next == p): return True,(p.id, i)
			if (q.next == None): return False,None
			q = q.next
		N += 1

def move(a,n,k):
	print(a)
	if (k==0): return 
	r = n%k
	m = n//k
	for i in range(1,m):
		for j in range(0,k):
			tmp = a[j]
			a[j] = a[i*k+j]
			a[i*k+j] = tmp
	if (r==0): return
	for i in range(r):
		tmp = a[i]
		a[i] = a[m*k+i]
		a[m*k+i] = tmp
	move(a, k, k-r)

def intersect(a,b):
	p=a;
	q=b;
	c = None
	st = None
	while (p and q):
		if (p): print(p.id,p.value)
		if (q): print(q.id,q.value)
		while (p and (not q or p.value<q.value)):
			p = p.next
		while (q and (not p or  q.value<p.value)):
			q = q.next
		
		if (p and q and p.value == q.value):
			newNode = Node(0,None)
			newNode.value = p.value
			if (st==None):
				st=newNode
				c = st
			else:
				c.next = newNode
				c = c.next
			p = p.next
			q = q.next
	return st
	
def main():
	d = dict()
	while (True):
		a,b = map(int,(input().split()))
		if (a==0 and b==0): break
		node(d,a).next = node(d,b)
	while (True):
		a,b = map(int, input().split())
		if (a==-1): break
		node(d,a).value = b
		
	a,b = map(int, input().split())
	print(a,b)
	
	c = intersect(node(d,a),node(d,b))
	print("c=")
	if (c):
		p = c
		while (p):
			print(p.value)
			p = p.next
		print("---")
	else:
		print("None")
	"""
	st = int(input())
	a,b = circle(node(d,st))
	print(a,b)
	
	n,k = map(int,input().split())
	a = list(map(int, input().split()))
	move(a,n,k)
	print(a)"""
	

if __name__=="__main__":
	main()
	