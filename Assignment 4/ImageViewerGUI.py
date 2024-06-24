from my_package import ImageCaptioningModel
from my_package import ImageClassificationModel
from tkinter import *
from functools import partial
from PIL import ImageTk, Image
from tkinter import filedialog,ttk


def fileClick(clicked):
    # Define the function you want to call when the filebrowser button (Open) is clicked.
    # This function should pop-up a dialog for the user to select an input image file.
    # To have a better clarity, please check out the sample video.
    global openimage,filename,pilimg,model_img
    openimage=True
    filename = filedialog.askopenfilename(initialdir="./data/imgs/", title="Select an image", filetypes=(("jpeg files", "*.jpg"), ("all files", "*.*")))
    pilimg = Image.open(filename)
    model_img=ImageTk.PhotoImage(pilimg)
    imgwindow=Label(root,image=model_img,highlightbackground="white",highlightthickness=8,font=("Arial", 16,"bold"),bg="black" ,foreground="white")
    imgwindow.grid(row=2,column=0)
    entry = Entry(root, width=40)
    entry.config(highlightbackground="white",highlightthickness=3,font=("Arial", 16,"bold"),bg="black" ,foreground="white")
    entry.grid(row=0,column=0)
    entry.insert(0, "Image - "+filename[-5])

def process(clicked, captioner, classifier):
    # This function will produce the required output when 'Process' button is clicked.
    # Note: This should handle the case if the user clicks on the `Process` button without selecting any image file.
    global outputlabel
    if openimage!=True:
        print("select an image first!")
        return
    
    elif clicked.get()=="captioning":
        captions=captioner(filename)
        outputlabel.config(text="Top 3 captions:\n\n"+"\n".join(captions),highlightbackground="white",highlightthickness=2,font=("Arial", 16,"bold"),bg="black" ,foreground="white")
        outputlabel.grid(row=2,column=2)

        return
    elif clicked.get()=="classification":
        classifications=classifier(filename)
        
        classificationlist=[]
        for c in classifications:
            classificationlist.append(str(round((c[0]*100),2))+"% - "+str(c[1]))
            
        outputlabel.config(text="Top 3 classifications:\n\n"+"\n".join(classificationlist),highlightbackground="white",highlightthickness=2,font=("Arial", 16,"bold"),bg="black" ,foreground="white")
        outputlabel.grid(row=2,column=2)
        return
    


if __name__ == '__main__':
    # Complete the main function preferably in this order:
    # Instantiate the root window.
    root=Tk()
    root.geometry("600x50")
    root.configure(bg="black")
    openimage=False
    # Provide a title to the root window.
    root.title("Captioner and Classifier")
    style = ttk.Style(root)
    style.configure("TFrame", background="black")
    style.configure("TLabel",foreground="black", font=("Arial", 16,"bold"))
    
    # Instantiate the captioner, classifier models.
    captioner=ImageCaptioningModel()
    classifier=ImageClassificationModel()
    # Declare the file browsing button.
    clicked=StringVar(root)
    clicked.set("notclicked")
    filebrowserbutton=Button(root,text="Open",highlightbackground="white",highlightthickness=3,font=("Arial", 16,"bold"),bg="black" ,foreground="white",command=lambda:fileClick(clicked))
    filebrowserbutton.grid(row=0,column=1)
    # Declare the drop-down button.
    def on_select(value):
        if openimage!=True:
            print("select an Image first!")
            return
        clicked.set(value)
    # Define the dropdown options
    options = ["captioning","classification"]
    # Set the default option
    selected_option = StringVar(value=options[0])
    # Create the dropdown button and attach a command to it
    dropdown_button =OptionMenu(root,selected_option, *options, command=on_select)
    dropdown_button.config(highlightbackground="white",highlightthickness=3,font=("Arial",16,"bold"),bg="black",fg="white")
    # Add the dropdown button to the root window
    dropdown_button.grid(row=0,column=2)
    # Declare the process button.
    global outputlabel
    outputlabel=Label(root,text="")
    outputlabel.grid(row=0,column=4)
 
    process_button=Button(root,highlightbackground="white",highlightthickness=3,font=("Arial",16,"bold"),text="process",bg="black",fg="white",command=lambda:process(clicked,captioner,classifier))
    process_button.grid(row=0,column=3)
    # Declare the output label.
    root.mainloop()

