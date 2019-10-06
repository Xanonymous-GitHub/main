''' Eight Queen Problem by Xanonymous. 20190430 '''
count=1
def PTQ(maps,result,m):
    #Stop after placing more than 8 lines.
    if m==9:
        drawboard(result)
        print()
        return
    #Check if the remaining maps have spaces.
    #Check if it is just starting to be placed.
    if m!=1:
        for check in list(range(m-1,8)):
            if not 0 in maps[check]:return
    #Place the queen.
    for pos in range(8):
        if maps[m-1][pos]!=0:continue
        else:
            result.append([m,pos+1])
            #Modifly the map.
            #Just bottom left, bottom and bottom right.
            for modiflybottom in range(8-m):
                if maps[m+modiflybottom][pos]==0:
                    maps[m+modiflybottom][pos]=m
            for modiflyleft in range(min([pos,8-m])):
                if maps[m+modiflyleft][pos-modiflyleft-1]==0:
                    maps[m+modiflyleft][pos-modiflyleft-1]=m
            for modiflyright in range(min([8-pos-1,8-m])):
                if maps[m+modiflyright][pos+modiflyright+1]==0:
                    maps[m+modiflyright][pos+modiflyright+1]=m
            #RECURSION.
            PTQ(maps,result,m+1)
            #BACKTRACKING.
            for modiflybottom in range(8-m):
                if maps[m+modiflybottom][pos]==m:
                    maps[m+modiflybottom][pos]=0
            for modiflyleft in range(min([pos,8-m])):
                if maps[m+modiflyleft][pos-modiflyleft-1]==m:
                    maps[m+modiflyleft][pos-modiflyleft-1]=0
            for modiflyright in range(min([8-pos-1,8-m])):
                if maps[m+modiflyright][pos+modiflyright+1]==m:
                    maps[m+modiflyright][pos+modiflyright+1]=0
            result.pop()
def drawboard(result):
    global count
    print('Number',count)
    for y in range(8):
        for x in range(8):
            print('●' if [y+1,x+1] in result else '○',end=' ')
        print()
    count+=1
def main():
    #Generate a blank board.
    maps=list([0 for e in range(8)] for e in range(8))
    PTQ(maps,[],1)
main()