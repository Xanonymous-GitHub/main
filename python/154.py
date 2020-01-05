import twder
import time
import requests
from prettytable import PrettyTable


def change1(c): return[c, twder.now(c)[1], twder.now(c)
                       [2], twder.now(c)[3], twder.now(c)[4]]


def translate(c):
    if c == "USD":
        currencyc = "美金"
    elif c == "HKD":
        currencyc = "港幣"
    elif c == "GBP":
        currencyc = "英鎊"
    elif c == "AUD":
        currencyc = "澳幣"
    elif c == "CAD":
        currencyc = "加拿大幣"
    elif c == "SGD":
        currencyc = "新加坡幣"
    elif c == "CHF":
        currencyc = "瑞士法郎"
    elif c == "JPY":
        currencyc = "日圓"
    elif c == "ZAR":
        currencyc = "南非幣"
    elif c == "SEK":
        currencyc = "瑞典幣"
    elif c == "NZD":
        currencyc = "紐元"
    elif c == "THB":
        currencyc = "泰幣"
    elif c == "PHP":
        currencyc = "菲國比索"
    elif c == "IDR":
        currencyc = "印尼幣"
    elif c == "EUR":
        currencyc = "歐元"
    elif c == "KRW":
        currencyc = "韓元"
    elif c == "VND":
        currencyc = "越南盾"
    elif c == "MYR":
        currencyc = "馬來幣"
    elif c == "CNY":
        currencyc = "人民幣"
    else:
        currencyc = print("錯誤")
    return(currencyc)


