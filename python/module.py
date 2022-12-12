#!/usr/bin/python

# Program to understand the import module
# Reusing the functions from function.py
# To Import a module the file must be present either in
# current directory
# pythonpath 
import function # imports all the function inside function module
#from function import log #this will import only the log function from function.py

function.log("Hello, function module") #when using the "import funtion
#log("Hello, function module") #when using the "from funtion import log"

# When this program is run the print statement from the module function
# will also be printted in the terminal
# This is because when the module.py import function the print functions in the 
# function module is getting executed. function has calls to its own print function
# when writing a python module that will be imported make sure to avoid this condition

# The dir command will display a list of variable, functions defined inside the imported 
# module in a sorted order.
modulelist = dir (function)
print(modulelist)
