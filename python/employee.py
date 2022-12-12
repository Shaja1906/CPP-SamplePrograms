#!/usr/bin/python
# Program to understand the class 

class Employee:
	employee_name = ""    # variable to hold the employee name
	employee_address = [] # variable to hold the employee address

	def __init__(self, name, addr):   # This is constructor
		self.employee_name = name # value is not set if self is not used to access the varaibles
		self.employee_address = addr
		#employee_name = name
		#employee_address = addr

	def __del__(self):   # This is destructor
		print ("The Employee object is destroyed")

	def getEmployeeName(self):
		return self.employee_name

	def getEmployeeAddr(self):
		return self.employee_address


#create employee object
emp = Employee("Shajahan", [23, "A", "Dindigul"])
print ("The employee name is ", emp.getEmployeeName())
print ("The employee addr is ", emp.getEmployeeAddr())
		


