class GraphicalEntity:
    def __init__(self, **kwargs):
        self.__worldGraphic = kwargs.get("graphic", None)

    # worldGraphic is read-only property whose value is set during construction
    worldGraphic = property(lambda self: self.__worldGraphic, None, None, "The image used to represent the item as placed in the world")