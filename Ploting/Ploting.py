from scipy.optimize import curve_fit as cfit
import numpy as np
import matplotlib
matplotlib.rcParams['text.usetex'] = True
import matplotlib.pyplot as PL


import model as md

#data from textfile
data = np.genfromtxt('data.txt',
                     skip_header=1,
                     usecols=(0, 1, 2, 3),
                     dtype=[('x', float),
                            ('xerr', float),
                            ('y', float),
                            ('yerr', float),],
                     comments='#')



# * * * fitting * * *
'''
* * * bounded fit * * *
boundaries are given by (array with lower, array with larger)
in this case all parameters ar positive, no array needed
Then, sigma is an array, and absolute sigma is a boolean
'''

data_fitted, covariance = cfit( md.I, data['x'], data['y'], sigma=data['yerr'], bounds=(0, 800))
#data_fitted, covariance = cfit( md.I, data['x'], data['y'], sigma=data['yerr'])
# sigma=errors, absolute_sigma=True,

perr = np.sqrt( np.diag(covariance) )

#printing fited data
print('fit parameter 1-sigma error')
print('———————————–')
for i in range(len(data_fitted)):
    print(str(data_fitted[i])+' +- '+str(perr[i]))



# * * * confidence levels * * *
dsig = 3. #data sigma
upper = data_fitted + dsig*perr
lower = data_fitted - dsig*perr



#* * * plotting * * * 
fig, ax = PL.subplots(1)

#Data plot with errors
PL.errorbar(data['x'], data['y'], xerr=data['xerr'], yerr=data['yerr'], fmt="+", color='black', label='errors')

#Linespaces for x axis use
xaxis = np.linspace(1, 10**(2.6), 100)

#Fit plot
#*data_fitted insert all parameters
PL.plot(xaxis, md.I(xaxis, *data_fitted), 'r-', label='fit')

#confidence plots
#ax.fill_between(xaxis, pf.S(xaxis, *upper), pf.S(xaxis, *lower), alpha=.25, label='5-sigma interval' )

ax.set_xlabel(r'V (V)')
ax.set_ylabel(r'I (mA)')

PL.xlim([0.45, 0.75])
PL.ylim([-1, 9])



PL.legend()
PL.show()
