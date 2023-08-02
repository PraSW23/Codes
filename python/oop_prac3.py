# RAILWAY TICKET BOOKING SYSTEM also look at updated code

from random import randint

class Irctc:

    def __init__(self):
        print(" Welcome !")
        self.source = input("Enter Starting point : ").upper()
        self.destination = input("Enter Destination : ").upper()
        self.seats = randint(0,11)          #  or use irctc api
        
        
    def availablity(self):
        print(f"\nFor {self.source} to {self.destination} :")

        if(self.seats == 0): 
            print("No seats Available ")
        else :
            print(f"{self.seats} seats Available")
    
    def booking(self):
        try:
            self.fare1
        except:
            print("Check fair first")
        else:
            if(self.seats>0):
                self.seat_book = int(input("Enter number of Seats for booking : "))
                if(self.seat_book <= self.seats):
                    print(f"\nPayment of Rs. {(self.fare1)*(self.seat_book)} is Successful\n{self.seat_book} seats are booked")
                    self.seats-=self.seat_book
                else:
                    print(f"\nSorry ONLY {self.seats} seats Available")
            else:
                print("\nSorry! No seats Available")

    def fare(self):
        self.fare1 = randint(10,100)*5
        print(f"\nFare is Rs. {self.fare1} for one seat")
        


check = Irctc()
check.availablity()
check.fare()
check.booking()

        