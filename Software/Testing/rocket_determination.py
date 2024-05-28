from random import randrange
import numpy as np
import pandas as pd

#  Prominent Arduino map function :)
def _map(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

visitors = [randrange(0,6000) for i in range(8)]

print(visitors)
for i in range(len(visitors)):
    year = 2015 + i
    steps = _map(visitors[i],0,6000,0,160000)
    distance = _map(visitors[i],0,6000,0,500)
    print(f"{year}: {steps} steps ({distance} mm)")