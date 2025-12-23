from abc import ABC, abstractmethod
from turtle import circle
class Shape(ABC):
    @abstractmethod
    def area_calculate(self):
        pass

    @abstractmethod
    def perimeter_calculate(self):
        pass


class Rectangle(Shape):
    def __init__(self, width , height):
        self.width = width
        self.height = height

    def area_calculate(self):
        return self.width * self.height

    def perimeter_calculate(self):
        return 2 * (self.width +self.height)

class Circle(Shape):
    def __init__(self ,radius):
        self.radius = radius
        self.pi = 3.14159

    def area_calculate(self):
        return self.pi * self.radius **2

    def perimeter_calculate(self):
        return 2 * self.pi * self.radius

shapes = [Rectangle(5,10) , circle(7)]

for shape in shapes:

    print("masahat:", shape.area_calculate())
    print("mohit:", shape.perimeter_calculate())
