a=int(input("enter mark 1 :"))
b=int(input("enter mark 2 :"))
c=int(input("enter mark 3 :"))
if(a>=b and a>c):
    if(b>c):
        print("a and b is big",(a+b)/2)
    else:
            print("a and c is big ",(a+b)/2)
elif("b>=c and b>=a"):
    if(a>c):
        print("b and a is big ",(a+b)/2)
    else:
        print("c and b is big ",(c+b)/2)
else:
    if(a>b):
        print("a and c is big ",(a+c)/2)
    else:
        print("c and b is big ",(c+b)/2)
                            

