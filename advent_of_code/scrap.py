arr1 = [1, 2, 3, 4, 5, 6, 7]
arr2 = [2, 3, 4, 5, 6]

def is_subarray(arr1, arr2, m, n):
    i = 0
    j = 0
    while i < n and j < m:
        if arr1[j] == arr2[i]:
            j = j + 1
        i = i + 1
    return j == m

if is_subarray(arr2, arr1, len(arr2), len(arr1)):
    print("Yes")