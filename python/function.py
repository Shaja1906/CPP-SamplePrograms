#! /usr/bin/python

# Program to understand the functions 

# Required parameter - A parameter is required to call the function.
def log(str):
	"Function to print the passed string" #Doc string
	print("The passed string is : ", str)
	return
log("Hello, World")


# python allows the caller function to suffle the order of parameters
def printdetail(name, age):
	"Function to print the name and age of a person"
	print("The person ", name, " is ", age, " years old.")

printdetail(age = 33, name = "Shajahan")
#printdetail(age = 32, "Babu") #This line causes error
printdetail("Babu", age=32) #This line causes error

#default parameters
def printoffice(name, office ="XYZ"):
	"Function to print the name along with default office name"
	print(name, " is working at ", office)

printoffice("Bob")
printoffice("John", "ZYX")

# function that takes variable lenght parameters
def printvariablelengthparam(arg1, *varTuple):
	"Function to print the variable length params"
	print ("arg1 : ", arg1)
	for var in varTuple:
		print ("Var is : ", var)

printvariablelengthparam(10,11,12,13,14,15,16,17,18)	
printvariablelengthparam(1,2,3,4,5)	

# anonymous function -> lambda functions
# does not require a def keyword.
# use lambda keyword to define the function
sum = lambda a,b: a+b
print ("The sum is : ", sum(5,25.5))

