from unittest import TestCase
from ..sudoku_solver.group import Group


class GroupTestCase(TestCase):
    def test_empty_group(self):
        g = Group([])
        self.assertTrue(g.empty)
        self.assertFalse(g.full)
        self.assertTrue(g.valid)
        self.assertEquals(len(g), 0)

    def test_bad_group(self):
        self.assertFalse(Group(["a"]).valid)

    def test_partial_group(self):
        g = Group(["1", "3"])
        self.assertFalse(g.empty)
        self.assertFalse(g.full)
        self.assertTrue(g.valid)
        self.assertEquals(len(g), 2)

    def test_full_group(self):
        g = Group(["1", "2", "3", "4", "5", "6", "7", "8", "9"])
        self.assertFalse(g.empty)
        self.assertTrue(g.full)
        self.assertTrue(g.valid)
        self.assertEquals(len(g), 9)
