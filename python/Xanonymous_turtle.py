import turtle


def star():
    print('>  畫星星囉~')
    print('>  直徑為d,角數為n;d建議為600,n太大會畫很久')
    d = int(input('d= '))
    n = int(input('n= '))
    b = int(input('寬度?(1~5,建議不要超過5喔)'))
    bolder = input('外框甚麼顏色?')
    color = input('甚麼顏色來填滿?')
    print('>  開始囉~請看畫面')
    t = turtle.Pen()
    t.speed(0)
    t.ht()
    t.screen.title('畫星星-Xanonymous')
    t.pensize(b)
    t.color(bolder)
    t.fillcolor(color)
    t.begin_fill()
    t.forward(-(d/2))
    for x in range(n):
        t.forward(d)
        t.left(180-360/n)
    t.end_fill()
    print('\n畫好了\n')
    input()


def knner():
    print('>  畫輻射型囉~')
    print('>  n太大會畫很久,建議在200到1000之間')
    n = int(input('n= '))
    b = int(input('寬度?(1~5,建議不要超過5喔)'))
    bolder = input('外框甚麼顏色?')
    print('>  開始囉~請看畫面')
    t = turtle.Pen()
    t.speed(0)
    t.ht()
    t.screen.title('畫輻射-Xanonymous')
    t.pensize(b)
    t.color(bolder)
    for x in range(n):
        t.forward(x)
        t.right(90+500/(n))
    print('\n畫好了\n')
    input()


def angle():
    print('>  畫圓圓囉~')
    d = int(input('>  半徑(150以下比較好)= '))
    a = int(input('角度= '))
    b = int(input('寬度?(1~5,建議不要超過5喔)'))
    bolder = input('外框甚麼顏色?')
    color = input('甚麼顏色來填滿?')
    print('>  開始囉~請看畫面')
    t = turtle.Pen()
    t.ht()
    t.screen.title('畫圓圓-Xanonymous')
    t.speed(0)
    t.pensize(b)
    t.color(bolder)
    t.fillcolor(color)
    t.begin_fill()
    for x in range(0, 360, a):
        t.setheading(x)
        t.circle(d)
    t.end_fill()
    print('\n畫好了\n')
    input()


print('<Xanonymous Python turtle program 1.0.181025>\n')
c = input('目前版本內建3種圖形。\n>  1是星星，2是輻射圖，3是圈圈。\n>  你想畫什麼?\n')
if c == '1':
    star()
if c == '2':
    knner()
if c == '3':
    angle()
