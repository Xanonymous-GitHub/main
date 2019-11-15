a, b, c = sorted(list(map(float, input().split())))
if(((a+b) > c)and((c-a) < b)):
    print('It is a triangle.')
    if(((a**2)+(b**2)) == (c**2)):
        print('-> also a Right triangle.')
        if(not(a-b)):
            print('-> Wow it\'s a Isosceles right triangle!')
else:
    print('not a triangle.')