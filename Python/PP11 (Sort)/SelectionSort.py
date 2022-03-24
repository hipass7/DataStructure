
def selection_sort(values):
    '''[9]'''
    endIndex = len(values) - 1

    for current in range(endIndex):
        min = current
        for i in range(current + 1, len(values)):
            if values[i] < values[min]:
                min = i
            values[current], values[min] = values[min], values[current]
    

