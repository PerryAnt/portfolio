import random
import pygame
from button import Button


def display_text(screen, font, text, color, pos):
    text = font.render(text, True, color)
    text_rect = text.get_rect()
    text_rect.center = pos
    screen.blit(text, text_rect)


class Hangman:
    """Hangman class"""
    white = (255, 255, 255)
    black = (0, 0, 0)

    def __init__(self, screen):
        self.screen = screen
        self.font = pygame.font.SysFont("Ariel", 50)
        self.target = "default"
        self.file = "easy.txt"

        self.pick_word(self.file)
        # Boolean array of which letters have been correctly guessed
        self.correct_letters = [False] * len(self.target)
        # Set of all guessed letters
        self.guessed = set()
        # Flag for whether or not screen needs to be redrawn
        self.draw_flag = True
        # Flag for whether or not the game has ended
        self.game_end = False
        # Text for whether you won or lost
        self.message = ""
        # Number of remaining guesses
        self.guesses_remaining = 10

        screen_width, screen_height = self.screen.get_size()
        x = screen_width - 200
        # List of buttons
        self.buttons = {}
        # Restart Buttons
        b = Button(screen, x, 0, self.black, "Restart", self.font, True, lambda: self.end_game("Restarting, select a difficulty"))
        self.buttons["restart"] = b

        # Buttons for each of the difficulties
        b = Button(screen, x, 100, self.black, "Easy", self.font, False, lambda: self.restart("easy.txt"))
        b.active = False
        self.buttons["easy"] = b

        b = Button(screen, x, 200, self.black, "Medium", self.font, False, lambda: self.restart("medium.txt"))
        b.active = False
        self.buttons["medium"] = b

        b = Button(screen, x, 300, self.black, "Hard", self.font, False, lambda: self.restart("hard.txt"))
        b.active = False
        self.buttons["hard"] = b

        # Used for positioning buttons on screen
        offset = screen_width//2 - 325
        x = 0
        y = screen_height-110
        # Buttons for each letter of the alphabet
        for i in range(26):
            letter = chr(97 + i)
            b = Button(screen, offset+50*x, y, self.black, letter, self.font, True, lambda k=letter: self.guess(k))
            self.buttons[letter] = b
            x += 1
            if x > 12:
                x = 0
                y += 50

    # Sets all buttons activity their default if value == False
    # and the opposite of their default if value == True
    def set_all_buttons(self, value):
        for b in self.buttons.values():
            # xor
            b.active = b.default ^ value

    # Picks a new word from file
    def pick_word(self, file):
        self.target = "default"
        try:
            with open(file, "r") as f:
                # First line of file is source of word list
                f.readline()
                # Second line of file is number of words
                count = int(f.readline().strip())
                # Select random word
                count = random.randrange(1, count)
                # Count to selected word
                while count > 1:
                    f.readline()
                    count -= 1
                # Get word after removing white space
                self.target = f.readline().strip()
        except OSError:
            print(file + " not found")
        except ValueError:
            print("Error in " + file)

    # Process click events
    def click(self, pos):
        for b in self.buttons.values():
            if b.click(pos):
                self.draw_flag = True
                return

    # Process guesses
    def guess(self, letter):
        # Only do anything if letter hasn't already been guessed
        if letter not in self.guessed:
            # Deactive letter button
            self.buttons[letter].active = False
            # Add letter to guessed set
            self.guessed.add(letter)
            # Enable flag to redraw screen
            self.draw_flag = True


            flag = False
            # Check if letter is in target word and update self.correct_letters
            # self.correct_letters has True at the positions of all the letters that
            # have been guessed correctly
            for i in range(len(self.target)):
                if letter == self.target[i]:
                    self.correct_letters[i] = True
                    flag = True
            # If letter is not in target word, decrement guesses
            # Player loses if they run out of guesses
            if not flag:
                self.guesses_remaining -= 1
                if self.guesses_remaining == 0:
                    # Makes the word visible when you lose
                    self.correct_letters = [True] * len(self.target)
                    self.end_game("You lose! Select a difficulty to play again")
            # Ends game in a win once all letters have been correctly guessed
            elif False not in self.correct_letters:
                self.game_end = True
                self.end_game("You win! Select a difficulty to play again")

    # Process key presses
    def keypress(self, key):
        # Don't read key presses if game is over
        if self.game_end:
            return

        if 'a' <= key <= 'z':
            self.guess(key)

    # Ends the game and enables buttons for selecting a new difficulty
    def end_game(self, message):
        self.message = message
        self.draw_flag = True
        self.game_end = True
        self.set_all_buttons(True)

    # Resets all the class variables and picks a new word, restarting the game
    def restart(self, file=None):
        if file:
            self.file = file
        else:
            self.file = "easy.txt"
        self.pick_word(self.file)
        self.correct_letters = [False] * len(self.target)
        self.guessed = set()
        self.draw_flag = True
        self.game_end = False
        self.message = ""
        self.guesses_remaining = 10
        self.set_all_buttons(False)

    # Draws everything to the screen
    def draw(self):
        # Fill the background with white
        self.screen.fill((0, 0, 0))

        # Get width of widest letter to use as spacing between letters
        text_width, text_height = self.font.size("m")
        # Get height and width of screen
        screen_width, screen_height = self.screen.get_size()

        # Set spacing between letters and starting position of text
        text_width += 5
        x = (screen_width - len(self.target) * text_width) // 2
        y = screen_height // 2

        # Display text letter by letter, replace letters that haven't been
        # guessed yet by underscores
        for i in range(len(self.target)):
            letter = self.target[i] if self.correct_letters[i] else "_"
            display_text(self.screen, self.font, letter, self.white, (x, y))
            x += text_width

        # Display remaining guesses on screen
        (x, y) = (screen_width // 2, screen_height - text_height * 4)
        display_text(self.screen, self.font, f"Guess Remaining: {self.guesses_remaining}", self.white, (x, y))

        # Displays a message at the top center of the screen
        (x, y) = (screen_width // 2, 50)
        display_text(self.screen, self.font, self.message, self.white, (x, y))

        # Draw all the buttons
        for b in self.buttons.values():
            b.draw()

        # Updates what is displayed on screen
        pygame.display.flip()

        self.draw_flag = False
