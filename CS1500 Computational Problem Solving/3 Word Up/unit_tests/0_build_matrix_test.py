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
    import word_up
    from typing import List

    # To debug in pudb3, highlight just below this line, hit 't', then 'n' or 's' as you want
    student_matrix: List[List[str]] = word_up.build_matrix(4, 3)
    if student_matrix != [[""] * 3] * 4:
        return False
    # Check edits to see if matrix was constructed properly.
    student_matrix[0][1] = "g"
    if student_matrix != [["", "g", ""], ["", "", ""], ["", "", ""], ["", "", ""]]:
        return False
    return True


if __name__ == "__main__":
    test()
