# -*- coding: utf-8 -*-
"""
Created on Sun Jun  3 23:45:52 2018

@author: sergi
"""
import pandas as pd

my_csv = pd.read_csv("airports.csv")
column = my_csv.continent
print(column.unique())