

class Puzzle(object):
    def __init__(self, puzzle_str):
        self.puzzle_str = puzzle_str
        self.cells = [Cell(value) for value in puzzle_str]
        group_factory = GroupFactory(self.cells)
        self.cols = group_factory.cols()
        self.rows = group_factory.rows()
        self.boxs = group_factory.boxs()

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

    def cols(self):
        #TODO may not be right
        for offset in range(9):
            yield Group([cell for cell in self.cells[offset:offset+9]])

    def rows(self):
        #TODO may not be right
        for offset in range(9):
            yield Group([cell for cell in self.cells[offset:offset+9]])

    def boxs(self):
        yield None
