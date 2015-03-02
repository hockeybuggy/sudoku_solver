

class Puzzle(object):
    def __init__(self, puzzle_str):
        self.puzzle_str = puzzle_str
        puzzle_factory = PuzzleFactory(puzzle_str)
        self.cols = [col for col in puzzle_factory.cols()]
        self.rows = [row for row in puzzle_factory.rows()]
        self.boxs = [box for box in puzzle_factory.boxs()]

    def __str__(self):
        return u"<Game: {}>".format(self.puzzle_str)

    @property
    def pretty_str(self):
        return "\n".join([str(row) for row in self.rows])

    def solve(self):
        return self


class PuzzleFactory(object):
    def __init__(self, puzzle_str):
        self.puzzle_str = puzzle_str
        self.cells = [Cell(value) for value in puzzle_str]

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


class Group(object):
    def __init__(self, cells):
        self.cells = cells

    def full(self):
        return all([cell.value == None for cell in self.cells])

    def valid(self):
        return True  # TODO check validity

    def __str__(self):
        return "".join([str(cell) for cell in self.cells])


class Cell(object):
    def __init__(self, value):
        self.value = value

    def __str__(self):
        return str(self.value)
