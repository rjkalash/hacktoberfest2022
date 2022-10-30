from datetime import date
 
def numOfDays(date1, date2):
    return (date2-date1).days
     
# Driver program
year = int(input("Input year : "))
month = int(input("Input month : "))
day = int(input("Input date : "))
input_date = date(year, month, day)
current_date = date.today()
print(numOfDays(current_date, input_date), "days to", day, "-", month, "-", year)