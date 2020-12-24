#in the command terminal type in:

#       python -m manim projects\helloworld.py moveToScene

from manimlib.imports import *
import numpy as np

class moveToScene(Scene):
    def construct(self):
        T1 = TextMobject("Merry Christmas to the best!")
        T2 = TextMobject("* * * * * * * * * * *")
        T3 = TextMobject("* * *")
        T4 = TextMobject("* * * * * * * * * * *")
        T5 = TextMobject("* * *")
        s1 = Square(color=GREEN)
        s2 = Square(color=GREEN)
        s3 = Square(color=GREEN)
        s4 = Square(color=GREEN)
        c1 = Circle()
        c2 = Circle()
        c3 = Circle()
        c4 = Circle()
        self.add(s1,s2,s3,s4,c1,c2,c3,c4)
        theTs= VGroup(T2,T3,T4,T5)
        theTs.set_color(BLUE_B)

        self.play(s1.to_edge, UP+RIGHT, s1.rotate, PI/4,
                  s2.to_edge, UP+LEFT, s2.rotate, -PI/4,
                  s3.to_edge, DOWN+RIGHT, s3.rotate, PI/4,
                  s4.to_edge, DOWN+LEFT, s4.rotate, -PI/4,
                  c1.to_edge, UP + RIGHT,
                  c2.to_edge, UP + LEFT,
                  c3.to_edge, DOWN + RIGHT,
                  c4.to_edge, DOWN + LEFT,
                  T2.to_edge, UP,
                  T3.to_edge, LEFT, T3.rotate, PI/2,
                  T4.to_edge, DOWN,
                  T5.to_edge, RIGHT, T5.rotate, -PI/2)
        self.play(Write(T1))
        self.play(T1.set_color_by_gradient, YELLOW_E, GOLD_C)








