def find(n, amounts, num_len, num_items, result):
    pos = int()
    the_result = list()
    while(pos < num_len):
        if not(pos):
            the_result.append(n)
            amounts[num_items.index(n)] -= 1
            pos += 1
            continue
        tmp_pos = 0
        try:
            while(True):
                if((num_items[tmp_pos] != the_result[pos-1])and amounts[tmp_pos]):
                    the_result.append(num_items[tmp_pos])
                    amounts[tmp_pos] -= 1
                    break
                tmp_pos += 1
        except:
            result.append(
                int(
                    ''.join(
                        list(
                            map(
                                str, reversed(the_result+[9]*(num_len-pos))
                            )
                        )
                    )
                )
            )
            return
        pos += 1
    result.append(
        int(
            ''.join(
                list(
                    map(
                        str, the_result
                    )
                )
            )
        )
    )
    return


def main():
    data = sorted(
        list(map(int, input().split()))
    )
    num_items = list(set(data))
    num_amounts = list()
    result = list()
    num_len = len(data)
    for i in num_items:
        num_amounts.append(data.count(i))
    for u in num_items:
        find(u, num_amounts.copy(), num_len, num_items, result)
    print(min(result))


if __name__ == '__main__':
    main()