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
    import filecmp

    # To debug in pudb3
    # Highlight the line of code below below
    # Type 't' to jump 'to' it
    # Type 's' to 'step' deeper
    # Type 'n' to 'next' over
    # Type 'f' or 'r' to finish/return a function call and go back to caller
    board = [
        [" ", " ", " ", " ", " "],
        [" ", " ", " ", " ", " "],
        [" ", " ", " ", " ", " "],
        [" ", " ", " ", " ", " "],
    ]
    orig_stdout = sys.stdout
    with open("temp.txt", "w") as your_output:
        sys.stdout = your_output
        mnk_business.draw_board(board, 4, 5)
    sys.stdout = orig_stdout
    passed = filecmp.cmp(
        "unit_tests/01_draw_board_output.txt",
        "temp.txt",
    )
    os.remove("temp.txt")
    return passed


if __name__ == "__main__":
    test()
