
from hashlib import sha256
from string import ascii_letters,digits
from itertools import permutations
from time import time
all_letters=ascii_letters+digits+'.,;'
def run():
    for k in range(1,10):
        for item in permutations(all_letters,k):
            item=''.join(item)
            sh=sha256(item.encode()).hexdigest()[-6:]
            print(item+' '+sh+'\n')

run()