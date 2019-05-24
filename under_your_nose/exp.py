from PIL import Image
img=Image.open('under_your_nose.jpg')
for i in range(95):
    for j in range(95):
        img.putpixel((i,j),img.getpixel((i*20,j*20)))
img.show()
