

formula = input()

splited_by_minus = formula.split("-")
sum = 0
for num in splited_by_minus[0].split("+"):
    sum += int(num)

for i in range(1, len(splited_by_minus)):
    for num in splited_by_minus[i].split("+"):
        sum -= int(num)

print(sum)
        
