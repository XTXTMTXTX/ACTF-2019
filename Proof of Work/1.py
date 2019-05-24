
from hashlib import sha384
from string import ascii_letters,digits
from itertools import permutations
from time import time
all_letters=ascii_letters+digits+'.,;'
def decrypt_md5(md5_value):
    if len(md5_value)!=6:
        print('error')
        return
    md5_value=md5_value.lower()
    for k in range(1,10):
        for item in permutations(all_letters,k):
            item=''.join(item)
            sh=sha384(item.encode()).hexdigest()[-6:]
            print(item+' '+sh+'\n')
            if sh==md5_value:
                return item
md5_value  =input()
start=time()
result=decrypt_md5(md5_value)
if result:
    print('\n Success: '+md5_value+'==>'+result)
print('Time used:',time()-start)
