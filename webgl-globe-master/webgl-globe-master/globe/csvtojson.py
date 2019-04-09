# -*- coding: utf-8 -*-
"""
Created on Sun Jun  3 15:50:15 2018

@author: sergi
"""

import csv


with open('airports.csv', newline='', encoding="utf-8") as csvfile:
    spamreader = csv.reader(csvfile)
    

#lines = csv.reader(open("airports.csv", "rb"))
    mpis = []  # Multidimensional Poverty Index
    thousands = []  # People, in thousands, in a poverty situation
    deprivations = []  # Intensity of Deprivation
    
    cont = 0
    
    for i in spamreader:
        if cont == 0:
            cont +=1
            continue
        if len(i[6]) == 0:
            i[6] = "0.0"
        
        if i[7] == 'OC':
            i[7] = "1"
        elif i[7] == 'AF':
            i[7] = "2"
        elif i[7] == 'AN':
            i[7] = "3"
        elif i[7] == 'EU':
            i[7] = "4"
        elif i[7] == 'AS':
            i[7] = "5"
        elif i[7] == 'SA':
            i[7] = "6"
        else:
            i[7] = "0"
        mpis += (i[4], i[5], i[6],i[7])
        cont += 1
        

print("""
[
["1990", [%s]]]
""" % (",".join(mpis)))