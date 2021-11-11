class Vehicle:
    def __init__(self, fuel_tank_capacity, fuel_consumption):
        self.__fuel_tank_capacity = fuel_tank_capacity
        if fuel_consumption == 0:
            raise ValueError("perpetuum mobile")
        self.__fuel_consumption = fuel_consumption

    def to_string(self):
        return " fuel tank capacity (gallons): " + str(
            self.__fuel_tank_capacity) + " fuel consumption (gallons per mile): " + str(self.__fuel_consumption)

    def get_range(self):
        return self.__fuel_tank_capacity / self.__fuel_consumption
