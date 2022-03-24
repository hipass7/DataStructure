def min_index(values, start, end):
    index_of_min = start
    index = start + 1
    while index <= end:
        if values[index] < values[index_of_min]:
            index_of_min = index
        index += 1
    return index_of_min


def tag_sort(values, num):
    end_index = num - 1
    current = 0
    while current < end_index:
        temp = min_index(values, current, end_index)
        values[current], values[temp] = values[temp], values[current]
        current += 1