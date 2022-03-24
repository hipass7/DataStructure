
def reheap_down(elements, root, bottom):
    '''[2]'''
    leftChild = root * 2 + 1
    rightChild = root * 2 + 2
    if leftChild <= bottom:
        if leftChild == bottom:
            maxChild = leftChild
        else:
            if elements[leftChild] <= elements[rightChild]:
                maxChild = rightChild
            else:
                maxChild = leftChild
        if elements[root] < elements[maxChild]:
            elements[root], elements[maxChild] = elements[maxChild], elements[root]
            reheap_down(elements, maxChild, bottom)

def heap_sort(values, numValues):
    '''[3]'''
    index = int(numValues / 2) - 1
    while index >= 0:
        reheap_down(values, index, numValues - 1)
        index -= 1
    
    index = numValues - 1
    while index >= 1:
        values[0], values[index] = values[index], values[0]
        reheap_down(values, 0, index - 1)
        index -= 1

def get_height(values, start, numValues):
    if start > numValues or start > numValues / 2 - 1:
        return 0
    l_height = get_height(values, start * 2 + 1, numValues)
    r_height = get_height(values, start * 2 + 2, numValues)

    if l_height > r_height:
        result = l_height + 1
    else:
        result = r_height + 1

    return result

def get_height_sum(values, numValues):
    index = 0
    sum = 0
    for index in range(numValues):
        sum += get_height(values, index, numValues - 1)

    print("sum of heights = ", sum)
