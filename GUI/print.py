#!/usr/bin/python
# -*- coding: utf-8 -*-

import pygame
from pygame.locals import * # constant value of pygame
import sys
import codecs
import os

if os.name == 'nt':
	# In Windows
	import ctypes
elif os.name == 'posix':
	# In Linux, Macos
	pass

class Game(object):
	def __init__(self):
		title = '勇者の旅立ち'
		pygame.display.set_caption(title)
		self.pos_y = 0
		self.pos_msg_y = 0
	
	def main(self, screen_size):
		f_screen_full = False
		self.screen_x = 640
		self.screen_y = 480
		clock = pygame.time.Clock()
		self.screen = pygame.display.set_mode((self.screen_x, self.screen_y))
		self.screen.fill((255, 255, 255))
		self.file_story = codecs.open("story.txt", "r", "utf-8")
		
		self.load_img_title()
		self.load_img_gamestart()
		self.play_bgm_title()
		
		story = 0 # 0 is title screen
		f = 0
		interval = 0
		
		while True:
			time = clock.tick(60) # 60 fps
			time_s = time / 1000.0
			pygame.display.update()
			for event in pygame.event.get():
				if event.type == QUIT:
					sys.exit()
					#return
				elif event.type == pygame.KEYDOWN and \
						event.key == pygame.K_ESCAPE:
					sys.exit()
					#return
				elif event.type == pygame.KEYDOWN and \
						event.key == pygame.K_F2:
					# フルスクリーンとウィンドウを F2キーで切り替え
					f_screen_full = not f_screen_full
					if f_screen_full == True:
						self.screen = pygame.display.set_mode(screen_size, FULLSCREEN)
						self.screen_x = screen_size[0]
						self.screen_y = screen_size[1]
					else:
						self.screen = pygame.display.set_mode((640, 480))
						self.screen_x = 640
						self.screen_y = 480
					#self.screen.fill((255, 255, 255))
				elif event.type == pygame.KEYDOWN and \
						event.key == pygame.K_RETURN:
					if story == 0:
						story += 1
						self.play_bgm_game()
						self.load_img_story1()
						self.make_msgarea()
					elif story == 1:
						self.puts_message()
			
			if story == 0:
				interval += time_s
				if interval >= 0.7 and f == 0:
					interval = 0
					self.load_img_title()
					f = 1
				elif interval >= 0.2 and f == 1:
					interval = 0
					self.load_img_gamestart()
					f = 0
		
		self.file_story.close()
	
	# screen
	def make_msgarea(self):
		screen_size = self.screen.get_size()
		self.msgarea_size = (screen_size[0] / 5 * 4, 18 * 5) #screen_size[1] / 4)
		self.msgarea = pygame.Surface(self.msgarea_size)
		self.msgarea.fill((0, 100, 0))
		pos = (screen_size[0] - (int(screen_size[0] * 0.9)), screen_size[1] - (int(screen_size[1] * 0.2)))
		self.screen.blit(self.msgarea, pos)
		#self.msgarea = msg
	
	# print
	def print_font_free(self, string, color = (0, 0, 0), size = 18, bgcolor = (255, 255, 255)):
		pos = (0, self.pos_y)
		f_sans_serif = pygame.font.Font("IPAexfont/ipaexg.ttf", size)
		if bgcolor == (255, 255, 255):
			text = f_sans_serif.render(string, True, color)
		else:
			text = f_sans_serif.render(string, True, color, bgcolor)
		self.screen.blit(text, pos)
		self.pos_y += size
		y = self.screen.get_size()
		if self.pos_y > y[1]:
			self.pos_y = 0
	
	def print_font(self, string, color = (0, 0, 0), size = 18, bgcolor = (255, 255, 255)):
		""" print to message area """
		if self.msgarea == None:
			return
		pos = (430, 200)
		pos_msg = (0, self.pos_msg_y);
		f_sans_serif = pygame.font.Font("IPAexfont/ipaexg.ttf", size)
		if bgcolor == (255, 255, 255):
			text = f_sans_serif.render(string, True, color)
		else:
			text = f_sans_serif.render(string, True, color, bgcolor)

		self.msgarea.blit(text, pos_msg)
		screen_size = self.screen.get_size()
		pos = (screen_size[0] - (int(screen_size[0] * 0.9)), screen_size[1] - (int(screen_size[1] * 0.2)))
		self.screen.blit(self.msgarea, pos)
		self.pos_msg_y += size
		if (self.pos_msg_y + size) >= self.msgarea_size[1]:
			self.msgarea.scroll(0, -18)
			self.pos_msg_y -= size
	
	def puts_message(self):
		str = self.file_story.readline()
		str = str.replace("\n", "")
		str = str.replace("\r", "")
		str = str.replace("\t", "    ")
		self.print_font(str, (0, 0, 0))
	
	# sound
	def play_bgm_game(self):
		pygame.mixer.music.load("sound/mp3/bgm1.mp3")
		pygame.mixer.music.play(-1)
	
	def play_bgm_title(self):
		pygame.mixer.music.load("sound/mp3/bgm_title.mp3")
		pygame.mixer.music.play(-1)
	
	# image
	def load_img_title(self):
		bgimg = pygame.image.load("image/bgimg_title.png").convert()
		self.screen.blit(bgimg, (0, 0))
		pygame.display.update()
	
	def load_img_gamestart(self):
		msgimg = pygame.image.load("image/game_start2.png").convert_alpha()
		x = ( self.screen_x - msgimg.get_size()[0] ) / 2
		y = ( self.screen_y - msgimg.get_size()[1] ) / 2
		self.screen.blit(msgimg, (x, y))
		pygame.display.update()
	
	def load_img_story1(self):
		img = pygame.image.load("image/bgimg_story1.png").convert()
		self.screen.blit(img, (0, 0))
		pygame.display.update()
	

def get_screen_size():
	if os.name == 'nt': #Windows
		user32 = ctypes.windll.user32
		screensize = user32.GetSystemMetrics(0), user32.GetSystemMetrics(1)
	elif os.name == 'posix': #Linux
		screensize = 640, 480
	else:
		screensize = 640, 480
	return screensize

### ----------- main ----------- ###
if __name__ == '__main__':
	pygame.init()
	f_screen_size = get_screen_size()
	game = Game()
	game.main(f_screen_size)
