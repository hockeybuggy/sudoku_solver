import os
from unittest import TestCase
from ..sudoku_solver.puzzle import Puzzle
from ..sudoku_solver.puzzle import GroupFactory


BASE_DIR = os.path.dirname(os.path.realpath(__file__))


class PuzzleTestCase(TestCase):
    def setUp(self):
        return Puzzle([str(x) for x in range(64)])

    def test_puzzle(self):
        pass


class GroupFactoryTestCase(TestCase):
    def setUp(self):
        fixture_file = os.path.join(BASE_DIR, "fixtures/group_factory.txt")
        with open(fixture_file, "r") as r:
            self.bgf = GroupFactory(list(r.readline()))
            self.cgf = GroupFactory(list(r.readline()))
            self.rgf = GroupFactory(list(r.readline()))

    def assert_group(self, group, value):
        self.assertIn(str(value), group)
        for cell_num in range(9):
            self.assertNotIn("0", group)

    def test_boxs(self):
        for group_num in range(1, 9):
            self.assert_group(self.bgf.box(group_num), group_num)

    # def test_cols(self):
    #     assert_group(self.c)

    # def test_rows(self):
    #     assert_group(self.r_cells)
