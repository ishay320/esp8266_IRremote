import glob

def header(file):
    file.write(
"""/* 
do not edit this file,
1. edit files in folder html_files 
2. run make_html.py
*/
#include <stdint.h>
\n""")

def html_files_in_folder(path):
    filenames = glob.glob(path+'/*.html')
    filenames += glob.glob(path+'/*.css')
    return filenames

def print_files_to_h(html_files,out_file):
    for file_name in html_files:
        file = open(file_name,"r")
        out_file.write("const char "+file_name.split("\\")[-1].split(".")[0]+"[] = R\"=====(")
        out_file.write(file.read())
        out_file.write(")=====\";\n\n")

if __name__ == "__main__":
    out_file_name = "html.h"
    html_files_folder_name = "html_files"

    out_file = open(out_file_name,"w")
    header(out_file)
    html_files = html_files_in_folder(html_files_folder_name)
    print_files_to_h(html_files,out_file)