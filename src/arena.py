from typing import Union, Tuple, List
from entity.fighter import Fighter


class Arena:
    def __init__(self):
        pass

    def battleToTheDeath(self, fighters: Union[Tuple[Fighter], List[Fighter]]):
        # determine turn order
        orderedFightList = sorted(fighters, key=lambda x: x.speed)
        
        while all(orderedFightList, lambda x: x.health > 0):
            pass


if __name__ == "__main__":
    a = Arena()
    fighter1 = Fighter()
    fighter2 = Fighter()

    a.battleToTheDeath({fighter1, fighter2})