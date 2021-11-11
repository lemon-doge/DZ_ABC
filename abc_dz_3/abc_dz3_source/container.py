from vehicle import *


class Container:
    def __init__(self):
        self.current_index = 0
        self.store = []

    def append(self, vehicle):
        self.store.append(vehicle)

    def __iter__(self):
        return self

    def __next__(self):
        if self.current_index < len(self.store):
            self.current_index += 1
            return self.store[self.current_index - 1]
        else:
            raise StopIteration

    def filter(self, predicate):
        self.store = list(filter(predicate, self.store))
        self.current_index = 0

    def clear(self):
        self.store.clear()
        self.current_index = 0

    def size(self):
        return len(self.store)

    def average_range(self):
        if len(self.store) != 0:
            return (sum(vehicle.get_range() for vehicle in self.store)) / len(self.store)
        else:
            return 0
