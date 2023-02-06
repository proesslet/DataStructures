# create a file to match the input1.txt file
import random

x = 8000
y = x*2
nums = []
for i in range(1, y):
    nums.append(i)

# open the file for writing
f = open("test.txt", "w")

# write the number of elements to file
f.write(str(x) + "\n")
f.write("\n")

# write 100 random numbers to the file on separate lines
i=0
while i < x:
    num = random.choice(nums)
    nums.remove(num)
    f.write(str(num) + "\n")
    i += 1

# Write a blank line
f.write("\n")

#write the find command
f.write("F 5")
f.write("\n")
for i in range(5):
    f.write(str(random.randint(1, y)) + "\n")
f.write("\n")

#write the sum pairs command
f.write("A 5")
f.write("\n")
for i in range(5):
    f.write(str(random.randint(1, y)) + "\n")
f.write("\n")

f.write("R 5")
f.write("\n")
for i in range(5):
    f.write(str(random.randint(1, y)) + "\n")
f.write("\n")

f.write("I 5")
f.write("\n")
for i in range(5):
    f.write(str(random.randint(1, y)) + "\n")
f.write("\n")


# close the file
f.close()
