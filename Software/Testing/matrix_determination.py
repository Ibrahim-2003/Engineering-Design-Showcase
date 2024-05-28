from random import randrange
import numpy as np
import pandas as pd

#  Prominent Arduino map function :)
def _map(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

visitors = [randrange(0,2) for i in range(5000)]

print(sum(visitors))
print(len(visitors) - sum(visitors))
perc = 1 - (sum(visitors)/len(visitors))
perc = perc*100
print(f"Percent Female: {perc:.0f}%")