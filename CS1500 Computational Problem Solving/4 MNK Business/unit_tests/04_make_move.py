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
    board_before: List[List[str]] = [
        [" ", "O", "X", "X", "X"],
        [" ", " ", " ", " ", " "],
        [" ", " ", " ", "O", " "],
        [" ", " ", " ", " ", " "],
    ]

    board_after: List[List[str]] = [
        [" ", "O", "X", "X", "X"],
        [" ", "O", " ", " ", " "],
        [" ", " ", " ", "O", " "],
        [" ", " ", " ", " ", " "],
    ]

    mnk_business.make_move(board_before, "O", 1, 1)
    return board_before == board_after


if __name__ == "__main__":
    test()
