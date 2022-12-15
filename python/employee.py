#!/usr/bin/python
# Program to understand the class 

class Employee:
	employee_name = ""    # variable to hold the employee name
	employee_address = [] # variable to hold the employee address
	__employee_ID = 1;    # private variable to hold the employee ID __ denotes the private variable

	def __init__(self, name, addr):   # This is constructor
		self.employee_name = name # value is not set if self is not used to access the varaibles
		self.employee_address = addr
		#employee_name = name
		#employee_address = addr

	def __del__(self):   # This is destructor
		print ("The Employee object is destroyed")

	def getEmployeeName(self):		#self must be passed for all member functions
		return self.employee_name

	def getEmployeeAddr(self):
		return self.employee_address

class ContractEmployee(Employee):
	def __init__(self, name, addr):
		self.employee_name = "Contract_" + name
		self.employee_address = addr

	def __del__(self):
		print ("The Contract Employee object is destroyed")
	
	def getEmployeeName(self):
		return self.employee_name

	def getEmployeeAddr(self):
		return self.employee_address

#create employee object
emp = Employee("Shajahan", [23, "A", "Dindigul"])
print ("The employee name is ", emp.getEmployeeName())
print ("The employee addr is ", emp.getEmployeeAddr())
contractemp = ContractEmployee("Shajahan", [23, "A", "Dindigul"])
print ("The employee name is ", contractemp.getEmployeeName())
print ("The employee addr is ", contractemp.getEmployeeAddr())
