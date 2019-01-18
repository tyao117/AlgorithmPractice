

def coin_change(table,coins,price):
    for coin in coins:
        cur_price = price - 1
        while cur_price >= 0:
            if table[cur_price] == 10001:
                cur_price -= 1
                continue
            if table[cur_price + coin] > table[cur_price] + 1:
                table[cur_price + coin] = table[cur_price] + 1
            cur_price -=1
    i = price
    while table[i] == 10001:
        i += 1
    print(i, table[i])
            

if __name__ == "__main__":
    test_cases = int(input())
    while test_cases > 0:
        table = [10001] * 19999
        table[0] = 0
        target = int(input())
        coin_size = int(input())
        coins = []
        for i in range(coin_size):
            coins.append(int(input()))
        coin_change(table, coins, target)
        coins = []
        test_cases -= 1