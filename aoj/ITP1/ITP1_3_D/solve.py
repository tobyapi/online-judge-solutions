(a,b,c) = map(int, raw_input().split())
print len([x for x in range(a,b+1) if c % x == 0])
