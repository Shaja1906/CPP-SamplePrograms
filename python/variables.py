#! /usr/bin/python

# Program to understand variables and del keyword

Counter = 10
one = 1
_one = 1
counter = 11 #varaible name is case sensitive
#1one = 1 #variable name cannot start with a numeral

print(Counter)
print(one)
print(_one)
#print 1one

#del keyword is used to delete the variables
del one
del _one
del Counter
del counter

# double delete a variable gives variable is not defined error
# del counter

#multi assignment to variable
a,b,c = 1,2,"Shajahan"

print "Multi Assigning variables"
print a
print b
print c

#local variable
def sum(x,y):
	sum  = x+y # here the variable sum is defined within the function scope cannot be accessed outise the function
print "Sum:"
print(sum(5,10)) #This prints none since there is no return

#local variable with return
def mul(a,b):
	mul = a*b
	return mul
print "Multiplication"
print(mul(10,10))

