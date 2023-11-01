#!/usr/bin/python3
# -*- coding: utf-8 -*-
import generate_word_search
import sys

assert (
    "linux" in sys.platform
), "This code should be run on Linux, just a reminder to follow instructions..."

"""
Feel free to define any other helper functions you may need for this assignment.
You must define and type-hint the below functions (in a way that satisfies the unit tests).
"""


def right(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
    # FIXME HOW TO USE FOUND VARIABLE
    rand = 1  # initialize for right search
    rand1 = 1
    if 0 <= col_pos + rand < int(cols2):  # if in bounds (RIGHT)
        for i in range(len(word) - 1):  # loops through num of letter in word
            if 0 <= col_pos + rand < int(cols2):  # if in bounds (RIGHT)
                if word[rand1] == matrix[row_pos][col_pos + rand]:  # check right
                    rand += 1  # counter
                    rand1 += 1
                else:
                    break
        if rand == (len(word)):
            # print('Searching for \"{}\" in matrix {} yields:'.format(word, matrix_num))
            # print('Start pos: ({}, {}) to End pos: ({}, {})'.format(row_pos, col_pos, row_pos, col_pos + x - 1))
            s_pos = (row_pos, col_pos)
            e_pos = (row_pos, col_pos + rand - 1)
            coord = (s_pos, e_pos)
            return coord


def left(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
    rand = 1  # initialize for left search
    rand1 = 1
    if 0 <= col_pos - rand < int(cols2):
        for i in range(len(word) - 1):  # loops through num of letter in word
            if 0 <= col_pos - rand < int(cols2):  # if in bounds (LEFT)
                if word[rand1] == matrix[row_pos][col_pos - rand]:  # check left
                    rand += 1  # counter
                    rand1 += 1
                else:
                    break
        if rand == (len(word)):
            # print('Searching for \"{}\" in matrix {} yields:'.format(word, matrix_num))
            # print('Start pos: ({}, {}) to End pos: ({}, {})'.format(row_pos, col_pos, row_pos, col_pos - x + 1))
            s_pos = (row_pos, col_pos)
            e_pos = (row_pos, col_pos - rand + 1)
            coord = (s_pos, e_pos)
            return coord


def down(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
    rand = 1  # initialize for down search
    rand1 = 1
    if 0 <= row_pos + rand < int(rows2):
        for i in range(len(word) - 1):  # loops through num of letter in word
            if 0 <= row_pos + rand < int(rows2):  # if in bounds (down)
                if word[rand1] == matrix[row_pos + rand][col_pos]:  # check down
                    rand += 1  # counter
                    rand1 += 1
        if rand == (len(word)):
            # print('Searching for \"{}\" in matrix {} yields:'.format(word, matrix_num))
            # print('Start pos: ({}, {}) to End pos: ({}, {})'.format(row_pos, col_pos, row_pos + x - 1, col_pos))
            s_pos = (row_pos, col_pos)
            e_pos = (row_pos + rand - 1, col_pos)
            coord = (s_pos, e_pos)
            return coord


def up(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
    rand = 1  # initialize for up search
    rand1 = 1
    if 0 <= row_pos - rand < int(rows2):
        for i in range(len(word) - 1):  # loops through num of letter in word
            if 0 <= row_pos - rand < int(rows2):  # if in bounds (up)
                if word[rand1] == matrix[row_pos - rand][col_pos]:  # check up
                    rand += 1  # counter
                    rand1 += 1
        if rand == (len(word)):
            # print('Searching for \"{}\" in matrix {} yields:'.format(word, matrix_num))
            # print('Start pos: ({}, {}) to End pos: ({}, {})'.format(row_pos, col_pos, row_pos - x + 1, col_pos))
            s_pos = (row_pos, col_pos)
            e_pos = (row_pos - rand + 1, col_pos)
            coord = (s_pos, e_pos)
            return coord


def up_right(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
    # Up Right Search
    rand = 1
    rand1 = 1
    if 0 <= row_pos - rand < int(rows2) and 0 <= col_pos + rand < int(cols2):
        for i in range(len(word) - 1):
            if 0 <= row_pos - rand < int(rows2) and 0 <= col_pos + rand < int(cols2):
                if word[rand1] == matrix[row_pos - rand][col_pos + rand]:
                    rand += 1
                    rand1 += 1
        if rand == (len(word)):
            s_pos = (row_pos, col_pos)
            e_pos = (row_pos - rand + 1, col_pos + rand - 1)
            coord = (s_pos, e_pos)
            return coord


def up_left(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
    # Up Left Search
    rand = 1
    rand1 = 1
    if 0 <= row_pos - rand < int(rows2) and 0 <= col_pos - rand < int(cols2):
        for i in range(len(word) - 1):
            if 0 <= row_pos - rand < int(rows2) and 0 <= col_pos - rand < int(cols2):
                if word[rand1] == matrix[row_pos - rand][col_pos - rand]:
                    rand += 1
                    rand1 += 1
        if rand == (len(word)):
            s_pos = (row_pos, col_pos)
            e_pos = (row_pos - rand + 1, col_pos - rand + 1)
            coord = (s_pos, e_pos)
            return coord


def down_left(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
    # Down Left Search
    rand = 1
    rand1 = 1
    if 0 <= row_pos + rand < int(rows2) and 0 <= col_pos - rand < int(cols2):
        for i in range(len(word) - 1):
            if 0 <= row_pos + rand < int(rows2) and 0 <= col_pos - rand < int(cols2):
                if word[rand1] == matrix[row_pos + rand][col_pos - rand]:
                    rand += 1
                    rand1 += 1
        if rand == (len(word)):
            s_pos = (row_pos, col_pos)
            e_pos = (row_pos + rand - 1, col_pos - rand + 1)
            coord = (s_pos, e_pos)
            return coord


def down_right(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):

    # Down Right Search
    rand = 1
    rand1 = 1
    if 0 <= row_pos + rand < int(rows2) and 0 <= col_pos + rand < int(cols2):
        for i in range(len(word) - 1):
            if 0 <= row_pos + rand < int(rows2) and 0 <= col_pos + rand < int(cols2):
                if word[rand1] == matrix[row_pos + rand][col_pos + rand]:
                    rand += 1
                    rand1 += 1
        if rand == (len(word)):
            s_pos = (row_pos, col_pos)
            e_pos = (row_pos + rand - 1, col_pos + rand - 1)
            coord = (s_pos, e_pos)
            return coord


def compare_data(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
    """Check each letter after the first for correctness of next letters."""
    if right(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
        return right(matrix, word, row_pos, col_pos, rows2, cols2, total_cols)
    if left(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
        return left(matrix, word, row_pos, col_pos, rows2, cols2, total_cols)
    if down(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
        return down(matrix, word, row_pos, col_pos, rows2, cols2, total_cols)
    if up(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
        return up(matrix, word, row_pos, col_pos, rows2, cols2, total_cols)
    if up_right(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
        return up_right(matrix, word, row_pos, col_pos, rows2, cols2, total_cols)
    if up_left(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
        return up_left(matrix, word, row_pos, col_pos, rows2, cols2, total_cols)
    if down_left(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
        return down_left(matrix, word, row_pos, col_pos, rows2, cols2, total_cols)
    if down_right(matrix, word, row_pos, col_pos, rows2, cols2, total_cols):
        return down_right(matrix, word, row_pos, col_pos, rows2, cols2, total_cols)


def build_matrix(rows, cols):
    """
    Should build a 2D List of Lists of empty strings, i.e., ""
    Returns a List[List[str]]
    Do NOT fill your matrix here; fill it in main, or another function.
    Write your function below here.
    """

    fullList = []
    for row in range(rows):
        colls = []
        for col in range(cols):
            colls.append("")
        fullList.append(colls)
    return fullList


def matrix_search(matrix, word):
    """
    Should search through a matrix built above to find the word (a str).
    Returns the coordinates listed [down][over] a.k.a. [row][col].
    as a tuple of tuples of ints: Tuple[Tuple[int, int], Tuple[int, int]].
    If it does not find the word, then return None.
    matrix_search should NOT build or fill the matrix.
    Write your actual AI below here.
    """
    # initialize Default
    s_pos = (-9, -9)
    e_pos = (-9, -9)
    coords = (s_pos, e_pos)

    rows2 = len(matrix)
    cols2 = len(matrix[0])

    row_pos = 0
    for rows in matrix:
        col_pos = 0
        total_cols = 0
        for cols in rows:
            total_cols += 1
            if cols == word[0]:
                if compare_data(
                    matrix, word, row_pos, col_pos, rows2, cols2, total_cols
                ):
                    coords = compare_data(
                        matrix, word, row_pos, col_pos, rows2, cols2, total_cols
                    )
            col_pos += 1
        row_pos += 1
    return coords


def main():
    """
    Write or call the code to read in the game parameters: dimensions/matrix/.
    word here. Main should call build_matrix and matrix_search
    """
    case = int(input())
    matrix_num = 0
    for wordSearches in range(case):
        why_hit_enter = input()
        rows, cols = input().split()
        rows = int(rows)
        cols = int(cols)
        matrix = build_matrix(rows, cols)
        for num in range(rows):
            x = 0
            letter_in_line = input().split()
            for num2 in range(cols):
                matrix[num][num2] = letter_in_line[x]
                x = x + 1
        word = input()
        matrix_search(matrix, word)
        matrix_num += 1

        coord = matrix_search(matrix, word)

        s_pos = coord[0]
        e_pos = coord[1]

        if s_pos[0] == -9:
            print('Searching for "{}" in matrix {} yields:'.format(word, wordSearches))
            print("The pattern was not found.")
            print()
        else:
            print('Searching for "{}" in matrix {} yields:'.format(word, wordSearches))
            print(
                "Start pos: ({}, {}) to End pos: ({}, {})".format(
                    s_pos[0], s_pos[1], e_pos[0], e_pos[1]
                )
            )
            print()


if __name__ == "__main__":
    main()
