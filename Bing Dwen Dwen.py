# python绘制2022冬奥会吉祥物--冰墩墩
# 此处左右为冰墩墩，面对我时我的观察角度所得

import turtle as t
from time import sleep

# 是否显示绘画过程
# t.tracer(False)

t.setup(800, 600)  # 设置窗体大小
t.title('送莹姐一只冰墩墩，生日快乐哈~')    # 更改窗口默认标题
t.speed(10)  # 设置画笔移动速度
# t.bgpic('dd.png')  # 找到一张简笔画，开始疯狂的测算描边
# 隐藏光标
t.hideturtle()

# 画出大致轮廓
#
#
# 画脑门
t.penup()  # 抬起画笔，不留下痕迹
t.goto(-73, 230)  # 设置起点
t.pencolor('lightgray')  # 画笔颜色
t.pensize(3)  # 画笔宽度
t.fillcolor('white')   # 绘制图形的填充色
t.begin_fill() # 从此处落笔开始，准备填充图形
t.pendown()    # 画笔落下，留下痕迹
t.setheading(20)   # 以 x 轴正方向为基准，设置当前朝向为 angle 角度
t.circle(-250, 35) # 画圆，1.半径；2.偏移角度
#
# 右耳
t.setheading(50)
t.circle(-42,180)
#
# 右侧脸与右侧肚子
t.setheading(-50)
t.circle(-190,30)
t.circle(-320,45)
#
# 右脚
t.circle(120,30)
t.circle(200,12)
t.circle(-18,85)
t.circle(-180,23)
t.circle(-20,110)
#
# 裤裆
t.circle(15,115)
t.circle(100, 12)
t.circle(15, 120)
#
# 左脚
t.circle(-15, 110)
t.circle(-150, 30)
t.circle(-15, 70)
t.circle(-150, 10)
#
# 左侧肚子
t.circle(200, 35)
t.circle(-150, 20)
#
# 左手
t.setheading(-120)
t.circle(50, 30)
t.circle(-35, 200)
t.circle(-300, 23)
#
# 左侧脸
t.setheading(86)
t.circle(-300, 26)
#
# 左耳
t.setheading(122)
t.circle(-53, 160)
t.end_fill()
#
# 补上右手
t.penup()
t.goto(177, 112)
t.pencolor("lightgray")
t.pensize(3)
t.fillcolor("white")
t.begin_fill()
t.pendown()
t.setheading(80)
t.circle(-45, 200)
t.circle(-300, 23)
t.end_fill()
#
#
# 画脸上的彩虹圈
t.penup()
t.goto(-135, 120)
t.pensize(5)
t.pencolor("cyan")
t.pendown()
t.setheading(60)
t.circle(-165, 150)
t.circle(-130, 78)
t.circle(-250, 30)
t.circle(-138, 105)
t.penup()
t.goto(-131, 116)
t.pencolor("slateblue")
t.pendown()
t.setheading(60)
t.circle(-160, 144)
t.circle(-120, 78)
t.circle(-242, 30)
t.circle(-135, 105)
t.penup()
t.goto(-127, 112)
t.pencolor("orangered")
t.pendown()
t.setheading(60)
t.circle(-155, 136)
t.circle(-116, 86)
t.circle(-220, 30)
t.circle(-134, 103)
t.penup()
t.goto(-123, 108)
t.pencolor("gold")
t.pendown()
t.setheading(60)
t.circle(-150, 136)
t.circle(-104, 86)
t.circle(-220, 30)
t.circle(-126, 102)
t.penup()
t.goto(-120, 104)
t.pencolor("greenyellow")
t.pendown()
t.setheading(60)
t.circle(-145, 136)
t.circle(-90, 83)
t.circle(-220, 30)
t.circle(-120, 100)
t.penup()
#
#
# 眼睛部分
#
# 左黑眼圈
t.penup()
t.goto(-64, 120)
t.pencolor("black")
t.pensize(1)
t.fillcolor('black')
t.begin_fill()
t.pendown()
t.setheading(40)
t.circle(-35, 152)
t.circle(-100, 50)
t.circle(-35, 130)
t.circle(-100, 50)
t.end_fill()
#
# 右黑眼圈
t.penup()
t.goto(51, 82)
t.fillcolor()
t.begin_fill()
t.pendown()
t.setheading(120)
t.circle(-32, 152)
t.circle(-100, 55)
t.circle(-25, 120)
t.circle(-120, 45)
t.end_fill()
#
#
# 填充黑色部分，从右耳开始，填充至右手时，画爱心
#
#
# 右耳黑
t.penup()
t.goto(90, 230)
t.pencolor('black')
t.pensize(1)
t.setheading(40)
t.fillcolor('black')
t.begin_fill()
t.pendown()
t.circle(-30, 170)
t.setheading(125)
t.circle(150, 23)
t.end_fill()
#
# 左耳黑
t.penup()
t.goto(-130, 180)
t.pencolor()
t.pensize(1)
t.fillcolor()
t.begin_fill()
t.pendown()
t.setheading(120)
t.circle(-28, 160)
t.setheading(210)
t.circle(150, 20)
t.end_fill()
#
# 左手黑
t.penup()
t.goto(-180, -55)
t.fillcolor()
t.begin_fill()
t.setheading(-120)
t.pendown()
t.circle(50, 30)
t.circle(-27, 200)
t.circle(-300, 20)
t.setheading(-90)
t.circle(300, 14)
t.end_fill()
#
# 左脚黑
t.penup()
t.goto(-38, -210)
t.fillcolor()
t.begin_fill()
t.pendown()
t.setheading(-155)
t.circle(15, 100)
t.circle(-10, 110)
t.circle(-100, 30)
t.circle(-15, 65)
t.circle(-100, 10)
t.circle(200, 15)
t.setheading(-14)
t.circle(-200, 27)
t.end_fill()
#
# 右脚黑
t.penup()
t.goto(108, -168)
t.fillcolor()
t.begin_fill()
t.pendown()
t.setheading(-115)
t.circle(110, 15)
t.circle(200, 10)
t.circle(-18, 80)
t.circle(-180, 13)
t.circle(-20, 90)
t.circle(15, 60)
t.setheading(42)
t.circle(-200, 29)
t.end_fill()
#
# 右手内部
t.penup()
t.goto(182, 95)
t.pencolor()
t.pensize(1)
t.fillcolor()
t.begin_fill()
t.setheading(95)
t.pendown()
t.circle(-37, 160)
t.circle(-20, 50)
t.circle(-200, 30)
t.end_fill()
#
#
# 画龙点睛作用
#
# 左眼珠子
t.penup()
t.goto(-47, 55)
t.fillcolor("white")
t.begin_fill()
t.pendown()
t.setheading(0)
t.circle(25, 360)
t.end_fill()
t.penup()
t.goto(-45, 62)
t.pencolor("darkslategray")
t.fillcolor("darkslategray")
t.begin_fill()
t.pendown()
t.setheading(0)
t.circle(19, 360)
t.end_fill()
t.penup()
t.goto(-45, 68)
t.fillcolor("black")
t.begin_fill()
t.pendown()
t.setheading(0)
t.circle(10, 360)
t.end_fill()
t.penup()
t.goto(-47, 86)
t.pencolor("white")
t.fillcolor("white")
t.begin_fill()
t.pendown()
t.setheading(0)
t.circle(5, 360)
t.end_fill()
#
# 右眼珠子
t.penup()
t.goto(79, 60)
t.fillcolor("white")
t.begin_fill()
t.pendown()
t.setheading(0)
t.circle(24, 360)
t.end_fill()
t.penup()
t.goto(79, 64)
t.pencolor("darkslategray")
t.fillcolor("darkslategray")
t.begin_fill()
t.pendown()
t.setheading(0)
t.circle(19, 360)
t.end_fill()
t.penup()
t.goto(79, 70)
t.fillcolor("black")
t.begin_fill()
t.pendown()
t.setheading(0)
t.circle(10, 360)
t.end_fill()
t.penup()
t.goto(79, 88)
t.pencolor("white")
t.fillcolor("white")
t.begin_fill()
t.pendown()
t.setheading(0)
t.circle(5, 360)
t.end_fill()
#
# 大黑鼻子
t.penup()
t.goto(37, 80)
t.fillcolor("black")
t.begin_fill()
t.pendown()
t.circle(-8, 130)
t.circle(-22, 100)
t.circle(-8, 130)
t.end_fill()
#
# 小嘴儿
t.penup()
t.goto(-15, 48)
t.setheading(-36)
t.begin_fill()
t.pendown()
t.circle(60, 70)
t.setheading(-132)
t.circle(-45, 100)
t.end_fill()
#
# 右手爱心
t.penup()
t.goto(220, 115)
t.pencolor("brown")
t.pensize(1)
t.fillcolor("brown")
t.begin_fill()
t.pendown()
t.setheading(36)
t.circle(-8, 180)
t.circle(-60, 24)
t.setheading(110)
t.circle(-60, 24)
t.circle(-8, 180)
t.end_fill()
t.penup()
#
#
# 标识
# 文字具体位置需要微调
#
# 专属名
'''t.pencolor("black")
t.goto(-60, -140)
t.write("Baby's Bing Dwen Dwen", font=('Arial', 10, 'bold italic'))
'''
# 奥运时间地点
t.pencolor('red')
t.goto(-36, -160)
t.write("BEIJING 2022", font=('Arial', 12, 'bold italic'))
#
# 奥运五环
t.penup()
t.goto(-5, -170)
t.pendown()
t.pencolor("blue")
t.circle(6)
t.penup()
t.goto(10, -170)
t.pendown()
t.pencolor("black")
t.circle(6)
t.penup()
t.goto(25, -170)
t.pendown()
t.pencolor("brown")
t.circle(6)
t.penup()
t.goto(2, -175)
t.pendown()
t.pencolor("lightgoldenrod")
t.circle(6)
t.penup()
t.goto(16, -175)
t.pendown()
t.pencolor("green")
t.circle(6)
t.penup()
#
t.pencolor('lightgray')
t.goto(230, -160)
t.write("", font=('Arial', 12, 'bold italic'))
t.goto(230, -180)
#t.write("0xtlu.github.io", font=('Arial', 12, 'bold italic'))
#
#
# sleep(2)
t.done()
