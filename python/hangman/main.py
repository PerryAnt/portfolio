# Program: main.py
# Author: Perry Antonelli
# Last date modified: 12/15/2020
import pygame
from hangman import Hangman


if __name__ == "__main__":
    pygame.init()

    # Set up the drawing window
    screen = pygame.display.set_mode([1000, 600])
    # Initialize game
    game = Hangman(screen)

    running = True
    while running:
        # Loop over all events in event queue
        for event in pygame.event.get():

            # Detect key press on key down
            if event.type == pygame.KEYDOWN:
                game.keypress(event.unicode)

            # Detect mouse clicks
            if event.type == pygame.MOUSEBUTTONDOWN:
                game.click(event.pos)

            # Did the user click the window close button?
            if event.type == pygame.QUIT:
                running = False

        if game.draw_flag:
            game.draw()

    pygame.quit()
