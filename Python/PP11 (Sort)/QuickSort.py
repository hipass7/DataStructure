def split(values, first, last):
    '''[7]'''
    splitVal = values[first]
    saveFirst = first
    first += 1

    while True:
        onCorrectSide = True
        while onCorrectSide:
            if values[first] > splitVal:
                onCorrectSide = False
            else:
                first += 1
                onCorrectSide = (first <= last)

        onCorrectSide = (first <= last)
        while onCorrectSide:
            if values[first] <= splitVal:
                onCorrectSide = False
            else:
                last -= 1
                onCorrectSide = (first <= last)
        
        if first < last:
            values[first], values[last] = values[last], values[first]
            first += 1
            last -= 1

        if first > last:
            break

    splitPoint = last
    values[saveFirst], values[splitPoint] = values[splitPoint], values[saveFirst]
    return last
    
def quick_sort(values, first, last):
    '''[8]'''
    if first < last:
        splitPoint = split(values, first, last)
        quick_sort(values, first, splitPoint - 1)
        quick_sort(values, splitPoint + 1, last)
