from tkinter import*
import calendar 
year=int(input("Enter year:-"))
text=calendar.calendar(year)

root=Tk()
root.geometry('550x600')
root.title("WELCOME BEAUTIFULL YEAR")
label1=Label(root,text="Welcome Beautifull year",bg="dark gray",font=("times",28,'bold'))
label1.grid(row=1,column=1)
root.config(background='white')
l1=Label(root,text=text,font="Consolas 10 bold")
l1.grid(row=2,column=1,padx=20)
root.mainloop()



