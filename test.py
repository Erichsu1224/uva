
#3
num1 = 100
num2 = 3

print("num1 % num2 =",num1%num2)
print("num1 * num2 =",num1*num2)
print("num1 / num2 =",num1/num2)
print("num1 // num2 =",num1//num2)


#4
list = []
total = 0

for i in range(5):
	tmp = int(input())
	list.append(tmp)
	total += tmp
avg = total/5


for i in range(5):
	print("第",i+1,"個數:",list[i],' ')
print("總和:",total)
print("平均:",avg)



#5
width = int(input())
height = int(input())

print("寬:",width)
print("高:",height)
print("周長",2*(height+width))
print("面積",height*width)