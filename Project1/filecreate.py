# create a file to match the input1.txt file
import random

# open the file for writing
f = open("test1.txt", "w")


# write 100 random numbers to the file on separate lines
for i in range(20000):
    f.write(str(random.randint(1,2000)) + "\n")





# close the file
f.close()






