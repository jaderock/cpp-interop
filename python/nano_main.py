import nano_ext
import numpy as np

# Create a dummy 100x100 RGB image with some data
image = np.full((100, 100, 3), 100, dtype=np.uint8)
print("Original image (first pixel):", image[0, 0, :])

nano_ext.process_image(image)