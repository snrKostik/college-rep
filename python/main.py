import time

class ThreeStates:
    def __init__(self):
        self.__state = "первое"

    def hasstate(self):
        if self.__state == "первое":
            print(f"Состояние: {self.__state}")
            time.sleep(5)
            self.__state = "второе"
        elif self.__state == "второе":
            print(f"Состояние: {self.__state}")
            time.sleep(3)
            self.__state = "третье"
        elif self.__state == "третье":
            print(f"Состояние: {self.__state}")
            time.sleep(2)
            self.__state = "первое"
        else:
            print("Неизвестное состояние")

print("Проверка класса ThreeStates:")
three_states_obj = ThreeStates()
three_states_obj.hasstate()
three_states_obj.hasstate()
three_states_obj.hasstate()
three_states_obj.hasstate()
print("-" * 30)

class Volume:
    def __init__(self, length, width, height):
        self._length = length
        self._width = width
        self._height = height

    def calculate_volume(self):
        return self._length * self._width * self._height

print("Проверка класса Volume:")
volume_obj = Volume(length=10, width=5, height=2)
print(f"Объем: {volume_obj.calculate_volume()}")
print("-" * 30)

class Employee:
    def __init__(self, name, patronymic, surname, salary):
        self.name = name
        self.patronymic = patronymic
        self.surname = surname
        self._salary = salary

class Salary(Employee):
    def get_full_name(self):
        return f"{self.surname} {self.name} {self.patronymic}"

    def get_total_income(self):
        return self._salary["wage"] + self._salary["bonus"]

print("Проверка классов Employee и Salary:")
salary_data = {"wage": 50000, "bonus": 10000}
employee_salary = Salary("Иван", "Иванович", "Иванов", salary=salary_data)
print(f"Полное имя: {employee_salary.get_full_name()}")
print(f"Доход с учетом премии: {employee_salary.get_total_income()}")
print(f"Атрибут name: {employee_salary.name}")
print(f"Защищенный атрибут _salary: {employee_salary._salary}")
print("-" * 30)

class Airplane:
    def __init__(self, speed, color, name, is_jet):
        self.speed = speed
        self.color = color
        self.name = name
        self.is_jet = is_jet

    def go(self):
        print(f"Самолет {self.name} летит")

    def stop(self):
        print(f"Самолет {self.name} не летит")

    def direction(self, new_direction):
        print(f"Самолет {self.name} повернул в направлении {new_direction}")

    def show_speed(self):
        print(f"Текущая скорость самолета {self.name}: {self.speed} км/ч")

class FastAirplane(Airplane):
    def show_speed(self):
        if self.speed > 1300:
            print(f"Самолет {self.name} летит на сверхзвуковой скорости: {self.speed} км/ч")
        else:
            super().show_speed()

class Biplane(Airplane):
    pass

class ArmyAirplane(Airplane):
    pass

print("Проверка классов Airplane и его наследников:")
airplane = Airplane(speed=800, color="белый", name="Boeing 737", is_jet=True)
fast_airplane = FastAirplane(speed=1500, color="черный", name="Су-57", is_jet=True)
biplane = Biplane(speed=200, color="желтый", name="АН-2", is_jet=False)
army_airplane = ArmyAirplane(speed=900, color="серый", name="МиГ-29", is_jet=True)

print("\nАтрибуты и методы базового класса Airplane:")
print(f"Скорость {airplane.name}: {airplane.speed}")
airplane.go()
airplane.direction("север")
airplane.show_speed()
airplane.stop()

print("\nАтрибуты и методы класса FastAirplane:")
print(f"Скорость {fast_airplane.name}: {fast_airplane.speed}")
fast_airplane.go()
fast_airplane.show_speed()

print("\nАтрибуты и методы класса Biplane:")
print(f"Скорость {biplane.name}: {biplane.speed}")
biplane.show_speed()

print("\nАтрибуты и методы класса ArmyAirplane:")
print(f"Скорость {army_airplane.name}: {army_airplane.speed}")
army_airplane.go()
print("-" * 30)

class MathOperations:
    def __init__(self, first_num, second_num):
        self.first_num = first_num
        self.second_num = second_num

    def calc(self):
        print("Запуск операции")

class my_sum(MathOperations):
    def calc(self):
        print(f"Сумма {self.first_num} и {self.second_num} равна: {self.first_num + self.second_num}")

class my_sub(MathOperations):
    def calc(self):
        print(f"Разность {self.first_num} и {self.second_num} равна: {self.first_num - self.second_num}")

class my_mult(MathOperations):
    def calc(self):
        print(f"Произведение {self.first_num} и {self.second_num} равно: {self.first_num * self.second_num}")

print("Проверка классов MathOperations и его наследников:")
math_op = MathOperations(10, 5)
sum_op = my_sum(10, 5)
sub_op = my_sub(10, 5)
mult_op = my_mult(10, 5)

print("\nМетод базового класса MathOperations:")
math_op.calc()

print("\nМетод класса my_sum:")
sum_op.calc()

print("\nМетод класса my_sub:")
sub_op.calc()

print("\nМетод класса my_mult:")
mult_op.calc()