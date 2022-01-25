(W,H,x,y,r)=map(int,raw_input().split())
if r<=x and r<=y and x<=W-r and y<=H-r : print "Yes"
else : print "No"
