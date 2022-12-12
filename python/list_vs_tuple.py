#! /usr/bin/python

#program to understand list and tuple
# list -> collection of multiple datatypes 
# can be modified after initialization.
# denoted by [] square brackets

list = [23, "A", "Madeena Compound", "Gandhiji New Road", 624002]

print ("List Operations")
print ("list is ", list)
print ("list[2] is ", list[2])
print ("list[2:8] is ", list[2:8])
print ("list *2 is ", list * 2);
print ("list[2:] is ", list[2:])
#print ('list[8] is ", list[8]) #index out of bounds
list[2] = "B"
print("Modified list value is ", list[2])

# tuple -> collection of muliple datatypes
# cannot be modified
# denoted by () brackets
tuple = (23, "A", "Madeena Compound", "Gandhiji New Road", 624002)

print("Tuple Operations")
print ("tuple is ", tuple)
print ("tuple[2] is ", tuple[2])
print ("tuple[2:8] is ", tuple[2:8])
print ("tuple *2 is ", tuple * 2);
print ("tuple[2:] is ", tuple[2:])
#print ('tuple[8] is ", tuple[8]) #index out of bounds
#tuple[2] = "B" #This line will cause error
#print("Modified tuple value is ", tuple[2])
