num = open('QS.txt', 'r')
lines = num.readlines()
counter = 0
numbers = []

# Reading the Text File
for line in lines:
    numbers.append(int(line))
    counter = counter + 1

# Global counter for the total number of comparisons
count = 0

def swap(A, i, j):
    temp = A[i]
    A[i] = A[j]
    A[j] = temp
    return A


# First part of the assignment
def partitioning_first(A, l, r):
    global count
    # Not Relevant
    if r <= l:
        return
    elif r - l == 1:
        # Just Two Elements in the Array
        count = count + 1
        if A[r] < A[l]:
            A = swap(A, l, r)
    else:
        # Actual Recursion step
        count = count + (r - l)
        p = A[l] # First Element as Pivot
        i = l + 1
        for j in range(l + 1, r + 1): # Relevant parts of the Array
            if A[j] < p:
                A = swap(A, i, j)
                i = i + 1
        A = swap(A, i - 1, l)

        # Recursion Steps
        partitioning_first(A, l, i - 2) # Left Part of the Array
        partitioning_first(A, i, r) # Right Part of the Array


def partitioning_last(A, l, r):
    global count
    if r - l == 1:
        count = count + (r - l) # Incrementing Count(Number of Comparisons)
        if A[r] < A[l]:
            A = swap(A, l, r)
    elif r <= l:
        count = count + 0
    else:
        count = count + (r - l) # Incrementing Count(Number of Comparisons)
        p = A[r] # Last Element as Pivot
        i = r - 1
        for j in range(r - 1, l - 1, -1):
            if A[j] > p:
                A = swap(A, i, j)
                i = i - 1
        A = swap(A, i + 1, r)

        # Recursion Steps
        partitioning_last(A, l, i) # Left Part of the Array
        partitioning_last(A, i + 2, r) # Right Part of the Array

# Second Part of the Assignment
def partitioning_LastReplace(A, l, r):
    global count
    if r <= l:
        return
    elif r - l == 1:
        count = count + (r - l) # Incrementing Count(Number of Comparisons)
        if A[r] < A[l]:
            A = swap(A, l, r)
    else:
        count = count + (r - l) # Incrementing Count(Number of Comparisons)

        # Swapping First and Last Element
        A = swap(A, l, r)
        p = A[l] # First Element as Pivot
        i = l + 1
        for j in range(l + 1, r + 1):
            if A[j] < p:
                A = swap(A, i, j)
                i = i + 1
        A = swap(A, i - 1, l)

        # Recursion Steps
        partitioning_LastReplace(A, l, i - 2) # Left Part of the Array
        partitioning_LastReplace(A, i, r) # Right Part of the Array


def findMedian(A, l, r):
    if r <= l:
        return -1
    else:
        mid = l + (r - l) // 2
        if A[l] < A[mid] and A[l] < A[r]:
            if A[mid] < A[r]:
                return mid
            else:
                return r
        elif A[mid] < A[l] and A[mid] < A[r]:
            if A[l] < A[r]:
                return l
            else:
                return r
        elif A[r] < A[mid] and A[r] < A[l]:
            if A[mid] < A[l]:
                return mid
            else:
                return l


def partitioning_median(A, l, r):
    global count
    if r <= l:
        return
    # Just Two elements in the array. Base Case
    elif r - l == 1:
        count = count + (r - l) # Incrementing Count(Number of Comparisons)
        if A[r] < A[l]:
            A = swap(A, l, r)
    else:
        count = count + (r - l) # Incrementing Count(Number of Comparisons)
        # Finding the median element to use as the Pivot
        pivot = findMedian(A, l, r)
        if pivot == -1:
            return

        # Swapping first element and Pivot element(Median)
        A = swap(A, l, pivot)

        p = A[l] # First Element as Pivot
        i = l + 1
        for j in range(l + 1, r + 1):
            if A[j] < p:
                A = swap(A, i, j)
                i = i + 1
        A = swap(A, i - 1, l)

        # Recursion Steps
        partitioning_median(A, l, i - 2) # Left Part of the Array
        partitioning_median(A, i, r) # Right Part of the Array


def quickSort():
    A = [3,1,6,5,2,4,8,7,10,9,12,15,20,19,18,14,13,11,17,16]
    # partitioning_first(numbers, 0, len(numbers) - 1)
    # print(numbers)
    # print(count)
    # partitioning_LastReplace(numbers, 0, len(numbers) - 1)
    # print(numbers)
    # print(count)
    # partitioning_median(numbers, 0, len(numbers) - 1)
    # print(numbers)
    # print(count)


if __name__ == '__main__':
    quickSort()