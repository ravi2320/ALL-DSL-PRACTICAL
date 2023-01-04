def partition(arr, start, end):
    lb = start + 1
    ub = end
    pivot = arr[start]
    while True:
        while lb<=ub and arr[lb] <= pivot:
            lb += 1
        while lb <= ub and arr[ub] >= pivot:
            ub -= 1
        if lb <= ub:
            arr[lb], arr[ub] = arr[ub], arr[lb]
        else:
            break

    arr[start], arr[ub] = arr[ub], arr[start]
    return ub

def quick(arr, start, end):
    while start < end:
        part_pos = partition(arr, start, end)
        quick(arr, start, part_pos-1)
        quick(arr, part_pos+1, end)

arr = [50,40,30,20,10]
print(arr)
quick(arr, 0, len(arr)-1)
print(arr)