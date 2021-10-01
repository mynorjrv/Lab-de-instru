from scipy.optimize import curve_fit as cfit
import numpy as np
import matplotlib
matplotlib.rcParams['text.usetex'] = True
import matplotlib.pyplot as PL


#data from textfile

dataZe = np.genfromtxt('Zener',
                     skip_header=1,
                     usecols=(0, 1, 2, 3),
                     dtype=[('x', float),
                            ('xerr', float),
                            ('y', float),
                            ('yerr', float),],
                     comments='#')



#* * * plotting * * * 
fig, ax = PL.subplots(1)

#Data plot with errors

PL.errorbar(dataZe['x'], dataZe['y'], xerr=dataZe['xerr'], yerr=dataZe['yerr'], fmt="-", color='black', label='Curva experimental del Zener', capsize=1.0)

PL.axvline(x=-3.3, color='red', linestyle='--', label='Voltaje de Zener teórico')


PL.title('Curva del diodo Zener')

ax.set_xlabel(r'V (V)')
ax.set_ylabel(r'I (mA)')

ax.grid(b=True, linestyle='--')

PL.legend()
PL.show()
