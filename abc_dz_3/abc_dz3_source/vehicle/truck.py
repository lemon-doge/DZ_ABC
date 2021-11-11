from vehicle.vehicle import *


class Truck(Vehicle):
    def __init__(self, fuel_tank_capacity, fuel_consumption, carrying_capacity):
        super().__init__(fuel_tank_capacity, fuel_consumption)
        self.__carrying_capacity = carrying_capacity

    def to_string(self):
        return "TRUCK " + super().to_string() + " carrying capacity (tons): " + str(self.__carrying_capacity)

