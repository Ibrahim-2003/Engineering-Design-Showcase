from random import randrange
import numpy as np
import pandas as pd

#  Prominent Arduino map function :)
def _map(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

visitors = [randrange(1000,6000) for i in range(12)]
colors = [_map(i,0,6000,0,3) for i in visitors]

print(visitors)
for i in range(len(colors)):
    if colors[i] == 0:
        print(f'Hour {i}: Green')
    elif colors[i] == 1:
        print(f'Hour {i}: Yellow')
    else:
        print(f'Hour {i}: Red')