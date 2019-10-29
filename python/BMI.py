while True:
    w = float(input('Please enter the weight: '))
    if w < 0:
        print('OVER.')
        break
    h = float(input('Please enter the height: '))
    print('BMI= ', w/((h/100)**2), '\n')
