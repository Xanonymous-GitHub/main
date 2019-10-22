import sys
sys.setrecursionlimit(10000000)
# > The recursive range of the title requirement may exceed the limit.
while True:
        # > The problem requires multiple test materials.
    try:
        i, j = map(int, input().split())
        # > i,j is the range of data entered by user.
    except:
        break
        # > Stop the program when the input is over.

    def caculate(i, j, maxlength, tmp, step):
        if i > j:
            print(maxlength)
            return
            # > Print out the maximum length and end the def when out of range.
        while True:
                # > start to caculate the 3n+1 of tmp.
            step += 1
            # > Recording steps.
            if tmp == 1:
                break
                # > Stop calculation until the calculated value is equal to 1.
            tmp = (3*tmp+1 if tmp % 2 != 0 else tmp/2)
            # > If the number is odd, multiply by 3 and add 1 else divide by 2.
        if step > maxlength:
            maxlength = step
            # > If the steps in this number is greater than known, replace it.
        return caculate(i+1, j, maxlength, i+1, 0)
        # > Use recursive to calculate the next number.
    print(i, j, end=' ')
    # > Display the range of the input first and leave a gap.
    if i > j:
        i, j = j, i
        # > Exchange to ensure that i is the starting calculation point.
    caculate(i, j, -1, i, 0)
    # > Start the first calculation.
