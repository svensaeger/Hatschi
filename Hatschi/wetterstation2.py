# -*- coding: utf-8 -*-
from _thread import start_new_thread
from tkinter import *
import serial
import time
import ast

def ausgeben(daten):
    try:
        dic = ast.literal_eval(daten)
        temp.set("Temperatur: "+dic["temp"]+"°C")
        luftf.set("Luftfeuchtigkeit: "+dic["luftf"]+"%")
        luftdruck.set("Luftdruck: "+dic["luftd"]+"hPa")
        af.set("Absolute Feuchtigkeit: "+dic["af"]+"g/m^3")
        gas.set("CO2-Gehalt: "+dic["gas"]+"ppm")
        
    except ValueError:
        print("ValueError: "+daten)
    except KeyError:
        print("KeyError: "+daten)
    except SyntaxError:
        print("SyntaxError: "+daten)
    timeS.set(time.strftime("%H:%M:%S", time.gmtime()))
    root.update_idletasks()

def geigerausgeben(gcv):
    gc.set("Geigerzähler: "+str(gcv))

root = Tk()
root.attributes("-fullscreen", True)
root.config(bg = "dark grey")
frameo = Frame(root)    
frameu = Frame(root, bg = "dark grey")
temp = StringVar()
temp.set("Auf Daten warten...")
luftf = StringVar()
luftf.set("")
luftdruck = StringVar()
luftdruck.set("")
af = StringVar()
af.set("")
gas = StringVar()
gas.set("")
timeS = StringVar()
timeS.set("")
gc = StringVar()
gc.set("")

Label(frameo, 
             text="Hatschi",
             fg = "black",
             bg = "dark grey",
             font = ("Times 50 bold", 100)).pack()

Label(frameu, 
             textvariable=temp,
             fg = "black",
             bg = "dark grey",
             font = "Times 50").pack()

Label(frameu, 
             textvariable=luftf,
             fg = "black",
             bg = "dark grey",
             font = "Times 50").pack()

Label(frameu, 
             textvariable=luftdruck,
             fg = "black",
             bg = "dark grey",
             font = "Times 50").pack()

Label(frameu, 
             textvariable=af,
             fg = "black",
             bg = "dark grey",
             font = "Times 50").pack()

Label(frameu, 
             textvariable=gas,
             fg = "black",
             bg = "dark grey",
             font = "Times 50").pack()

Label(frameu, 
             textvariable=gc,
             fg = "black",
             bg = "dark grey",
             font = "Times 50").pack()

Label(frameu,
      textvariable=timeS,
      fg = "black",
      bg = "dark grey",
      font = "Times 50").pack()

frameo.pack()
frameu.pack(pady = 20)
root.update()

s = serial.Serial('/dev/ttyACM0', 9600)
gcs = serial.Serial('/dev/ttyUSB0', 9600)
try:
    s.open()
    gcs.open()
except serial.serialutil.SerialException:
    s.close()
    s.open()
    gcs.close()
    gcs.open()
time.sleep(2)
geigercounter = 0
try:
    while True:
        try:
            line = s.readline().decode("ascii")
            if gcs.inWaiting():
                geigercounter += int(gcs.read(1).decode("ascii"))
            ausgeben(line)
            geigerausgeben(geigercounter)
        except UnicodeDecodeError:
            print("Error")
except KeyboardInterrupt:
    s.close()





