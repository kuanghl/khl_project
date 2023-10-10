import pytest
import numpy as np

a=pytest.add(108, 66)
print(a)

b=5
ret = np.array(100, dtype=np.int32);
print(ret)
c=pytest.add_pointer(a,b,ret)
print(c)
print(ret)