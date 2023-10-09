# Importing the Calendar Module 
import calendar
# Using the Try-Except for Handeling Errors
try:
    year=int(input("Enter a Year: "))
    # Creating the Calander 
    disp=calendar.calendar(year)
    print(disp)
except Exception as e:
    print("Invalid Entry: Error: ",e)