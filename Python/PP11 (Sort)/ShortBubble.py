
def short_bubble(values, numValues):
    '''[10]'''
    current = 0
    sorted = False
    while current < numValues - 1 and not sorted:
        bubble_up(values, current, numValues - 1, sorted)
        current += 1

def bubble_up(values, startIndex, endIndex, sort):
    '''[11]'''
    sort = True
    index = endIndex
    while index > startIndex:
        if values[index] < values[index - 1]:
            values[index], values[index - 1] = values[index - 1], values[index]
            sort = False
        index -= 1
