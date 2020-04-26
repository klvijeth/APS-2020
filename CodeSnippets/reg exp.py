import re
print("Enter your email")
text = input()
y = re.findall('^([^@]*)',text)
z= re.findall('@(\S*)',text)
print(y)
print(z)
