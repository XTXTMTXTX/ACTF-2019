def reL(input):
    i=((input>>1)&mask)
    lsb=input&1
    while i != 0:
        lsb^=(i&1)
        i=i>>1    
    output=(input>>1)|(lsb<<207)
    return output