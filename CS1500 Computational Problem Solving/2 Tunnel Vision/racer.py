#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Tunnel Vision 2.1
"""
import racey_art

# intro screen
def title_screen() -> None:

    print(racey_art.car)
    print("Welcome to Tunnel Vision.")
    print("Navigate through to the light at the end of the tunnel to win!")
    print("Press 'a' for left, 'd' for right', enter for nothing.")
    print("If you hit the walls, you lose.")
    print("To win, you have to complete 2 laps around the tunnel array.")
    start_input = input("Press any key to start!")
    print(racey_art.clear_screen_str)
    gameplay()


def gameplay() -> None:
    insert_pos = 9
    for lap in range(3):
        posi = 0
        for level in range(len(racey_art.track)):
            track_with_car = list(racey_art.track[posi % 23])

            if lap == 2:
                win_screen()
            print(
                "Tunnel Vision, level:  {}  completed rows in lap number  {}".format(
                    posi, lap + 1
                )
            )
            print(racey_art.lightbulb)

            if (track_with_car[insert_pos] != "|") and (
                track_with_car[insert_pos] != "*"
            ):
                track_with_car[insert_pos] = "^"
            else:
                print(racey_art.clear_screen_str)
                death_screen()
                break

            print(racey_art.track[(posi + 2) % 23])
            print(racey_art.track[(posi + 1) % 23])
            print("".join(track_with_car))

            leftright = input()
            if leftright == "a":
                insert_pos -= 1
            elif leftright == "d":
                insert_pos += 1
            else:
                insert_pos = insert_pos
            posi += 1

            print(racey_art.clear_screen_str)


def win_screen() -> None:
    print(racey_art.win)
    print("You win!\n")
    win_input = input("Do you want to play again? (y/n): \n")
    while win_input != "y" and win_input != "n":
        print()
        win_input = input("Do you want to play again? (y/n): \n")
    if win_input == "y":
        print(racey_art.clear_screen_str)
        gameplay()
    elif win_input == "n":
        quit()


def death_screen() -> None:
    print(racey_art.skull)
    print("You hit the wall, and lose!\n")
    death_input = input("Do you want to play again? (y/n): \n")
    while death_input != "y" and death_input != "n":
        print()
        death_input = input("Do you want to play again? (y/n): \n")
    if death_input == "y":
        print(racey_art.clear_screen_str)
        title_screen()
    elif death_input == "n":
        quit()


print(racey_art.clear_screen_str)
title_screen()
