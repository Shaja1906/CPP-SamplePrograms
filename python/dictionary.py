#! /usr/bin/python

#program to understand the dictionary
# dictionary is a hash table has key and values.

dict = {}
dict["name"] = "Shajahan"
dict["Phone"] = 9788650681

# adding duplicate keys
dict["name"] = "Ayman" #The value of key "name" was overwritten

anotherdict = {'name' : 'Reshma', 'Phone' : 9788650681}

print(dict)
print(dict["name"])
print(anotherdict.keys()) #keys displayed in reverse order
print(anotherdict.values()) #values displayed in the reverse order
