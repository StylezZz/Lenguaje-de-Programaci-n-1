import tkinter as tk
from tkinter import filedialog
import csv

# Crear una ventana de diálogo para seleccionar el archivo de texto
root = tk.Tk()
root.withdraw()
file_path = filedialog.askopenfilename(filetypes=[('Archivo de texto', '*.txt')])

# Crear un archivo CSV con el mismo nombre que el archivo de texto
csv_file_path = file_path.replace('.txt', '.csv')

# Abrir archivo de texto y archivo CSV
with open(file_path, 'r') as file_txt, open(csv_file_path, 'w', newline='') as file_csv:
    
    # Crear objeto lector del archivo de texto y objeto escritor del archivo CSV
    txt_reader = csv.reader(file_txt, delimiter='\t')
    csv_writer = csv.writer(file_csv, delimiter=',')
    
    # Escribir el contenido del archivo de texto en el archivo CSV
    for row in txt_reader:
        csv_writer.writerow(row)
