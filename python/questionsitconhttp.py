import requests as re
ANS = {
    "teamid": 7,
    "name": "Xanonymous",
    "chalid": -1,
    "answer": "",
    "diy": True
}
url = 'https://sitprac.herokuapp.com/countries/engname/chiname/chicapital/continent/area/population/nobel/longevity/gun/murder'
url2 = 'https://sitprac.herokuapp.com/records.json'
r = re.get(url).json()
# 1ans:
ANS['chalid'] = 0
pos1 = 0
while True:
    if r[pos1]['chiname'] == '海地':
        ANS['answer'] = r[pos1]['population']
        re.post(url2, ANS)
        #print(r[pos1]['population'])#
        break
    else:
        pos1 += 1
# 2ans:
ANS['chalid'] = 1
temp2 = list()
for x in range(len(r)):
    temp2.append([r[x]['longevity'], r[x]['engname']])
temp2.sort(reverse=True)
ANS['answer'] = temp2[0][1]
re.post(url2, ANS)
#print(temp2[0][1])#
# 3ans:
ANS['chalid'] = 2
temp3a = list()
temp3b = list()
for x in range(len(r)):
    if r[x]['continent'] == 'europe':
        temp3a.append(r[x])
for x in range(len(temp3a)):
    temp3b.append([float(temp3a[x]['population']) /
                   float(temp3a[x]['area']), temp3a[x]['engname']])
temp3b.sort(reverse=True)
ANS['answer'] = temp3b[4][1]
re.post(url2, ANS)
#print(temp3b[4][1])#
# 4ans:
# south_america,north_america,nobel
ANS['chalid'] = 3
temp4 = list()
for x in range(len(r)):
    if (r[x]['continent'] == 'south_america' or r[x]['continent'] == 'north_america')and(int(r[x]['nobel']) < 2):
        temp4.append([int(r[x]['area']), r[x]['engname']])
temp4.sort(reverse=True)
ANS['answer'] = temp4[0][1]
re.post(url2, ANS)
#print(temp4[0][1])#
# 5ans:
# gun,murder
ANS['chalid'] = 4
temp5a = list()
temp5b = list()
for x in range(len(r)):
    if(float(r[x]['gun']) > 40):
        temp5a.append([float(r[x]['murder']), r[x]['engname']])
temp5a.sort()
temp5a = temp5a[0][1]
for x in range(len(r)):
    temp5b.append([float(r[x]['murder']), r[x]['engname']])
temp5b.sort(reverse=True)
for x in range(len(temp5b)):
    if temp5b[x][1] == temp5a:
        ANS['answer'] = x+1
        re.post(url2, ANS)
        #print(x+1)#
        break
