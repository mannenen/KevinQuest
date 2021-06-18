import logging
from typing import Set
from loot.item import Item


log = logging.getLogger(__name__)


class InventoryTracker:
    def __init__(self):
        self.__storedItems: Set[Item] = set()

    def store(self, obj: Item):
        self.__storedItems.add(obj)
    
    def retrieve(self, obj: Item):
        try:
            self.__storedItems.remove(obj)
        except KeyError as k:
            log.info(f"Tried to remove {obj} from inventory, but was not in inventory")