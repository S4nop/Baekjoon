
N, M, K = map(int, input().split())

sqnc = [i for i in range(1, N+1)]
sub_sqnc = []

sub_size = int(N / M) + (1 if N % M != 0 else 0)
for i in range(0, M - 1):
    sub_sqnc.append(sqnc[sub_size*i:sub_size*(i+1)])

sub_sqnc.append(sqnc[sub_size*(M-1):])

for sub in sub_sqnc:
    sub.reverse()

print(sub_sqnc)




