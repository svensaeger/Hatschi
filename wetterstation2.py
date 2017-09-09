from tkinter import *
import serial
import time

def ausgeben(daten):
    datenEinzeln = daten.split()
    

root = Tk()
root.attributes("-fullscreen", True)
root.config(bg = "light green")
frameo = Frame(root)    
frameu = Frame(root, bg = "light green")


temp = "0"
luftfeu = "0"
luftdruck = "0"
gas = "0"
regen = "0"




Label(frameo, 
		 text="Die Daten der Hatschi Wetterstation:",
		 fg = "green",
                 bg = "dark blue",
		 font = "Times 50").pack()





Label(frameu, 
		 text="Temperatur: " + temp,
		 fg = "green",
                 bg = "yellow",
		 font = "Times 50").pack()

Label(frameu, 
		 text="Luftfeuchtigkeit: " + luftfeu,
		 fg = "green",
		 bg = "red",
		 font = "Times 50").pack()

Label(frameu, 
		 text="Luftdruck: " + luftdruck,
		 fg = "green",
		 bg = "light blue",
		 font = "Times 50").pack()

Label(frameu, 
		 text="Gas: " + gas,
		 fg = "green",
		 bg = "blue",
		 font = "Times 50").pack()

Label(frameu, 
		 text="Regen: " + regen,
		 fg = "green",
		 bg = "yellow",
		 font = "Times 50").pack()







frameo.pack()
frameu.pack(pady = 20)
root.mainloop()

s = serial.Serial('/dev/ttyACMO', 9600);
try:
    s.open()
except serial-seralutil.SerialException:
    s.close()
    s.open()
time.sleep(5)
try:
    while True:
        response = s.readline()
        ausgeben(response)
except KeyboardInterrupt:
    s.close()
