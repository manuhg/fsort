import sys,os
from kivy.app import App
from kivy.uix.button import Button
from kivy.uix.widget import Widget
from kivy.uix.label import Label
from kivy.uix.boxlayout import BoxLayout
from kivy.app import App
from kivy.graphics import Color, Rectangle
from kivy.uix.image import Image
from random import random as r
from functools import partial
from os.path import sep, expanduser, isdir, dirname
import fsort as Fsort
class StressCanvasApp(App):

    def build(self):
        # fs=Fsort.fsort()
        # flst=fs.sort("/home/gk1000/tf")
        layout = BoxLayout(spacing=10)
        btn1 = Button(text='Hello', size_hint=(.7, 1))
        btn2 = Button(text='World', size_hint=(.3, 1))
        layout.add_widget(btn1)
        layout.add_widget(btn2)
        # for f in flst:
        #     wimg = Image(source=f)
        #     wid = Widget()
        #     layout.add_widget(wimg)

        # label = Label(text='0')

        # btn_add100 = Button(text='+ 100 rects',
        #                     on_press=partial(self.add_rects, label, wid, 100))

        # btn_add500 = Button(text='+ 500 rects',
        #                     on_press=partial(self.add_rects, label, wid, 500))

        # btn_double = Button(text='x 2',
        #                     on_press=partial(self.double_rects, label, wid))

        # btn_reset = Button(text='Reset',
        #                    on_press=partial(self.reset_rects, label, wid))
        # layout = BoxLayout(size_hint=(1, None), height=50)
        
        #layout.add_widget(wimg)
        # layout.add_widget(btn_add100)
        # layout.add_widget(btn_add500)
        # layout.add_widget(btn_double)
        # layout.add_widget(btn_reset)
        # layout.add_widget(label)

#        root.add_widget(wid)



if __name__ == '__main__':
    StressCanvasApp().run()