continue1 = 1
continue2 = 2
continue3 = 2
continue4 = 2
while continue1 == 1 or continue2 == 2 or continue2 == 2 or continue4 == 2:
    choice = int(input("請選擇服務項目：1.查詢所有幣別匯率 2.查詢特定幣別匯率 3.匯率換算 4.開啟匯率通知:"))
    if choice == 1:
        schedul = PrettyTable(["幣別 ", "現金買入", "現金賣出", "即期買入", "即期賣出"])
        schedul.add_row(change1("USD"))
        schedul.add_row(change1("HKD"))
        schedul.add_row(change1("GBP"))
        schedul.add_row(change1("AUD"))
        schedul.add_row(change1("CAD"))
        schedul.add_row(change1("SGD"))
        schedul.add_row(change1("CHF"))
        schedul.add_row(change1("JPY"))
        schedul.add_row(change1("ZAR"))
        schedul.add_row(change1("SEK"))
        schedul.add_row(change1("NZD"))
        schedul.add_row(change1("THB"))
        schedul.add_row(change1("PHP"))
        schedul.add_row(change1("IDR"))
        schedul.add_row(change1("EUR"))
        schedul.add_row(change1("KRW"))
        schedul.add_row(change1("VND"))
        schedul.add_row(change1("MYR"))
        schedul.add_row(change1("CNY"))
        print(schedul)
        print("更新時間：", twder.now("USD")[0])
        continue1 = int(input("繼續查詢其他幣別？1.使用其他功能 2.離開："))
        if continue1 == 2:
            break
    elif choice == 2:
        continue2 = 1
        while continue2 == 1:
            print("您可以查詢以下幣別的匯率：")
            print(','.join(twder.currencies()))
            currency = input("請輸入您要查詢的幣別(請注意大小寫）：")
            print("幣別：%s(%s)" % (currency, translate(currency)))
            print("現金買入匯率為：%2f" % (float(twder.now(currency)[1])))
            print("現金賣出匯率為：%2f" % (float(twder.now(currency)[2])))
            print("即期買入匯率為：%2f" % (float(twder.now(currency)[3])))
            print("即期賣出匯率為：%2f" % (float(twder.now(currency)[4])))
            continue2 = int(input("繼續查詢其他幣別？1.繼續 2.使用其他功能 3.離開："))
            if continue2 == 2 or continue2 == 3:
                break
    elif choice == 3:
        continue3 = 1
        while continue3 == 1:
            choicec = input("請選擇（1.台幣換外幣2.外幣換台幣3.外幣換外幣）：")
            if choicec == "1":
                currency = input("請輸入想換算的幣別:")
                ratechoice = int(
                    input("請選擇想使用匯率種類：1.現金買入匯率2.現金賣出匯率3.即期買入匯率4.即期賣出匯率:"))
                amount1 = int(input("請輸入新台幣金額:"))
                rate = float(twder.now(currency)[ratechoice])
                amount2 = amount1/rate
                print("NT%d=%s%.2f" % (amount1, currency, amount2))
            elif choicec == "2":
                currency = input("請輸入想換算的幣別:")
                ratechoice = int(
                    input("請選擇想使用匯率種類：1.現金買入匯率2.現金賣出匯率3.即期買入匯率4.即期賣出匯率:"))
                amount3 = int(input("請輸入金額:"))
                rate = float(twder.now(currency)[ratechoice])
                amount4 = amount3*rate
                print("%s%.2f=NT%d" % (currency, amount3, amount4))
            elif choicec == "3":
                currency1 = input("請輸入想換算的幣別1:")
                ratechoice = int(
                    input("請選擇想使用匯率種類：1.現金買入匯率2.現金賣出匯率3.即期買入匯率4.即期賣出匯率:"))
                amount5 = int(input("請輸入金額:"))
                currency2 = input("請輸入想換算成的幣別2:")
                rate1 = float(twder.now(currency1)[ratechoice])
                rate2 = float(twder.now(currency2)[ratechoice])
                amount6 = (amount5*rate1)/rate2
                print("%s%.2f=%s%.2f" %
                      (currency1, amount5, currency2, amount6))
            else:
                print("輸入錯誤")
                continue3 = int(input("繼續查詢其他幣別？1.繼續2.使用其他功能 3.離開："))
                if continue3 == 2 or continue3 == 3:
                    break
    elif choice == 4:
        print("需要有密碼才能啟動此功能！")
        code = input("請輸入密碼：")
        if code == "a0603":
            continue4 = 1
            while continue4 == 1:
                currency = input("請輸入您要需要提醒的幣別：")
                ratechoice = int(
                    input("請選擇需要提醒的匯率種類：1.現金買入匯率2.現金賣出匯率3.即期買入匯率4.即期賣出匯率:"))
                rate = input("請輸入需要提醒的匯率:")
                compare = (input("請輸入要大於還是小於此匯率時需要提醒（1.大於 2.小於):"))
                frequency = int(input("請輸入提醒的間隔（單位：分鐘):"))
                number = int(input("請輸入需要提醒的次數"))
                if compare == "1":
                    compare = ">"
                elif compare == "2":
                    compare = "<"
                if ratechoice == 1:
                    ratetype = "現金買入匯率"
                elif ratechoice == 2:
                    ratetype = "現金賣出匯率"
                elif ratechoice == 3:
                    ratetype = "即期買入匯率"
                elif ratechoice == 4:
                    ratetype = "即期賣出匯率"
                else:
                    print("匯率種類輸入錯誤，請重新輸入！")
                    break
                print("當%s%s%s%s元時提醒" % (currency, ratetype, compare, rate))
                print("提醒%d次，每次間隔%d分鐘" % (number, frequency))
                check = input("請確認以上提醒資訊是否正確(Y/N)")
                if check == "Y" or "y":
                    counterLine = 0
                    if compare == ">":
                        while True:
                            if float(twder.now(currency)[ratechoice]) > float(rate):
                                print("開啟提醒")
                                url_ifttt = "https://maker.ifttt.com/trigger/currency_remind/with/key/OQELEzFyBnBpzUV6c1-jl" + \
                                    "?value1=" + \
                                    translate(currency)+"的"+ratetype+"為" + \
                                    twder.now(currency)[ratechoice]+"元!"
                                res1 = requests.get(url_ifttt)
                                counterLine += 1
                                print("已傳送%d次" % (counterLine))
                            if counterLine >= number:
                                print("已完成")
                                break
                            time.sleep(60*frequency)
                    elif compare == "<":
                        while True:
                            if float(twder.now(currency)[ratechoice]) < float(rate):
                                print("開啟提醒")
                                url_ifttt = "https://maker.ifttt.com/trigger/currency_remind/with/key/OQELEzFyBnBpzUV6c1-jl" + \
                                    "?value1=" + \
                                    translate(currency)+"的"+ratetype+"為" + \
                                    twder.now(currency)[ratechoice]+"元!"
                                res1 = requests.get(url_ifttt)
                                counterLine += 1
                                print("已傳送%d次" % (counterLine))
                            if counterLine >= number:
                                print("已完成")
                                break
                            time.sleep(60*frequency)
                    else:
                        print("輸入錯誤，請重新輸入！")
                        continue
                elif check == "N" or "n":
                    print("請重新設定")
                    continue
            continue4 = int(input("繼續查詢其他幣別？1.繼續2.使用其他功能 3.離開："))
            if continue4 == 2 or continue4 == 3:
                break
    else:
        print("輸入錯誤，請重新輸入！")
        continue
    if continue2 == 3 or continue3 == 3 or continue4 == 3:
        break
    print("歡迎下次再使用")
