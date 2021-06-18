from typing import Dict, Any

from entity.inventory import InventoryTracker
from graphical import GraphicalEntity


class Fighter(GraphicalEntity):
    def __init__(self, **kwargs: Dict[str, Any]):
        super(Fighter, self).__init__(**kwargs)
        
        self.__maxHealth = kwargs.get("maxHealth", 0.0)
        self.__health = self.__maxHealth

        self.__speed = kwargs.get("speed", 1.0)

        self.__inventoryTracker = InventoryTracker()

    def receiveAttack(self):
        pass

    def heal(self, amount: float = -1) -> None:
        if amount < 0:
            self.__health = self.__maxHealth
        else:
            self.__health = min(self.__health + amount, self.__maxHealth)
        
    def damage(self, amount: float = -1) -> None:
        if amount < 0:
            self.__health = 0
        else:
            self.__health = max(self.__health - amount, 0)
    
    health: float = property(lambda self: self.__health, None, None, "Character health")
    maxHealth: float = property(lambda self: self.__maxHealth, None, None, "The most health this character can have")
    speed: float = property(lambda self: self.__speed, None, None, "Determines this fighter's location in the turn order")