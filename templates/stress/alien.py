def isPrime(n):
    if n % 2 == 0:
        return n == 2
    d = 3
    while d * d <= n and n % d != 0:
        d += 2
    return d * d > n

f = open('input.txt', 'r')
f1 = open('output.txt', 'w')
n, k = map(int, f.read().split())
#n, k = map(int, input().split())

check = isPrime(n)

if not check:
    for x in range(0, n*k + 1000, 1):
        if (x // k) * (x % k) == n:
            f1.write(x)
            break
else:
    f1.write(n * k + 1)
