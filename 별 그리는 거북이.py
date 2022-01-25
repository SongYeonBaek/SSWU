import turtle
import random

def star():
    size = random.randint(1,100)
    angle = random.randint(1,360)
    t.left(angle)
    for x in range(5):
        t.forward(size)
        t.left(144)
    
def mv(x,y):
    t.penup()
    t.goto(x,y)
    t.pendown()
    star()

t = turtle.Turtle()
t.shape('turtle')

turtle.onscreenclick(mv)