#!/usr/bin/python
import re # to perform regex operations

# program to read the stats file and calculate the free memory delta
# and write it into a new file

fp = open("stats", "r") #open the stats file. file is in the current directory
# Read each line from the file
list = []
for line in fp:
	# Format the lines
	# Replace single space and multiple space with "," using regex
	print line[3]
	new_line = line.strip()   # strip is used to remove the leading and trailing white spaces.
	new_line1 = re.sub("(\s)+", ",",new_line)
	list.append( new_line1 + "\n" )
# Remove the first line from the list
del list[0]

#copy the list into a new csv file
csv_file = open("vmstat.csv", "w") # opening a new csv file in write mode
csv_file.writelines(list)
#close the files
fp.close()
csv_file.close()
