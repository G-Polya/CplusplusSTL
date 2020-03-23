GreedBetterChange(Money, coin, d):
    for i = d to 1
        k[i] = M/c[i] //k is array. k1, k2, ... , kd
        M = M - c[i] * k[i]
    return k