
def bubble_sort(values):
    """[1]"""
    current = 0
    endIndex = len(values) - 1

    while current < endIndex:
        index = endIndex
        while index > current:
            if values[index] < values[index - 1]:
                values[index], values[index - 1] = values[index - 1], values[index]
            index -= 1
        current += 1



