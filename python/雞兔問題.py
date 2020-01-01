H = int(input('Please enter the amount of the head: '))
F = int(input('Please enter the amount of the foot: '))
if not((F-2*H)/2 == int((F-2*H)/2) or H-((F-2*H)/2) == int(H-((F-2*H)/2))) or ((F-2*H)/2 < 0 or H-((F-2*H)/2) < 0):
    print('ERROR!')
else:
    print('Chicken: ', int(H-((F-2*H)/2)), '\n', 'Rabbit: ', int((F-2*H)/2))
