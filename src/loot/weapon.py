from typing import Dict, Any
from loot.item import Item


class Weapon(Item):
    def __init__(self, **kwargs: Dict[str, Any]):
        super(Weapon, self).__init__(**kwargs)

        self.__minDamage = kwargs.get("minDamage", 0.0)
        self.__maxDamage = kwargs.get("maxDamage", 0.0)
        

    def __str__(self):
        pass

    def __repr__(self):
        pass

    power = property(lambda self: (self.__minDamage, self.__maxDamage), None, None, "The minimum and maximum damage this weapon deals")