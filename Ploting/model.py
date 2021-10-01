import numpy as np

qe = 1.602176565e-19
kb = 1.3806504e-23
Is = 10e-12

n = 1

def VT(T):
    return( kb*T/qe)

def I(Vd, T):
    Id = Is*(10e3)*( np.exp( Vd/( n*VT(T) ) ) - 1 )
    return Id

def Iotro(Vd, v_t, i_s):
    Id = i_s*( np.exp( Vd/(n*v_t) ) + 1 )
    return Id
