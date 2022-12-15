#!/usr/bin/python
# program to understand csv read.modify and write using csv reader
import csv

#open and read the csv file
rows = []   	# list to hold the rows
prev_freemem = 0 
curr_freemem = 0
delta_freemem = 0
csv_file = open("vmstat.csv", "r")
csv_reader = csv.reader(csv_file)
header = next(csv_reader)
for row in csv_reader:
	curr_freemem = int(row[3])
	delta_freemem = curr_freemem - prev_freemem
	prev_freemem = curr_freemem
	row.append(delta_freemem)
	rows.append(row)

csv_freemem = open("freememgrowth.csv", "w")
csv_writer = csv.writer(csv_freemem)
header.append("FreeMemDelta")
csv_writer.writerow(header) 
csv_writer.writerows(rows)
	
#close the file
csv_file.close()
csv_freemem.close()
