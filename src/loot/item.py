from typing import Dict, Any
import uuid
import logging
from graphical import GraphicalEntity


log = logging.getLogger(__name__)

class Item(GraphicalEntity):
    def __init__(self, **kwargs: Dict[str, Any]):
        super(Item, self).__init__(**kwargs)

        self.__objId = uuid.uuid4()
        self.__weight = kwargs.get("weight", 0.0)
        self.__description = kwargs.get("description", "An item of some kind")
        self.__value = kwargs.get("value", 0.0)

    def __str__(self):
        pass

    def __repr__(self):
        pass

    obj_id = property(lambda self: self.__objId, None, None, "The internal object id")
    weight = property(lambda self: self.__weight, None, None, "Represents the carry weight of the item")
    description = property(lambda self: self.__description, None, None, "A text description of the item")
    value = property(lambda self: self.__value, None, None, "The sale value of an item")