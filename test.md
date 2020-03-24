BruteForceChange(coinValueList, total, numCoins, coinDict):
    for i := 0 to length(coinValueList):
        coinDict[coinValueList[i]]

    if total == 0:
        return (numCoins, coinDict)

    bestCoins := -1
    bestDict := make_dictionary()   // make empty dictionary

    for i := 0 to length(coinValueList):
        dictCopy := make_dictionary()

        for i:=0 to length(coinValueList):
            dictCopy[coin] = coinDict[coin]
        
        coin := conValueList[i]

        if coin <= total:
            dictCopy[coin] += 1

            (subCoins, subDict) := BruteForceChange(coinValueList, totla-coin, numCoins+1, dictCopy)

            if bestCoins == -1 && subCoins < bestCoins:
                bestCoins := subCoins
                bestDict := subDict
            
        
    return (bestCoins, bestDict)