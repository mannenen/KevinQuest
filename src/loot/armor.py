from typing import Dict, Any
from loot.item import Item


class Armor(Item):
    def __init__(self, **kwargs: Dict[str, Any]):
        super(Armor, self).__init__(**kwargs)
        self.__rating = kwargs.get("rating", 0.0)

    def __str__(self):
        pass

    def __repr__(self):
        pass

    defense = property(lambda self: (self.__rating))