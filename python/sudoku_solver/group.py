

class Group(object):
    def __init__(self, cells):
        self.cells = cells

    def full(self):
        return all([cell.value == None for cell in self.cells])

    def valid(self):
        return True  # TODO check validity

    def __str__(self):
        return "".join([str(cell) for cell in self.cells])
