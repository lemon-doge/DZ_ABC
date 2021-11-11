from vehicle.vehicle import *


class Bus(Vehicle):
    def __init__(self, fuel_tank_capacity, fuel_consumption, passenger_capacity):
        super().__init__(fuel_tank_capacity, fuel_consumption)
        self.__passenger_capacity = passenger_capacity

    def to_string(self):
        return "BUS " + super().to_string() + " passenger capacity (ppl): " + str(self.__passenger_capacity)
