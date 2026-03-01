n = int(input())  # the number of temperatures to analyse
if n <= 0:
    print(0)
else:
    values = [int(i)for i in input().split()]
    min_val = max(values)
    for v in values:
        if abs(v) < abs(min_val):
            min_val = v
        elif v == -min_val:
            min_val = abs(v)
    print(min_val)
