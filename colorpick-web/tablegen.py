OUTPUTNAME='htmltablegen.txt'

fd=open(OUTPUTNAME,'w')

ROW=10
COL=1
DEFAULTVAL="000000"

fd.write("<table>\n")

for rownum in range(0,ROW):
    fd.write("<tr>\n")
    for colnum in range(0,COL):
        fd.write("<th>\n")

        line="<input type=\"text\" id="
        idstr=str(colnum+1)+str(rownum+1)
        line= line + '\"' + idstr + "\" class=\"jscolor\" value=\"" + DEFAULTVAL + "\">"
        fd.write(line)
        fd.write('\n')
        
        fd.write("</th>\n")


    fd.write("</tr>\n")


fd.write("</table>\n")

fd.close()

