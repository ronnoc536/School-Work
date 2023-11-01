#!/usr/bin/python3
# -*- coding: utf-8 -*-

import os
import sys

# Temporarily add the current path to the system path for importing the student's source code.
sys.path.append(
    os.path.join(
        os.path.dirname(os.path.dirname(os.path.abspath(__file__))), ".admin_files"
    )
)
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
# python3 seemingly respects only abspaths, while ipython3 is ok with relative, like '..' here.
import test_utils


@test_utils.test_wrapper
def test() -> bool:
    import mnk_business

    # To debug in pudb3
    # Highlight the line of code below below
    # Type 't' to jump 'to' it
    # Type 's' to 'step' deeper
    # Type 'n' to 'next' over
    # Type 'f' or 'r' to finish/return a function call and go back to caller
    board_positive = [
        ["O", "O", " ", " ", " "],
        ["X", " ", " ", " ", " "],
        ["X", " ", " ", " ", " "],
        ["X", " ", " ", " ", " "],
    ]

    board_negative = [
        [" ", "O", " ", " ", " "],
        ["O", " ", " ", " ", " "],
        ["X", " ", " ", " ", " "],
        ["X", " ", " ", " ", " "],
    ]

    # positive
    if not mnk_business.check_down(board_positive, "X", 4, 5, 3, 1, 0):
        return False

    # negative
    if mnk_business.check_down(board_negative, "X", 4, 5, 3, 2, 0):
        return False

    return True


if __name__ == "__main__":
    test()
