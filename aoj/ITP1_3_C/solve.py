while 1:
    (a,b) = map(int,raw_input().split())
    if a==0 and b==0 : break;
    print min(a,b),max(a,b)
