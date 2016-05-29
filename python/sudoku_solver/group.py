
full_group = set(["1", "2", "3", "4", "5", "6", "7", "8", "9"])


class Group(object):
    def __init__(self, cells):
        self.cells = set(cells)

    def __len__(self):
        return len(self.cells)

    @property
    def full(self):
        return len(self.cells) == 9

    @property
    def empty(self):
        return len(self.cells) == 0

    @property
    def valid(self):
        return self.cells <= full_group

    def __contains__(self, value):
        return value in self.cells

    def __str__(self):
        return "".join([str(cell) for cell in self.cells])
