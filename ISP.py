from abc import *

class Character(metaclass=ABCMeta):
    @abstractmethod
    def attack(self):
        pass

    def move(self):
        pass

class Monster(Character):
    def attack(self):
        pass

class Human(Character):
    def move(self):
        pass

class Attack(metaclass=ABCMeta):
    @abstractmethod
    def attack(self):
        pass

class Move(metaclass=ABCMeta):
    @abstractmethod
    def move(self):
        pass

class Monster(Attack):
    def attack(self):
        pass

class Human(Move):
    def move(self):
        pass