def merge_sort(values, first, last):
    '''[5]'''
    if first < last:
        middle = int((first + last) / 2)
        merge_sort(values, first, middle)
        merge_sort(values, middle + 1, last)
        merge(values, first, middle, middle + 1, last)
    


def merge(values, leftFirst, leftLast, rightFirst, rightLast):
    '''[6]'''
    arySize = rightLast - leftFirst + 1
    tempArray = [None] * len(values)
    index = leftFirst
    saveFirst = leftFirst

    while (leftFirst <= leftLast) and (rightFirst <= rightLast):
        if values[leftFirst] < values[rightFirst]:
            tempArray[index] = values[leftFirst]
            leftFirst += 1
        else:
            tempArray[index] = values[rightFirst]
            rightFirst += 1
        index += 1

    while leftFirst <= leftLast:
        tempArray[index] = values[leftFirst]
        leftFirst += 1
        index += 1
    
    while rightFirst <= rightLast:
        tempArray[index] = values[rightFirst]
        rightFirst += 1
        index += 1

    index = saveFirst
    while index <= rightLast:
        values[index] = tempArray[index]
        index += 1
