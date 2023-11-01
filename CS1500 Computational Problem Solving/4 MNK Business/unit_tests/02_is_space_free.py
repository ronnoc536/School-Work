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
    board = [
        [" ", "O", "X", "X", "X"],
        [" ", " ", " ", " ", " "],
        [" ", " ", " ", "O", " "],
        [" ", " ", " ", " ", " "],
    ]
    # positive test
    if not mnk_business.is_space_free(board, 1, 3):
        return False

    # negative test
    if mnk_business.is_space_free(board, 0, 3):
        return False

    return True


if __name__ == "__main__":
    test()
