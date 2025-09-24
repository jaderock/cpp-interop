import pb_extension
import numpy as np

pb_extension.add(1, 2)

# Create a NumPy array
my_array = np.array([1.0, 2.0, 3.0], dtype=np.double)
pb_extension.process_array(my_array)