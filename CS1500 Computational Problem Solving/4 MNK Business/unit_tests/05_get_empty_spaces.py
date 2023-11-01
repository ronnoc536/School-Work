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
        ["O", "O", "X", " ", " "],
        ["X", "X", " ", "O", "O"],
        [" ", "X", "X", "O", "O"],
        ["O", "X", " ", "O", " "],
    ]

    actual_result = [[0, 3], [0, 4], [1, 2], [2, 0], [3, 2], [3, 4]]
    function_result = mnk_business.get_empty_spaces(board, 4, 5)
    return actual_result == function_result


if __name__ == "__main__":
    test()
