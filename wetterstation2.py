from tkinter import *

root = Tk()
root.attributes("-fullscreen", True)
root.config(bg = "light green")
frameo = Frame(root)
frameu = Frame(root, bg = "light green")


Label(frameo, 
		 text="Die Daten der Hatschi Wetterstation:",
		 fg = "green",
                 bg = "dark blue",
		 font = "Times 50").pack()





Label(frameu, 
		 text="Temperatur:",
		 fg = "green",
                 bg = "yellow",
		 font = "Times 50").pack()

Label(frameu, 
		 text="Luftfeuchtigkeit:",
		 fg = "green",
		 bg = "red",
		 font = "Times 50").pack()

Label(frameu, 
		 text="Luftdruck:",
		 fg = "green",
		 bg = "light blue",
		 font = "Times 50").pack()

Label(frameu, 
		 text="Gas:",
		 fg = "green",
		 bg = "blue",
		 font = "Times 50").pack()

Label(frameu, 
		 text="Regen:",
		 fg = "green",
		 bg = "yellow",
		 font = "Times 50").pack()







frameo.pack()
frameu.pack(pady = 20)
root.mainloop()
