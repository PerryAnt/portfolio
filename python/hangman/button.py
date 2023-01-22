import pygame


class Button:
    """Button class"""

    def __init__(self, screen, x, y, color, text, font, default, on_click):
        # Reference to screen so it can draw itself
        self.screen = screen
        # x and y positions
        self.x = x
        self.y = y
        # Width and height
        self.w = font.size(text)[0] + 20
        self.h = font.size(text)[1] + 20
        # Text color
        self.color = color
        # Text
        self.text = text
        # Font
        self.font = font
        # Function to execute when button is clicked on
        self.on_click = on_click
        # Default active/inactive state
        self.default = default
        self.active = default

    # Draws button
    def draw(self):
        if self.active:
            pygame.draw.rect(self.screen, self.color, (self.x, self.y, self.w, self.h), 0)
            self.screen.blit(self.font.render(f"{self.text}", 1, (255, 255, 255)),
                    (self.x + 10, self.y + 10))

    # Detect click on button, runs on_click and returns True when button is clicked
    # returns False otherwise
    def click(self, pos):
        if self.active:
            if self.x < pos[0] < self.x + self.w:
                if self.y < pos[1] < self.y + self.h:
                    self.active = False
                    self.on_click()
                    return True
        return False
