T = int(input())
for tc in range(0,T) :
	a=sorted(map(int,input().split(" ")))
	if a[0]**2+a[1]**2==a[2]**2 :
		print("YES")
	else:
		print("NO")
