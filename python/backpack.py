# 背包荷重
pack_weight = int(input())
# 物品重量
weight = list(map(int, input().split()))
# 物品價值
value = list(map(int, input().split()))
'''求最大價值'''
value_list = [0]*pack_weight
for i in range(len(weight)):
    for j in range(len(value_list)):
        tmp_value = value[i]*((j+1)//weight[i])
        if (weight[i] <= j+1)and(tmp_value > value_list[j]):
            value_list[j] = tmp_value
print(max(value_list))
