from vehicle.vehicle import *


class Car(Vehicle):
    def __init__(self, fuel_tank_capacity, fuel_consumption, speed_limit):
        super().__init__(fuel_tank_capacity, fuel_consumption)
        self.__speed_limit = speed_limit

    def to_string(self):
        return "CAR " + super().to_string() + " speed limit (mph): " + str(self.__speed_limit)
