#!/usr/bin/python
# -*- coding: utf-8 -*-

import pygame
from pygame.locals import * # constant value of pygame
import sys
import codecs

class Game(object):
	def __init__(self):
		title = 'Game!!'
		pygame.display.set_caption(title)
		# setup font
		self.font_size = 18 # default font size
		self.f_serif = pygame.font.Font("IPAexfont/ipaexm.ttf", self.font_size)
		self.f_sans_serif = pygame.font.Font("IPAexfont/ipaexg.ttf", self.font_size)
		self.pos_y = 0

	def main(self, screen):
		self.screen = screen
		self.screen.fill((255, 255, 255))
		self.print_font("Welcome to Gaming world!")
		self.file_story = codecs.open("story.txt", "r", "utf-8")
		while True:
			for event in pygame.event.get():
				if event.type == QUIT:
					#sys.exit()
					return
				elif event.type == pygame.KEYDOWN and \
						event.key == pygame.K_ESCAPE:
					#sys.exit()
					return
				elif event.type == pygame.KEYDOWN and \
						event.key == pygame.K_RETURN:
					self.puts_message()
		self.file_story.close()

	def print_font(self, string, color = (0, 0, 0)):
		pos = (0, self.pos_y)
		text = self.f_sans_serif.render(string, True, color)
		self.screen.blit(text, pos)
		pygame.display.update()
		self.pos_y += self.font_size

	def puts_message(self):
		str = self.file_story.readline()
		str = str.replace("\n", "")
		str = str.replace("\r", "")
		str = str.replace("\t", "    ")
		self.print_font(str)

### ----------- main ----------- ###
if __name__ == '__main__':
	screen_size = (640, 480)
	pygame.init()
	screen = pygame.display.set_mode(screen_size)
	game = Game()
	game.main(screen)