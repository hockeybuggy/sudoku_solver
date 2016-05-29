from group import Group


class Puzzle(object):
    def __init__(self, puzzle_str):
        self.inital_str = puzzle_str
        self.cells = list(puzzle_str)
        group_factory = GroupFactory(self.cells)
        self.boxs = [group_factory.box(x) for x in range(9)]
        self.cols = [group_factory.col(x) for x in range(9)]
        self.rows = [group_factory.row(x) for x in range(9)]

    def __str__(self):
        return u"<Game: {}>".format(self.puzzle_str)

    @property
    def pretty_str(self):
        return "\n".join([str(row) for row in self.rows])

    def solve(self):
        return self


class GroupFactory(object):
    def __init__(self, cells):
        self.cells = cells

    def col(self, offset):
        return Group([cell for cell in self.cells[offset:offset+9]])

    def row(self, offset):
        return Group([cell for cell in self.cells[offset:offset+9]])

    def box(self, offset):
        return Group([cell for cell in self.cells[offset:offset+9]])
