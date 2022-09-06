import numpy as np
import mypackage._cpp

def hello_cpp():
    """Print sample message.
    """
    return mypackage._cpp.hello_cpp()

def raw_ndarray(x:np.ndarray)->np.ndarray:
    """
    """
    return mypackage._cpp.raw_ndarray(x)
