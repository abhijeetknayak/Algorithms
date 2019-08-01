num = open('numbers.txt', 'r')
lines = num.readlines()
counter = 0
numbers = []

for line in lines:
    numbers.append(int(line))
    counter = counter + 1

count = 0

def sort_and_count(a, n):
    global count
    if n == 1:
        return a
    elif n == 2:
        if a[0] > a[1]:
            temp = a[0]
            a[0] = a[1]
            a[1] = temp
            count = count + 1
        return a
    else:
        x = sort_and_count(a[0:n//2], n // 2)
        y = sort_and_count(a[n//2:n], (n - n // 2))
        a = countSplitInversion(x, y)
        return a


def countSplitInversion(x, y):
    global count
    i = 0
    j = 0
    out = []
    while (j <= len(y) and i <= len(x)):
        if j == len(y) and i < len(x):
            out.append(x[i])
            i = i + 1
        elif i == len(x) and j < len(y):
            out.append(y[j])
            j = j + 1
        elif i == len(x) and j == len(y):
            break
        elif x[i] > y[j]:
            out.append(y[j])
            j = j + 1
            count += (len(x) - i)
        elif x[i] < y[j]:
            out.append(x[i])
            i = i + 1
    return out

if __name__ == '__main__':
    # countSplitInversion([1,2,3,6], [4,5])
    sort_and_count(numbers, len(numbers))
    print(count)