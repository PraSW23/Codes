# railway 3
from random import randint

class Irctc:
    def __init__(self):
        print("Welcome!")
        self.source = self.get_valid_input("Enter Starting point: ")
        self.destination = self.get_valid_input("Enter Destination: ")
        self.seats = randint(0, 11)

    def get_valid_input(self, prompt):
        while True:
            user_input = input(prompt).strip().upper()
            if user_input:
                return user_input
            else:
                print("Invalid input. Please try again.")

    def availability(self):
        print(f"\nFor {self.source} to {self.destination}:")
        if self.seats == 0:
            print("No seats available")
        else:
            print(f"{self.seats} seats available")

    def booking(self):
        if self.seats == 0:
            print("Sorry! No seats available")
            return

        num_seats = self.get_valid_seat_input()
        if num_seats > self.seats:
            print(f"Sorry! Only {self.seats} seat(s) available")
        else:
            fare = self.calculate_fare(num_seats)
            payment_status = self.process_payment(fare)
            if payment_status == "SUCCESS":
                reservation_status = self.reserve_seats(num_seats)
                if reservation_status == "SUCCESS":
                    print(f"Payment of Rs. {fare} is successful")
                    print(f"{num_seats} seat(s) booked")
                    self.seats -= num_seats
                else:
                    print("Sorry! Failed to reserve seats. Please try again.")
            else:
                print("Payment failed. Please try again.")

    def get_valid_seat_input(self):
        while True:
            try:
                num_seats = int(input("Enter number of seats for booking: "))
                if num_seats > 0:
                    return num_seats
                else:
                    print("Invalid input. Please enter a positive number.")
            except ValueError:
                print("Invalid input. Please enter a valid number.")

    def calculate_fare(self, num_seats):
        fare_per_seat = randint(10, 100) * 5
        return fare_per_seat * num_seats

    def process_payment(self, amount):
        # Mock payment gateway implementation
        print(f"Processing payment of Rs. {amount}...")
        payment_status = "SUCCESS"  # Replace with actual payment gateway integration logic
        return payment_status

    def reserve_seats(self, num_seats):
        # Mock seat reservation implementation
        print(f"Reserving {num_seats} seat(s)...")
        reservation_status = "SUCCESS"  # Replace with actual seat reservation logic
        return reservation_status


check = Irctc()
check.availability()
check.booking()
